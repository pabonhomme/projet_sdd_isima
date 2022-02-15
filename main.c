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

#include "semaine.h"

void affichMenu(void) 
{   
    printf("\n\n             *******************************************************\n");
        printf("             *                                                      *\n");
        printf("             *                 Gestion semaines                     *\n");
        printf("             *                                                      *\n");
        printf("             *******************************************************\n");
        printf("\n                 1- Afficher les listes                                                                            \n ");
        printf("\n                 2- Sauvegarder la liste                                                         \n ");
        printf("\n                 3- Suppression d'une action                                                     \n");
        printf("\n                 0- quitter                                                                       \n");
        printf("\n              *****************************************************\n");
}

void menu(char* nomFichier){
    int        choix;
    ListeSem_t liste = initSem();

    liste = chargeSemaine(nomFichier, liste);

    affichMenu();
    printf("Tapez votre choix :\n");
    while(scanf("%d",&choix)==0)
        {   
            affichMenu();
            printf("Caractere non pris en charge\n");

            printf("Tapez votre choix :\n");
            scanf("%d",&choix);
            getchar();

        }

    while(choix>0 && choix<4)
    {
        switch(choix)
        {
            case 0:
                exit(1);
            break;
            case 1:
                
                afficherListeSem(liste);
            break;
            case 2:
                sauvegarder("sauvegarde.txt", liste);
            break;
            case 3:
                
            break;
        }
    affichMenu();
    printf("Tapez votre choix :\n");
    while(scanf("%d",&choix)==0)
        {   
            affichMenu();
            printf("Caractere non pris en charge\n");

            printf("Tapez votre choix :\n");
            scanf("%d",&choix);
            getchar();

        }
    }
}

int main(int argc, char *argv[])
{
    if(argc==2)
    {
        menu(argv[1]);
    }
    else
    {
        printf("Vous n'avez pas fourni le nom du fichier à lire\n");
    }
	return 0;
}