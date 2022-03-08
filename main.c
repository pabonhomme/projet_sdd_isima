/**
 * @file main.c
 * @author Paul BONHOMME & Rime LAMRANI (paul.bonhomme@etu.uca.fr & rime.lamrani@etu.uca.fr)
 * @brief fichier .c : fonction main qui affiche et gère le menu
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "jour.h"

/* --------------------------------------------------------------------
affichMenu : Affiche le menu
 
En entrée: void;

En sortie: void

 -------------------------------------------------------------------- */
void affichMenu(void) 
{   
    printf("\n                                    GESTION DE L'ECHEANCIER                     ");
    printf("\n\n\t╔═══════════════════════════════════════════════════════════════════════════╗\n");
    printf("\t║                                                                           ║\n");
    printf("\t║\t1- Afficher les semaines et les actions                             ║\n");
    printf("\t║                                                                           ║\n");
    printf("\t║\t2- Sauvegarder la liste dans le fichier \"sauvegarde.txt\"            ║\n");
    printf("\t║                                                                           ║\n");
    printf("\t║\t3- Afficher les jours à partir d'un motif (Donnez un motif)         ║\n");
    printf("\t║                                                                           ║\n");
    printf("\t║\t4- Suppression d'une action                                         ║\n");
    printf("\t║                                                                           ║\n");
    printf("\t║\t5- Lancer la série de tests                                         ║\n");
    printf("\t║                                                                           ║\n");
    printf("\t║\t6- Quitter                                                          ║\n");
    printf("\t║                                                                           ║\n");
    printf("\t╚═══════════════════════════════════════════════════════════════════════════╝\n\n");
}

/* --------------------------------------------------------------------
menu : fonction de menu qui contient un switch sur les différentes options du menu
 
En entrée: nomFichier :  le nom du fichier donné en ligne de commande par l'utilisateur;

En sortie: void

 -------------------------------------------------------------------- */
void menu(char* nomFichier){
    int        choix, nbJour, jourASupp; // choix de l'utilisateur, nombre de jour trouvé pour un motif donné et jour à supprimer
    char       motif[11], anneeASupp[11], numSemASupp[3], heureASupp[3]; // motif donné par l'utilisateur, Annee a supprimer, numero de semaine a supprimer, heure a supprimer
    ListeSem_t liste = initSem(); // initialisation de la liste
    Jour_t     jourTab[MAX_JOUR], * finJourTab; // initialisation tableau de jours statique et pointeur de fin

    liste = chargeSemaine(nomFichier, liste); // chargement des semaines à partir du nom de fichier
    finJourTab = &jourTab[MAX_JOUR]; // affectation du pointeur de fin du tableau de jour

    affichMenu(); // affichage du menu
    printf("Tapez votre choix :\n");
    while(scanf("%d%*c",&choix)==0) // tant que l'utlisateur n'a pas rentré un nombre
        {   
            affichMenu();
            printf("Caractere non pris en charge\n");

            printf("Tapez votre choix :\n");
            scanf("%d",&choix);
            getchar();
        }

    while(choix>0 && choix<7)
    {
        switch(choix)
        {
            case 1:
                
                afficherListeSem(liste); // affichage de la liste
                break;
            case 2:
                sauvegarder("sauvegarde.txt", liste); // sauvegarde de la liste
                break;
            case 3:
                printf("Donnez un motif :");
                lireChaine(motif, 11); // lecture du motif rentré par l'utilisateur
                nbJour = tableauParMotif(motif, liste, jourTab, finJourTab); // recherche des actions avec le motif
                afficherTableauParMotif(jourTab, motif, nbJour); // affichage du tableau de jours
                break;
            case 4:
                printf("Donnez l'annee de l'action à supprimer :\n");
                lireChaine(anneeASupp, 11); // lecture de l'année de la semaine à supprimer rentrée par l'utilisateur

                printf("Donnez le numéro de semaine de l'action à supprimer :\n");
                lireChaine(numSemASupp, 3); // lecture du numéro de la semaine à supprimer rentré par l'utilisateur

                printf("Donnez le jour de l'action à supprimer :\n");
                while(scanf("%d", &jourASupp)==0)
                {
                    printf("Les informations rentrées ne sont pas dans le bon format\n");
                    printf("Donnez le jour de l'action à supprimer :\n");
                    scanf("%d", &jourASupp);
                    getchar();
                }

                printf("Donnez l'heure de l'action à supprimer :\n");
                lireChaine(heureASupp, 11); // lecture de l'heure à supprimer rentrée par l'utilisateur

                if(supprimerAction(liste, anneeASupp, numSemASupp, jourASupp, heureASupp)) // si la semaine contenant l'action à supprimer ne contient plus d'action 
                {
                    liste = supprimerMaillonSemaine(liste, anneeASupp, numSemASupp); // on supprime cette semaine vide de la liste
                }
                break;
            case 5:
                mainTest(liste); // fonction de tests
                break;
            case 6:
                libererSemaines(liste); // libère la mémoire utilisée avant de quitter le programme
                exit(0);
                break;
        }

        affichMenu(); // affichage du menu
        printf("Tapez votre choix :\n");
        while(scanf("%d%*c",&choix)==0) // tant que l'utilisateur n'a pas rentré un nombre
            {   
                affichMenu();
                printf("Caractere non pris en charge\n");

                printf("Tapez votre choix :\n");
                scanf("%d",&choix);
                getchar();
            }
    }
}

/* --------------------------------------------------------------------
viderBuffer : fonction qui permet de vider le buffer après avoir récuperer le nombre de caractères voulus
 
En entrée: void

En sortie: void

 -------------------------------------------------------------------- */
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF) // tant que l'on a pas atteint la fin du buffer
    {
        c = getchar();
    }
}

/* --------------------------------------------------------------------
lireChaine : Permet de récuperer une chaine de caractère en fonction d'une taille donnée

Cela permet d'éviter les cas où l'utilisateur rentre plus de caractères que la chaine peut en contenir (erreur avec un scanf)
 
En entrée: chaine : la chaine de caractère à remplir
           longueur : taille de la chaine de caractère

En sortie: void

 -------------------------------------------------------------------- */
void lireChaine(char *chaine, int longueur)
{
    char *positionEntree = NULL;
 
    if (fgets(chaine, longueur, stdin) != NULL) // si on lit des données
    {
        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entrée"
        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace ce caractère par \0
        }
        else
        {
            viderBuffer(); // on vide le buffer
        }
    }
    else
    {
        viderBuffer(); // on vide le buffer
    }
}

int main(int argc, char *argv[])
{
    if(argc==2) // si l'utilisateur a bien fourni un argument lors de l'éxécution
    {
        menu(argv[1]);
    }
    else
    {
        printf("Vous n'avez pas fourni le nom du fichier à lire\n");
    }
	return 0;
}