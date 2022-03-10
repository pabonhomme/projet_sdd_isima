/**
 * @file semaine.c
 * @author Paul BONHOMME & Rime LAMRANI (paul.bonhomme@etu.uca.fr & rime.lamrani@etu.uca.fr)
 * @brief fichier .c : fonctions de base pour les semaines, chargement des listes à partir d'un fichier
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "semaine.h"

/* --------------------------------------------------------------------
initSem : Initialise une liste
 
En entrée: void

En sortie: la liste initialisée à NULL

 -------------------------------------------------------------------- */
ListeSem_t initSem(void)
{
    return NULL;
}

/* --------------------------------------------------------------------
videListeSem : Vérifie si une liste est vide
 
En entrée: 
    ListeSem_t liste: la liste qu'on teste

En sortie: un Boolen, vrai si la liste est vide, faux sinon

 -------------------------------------------------------------------- */
Boolen_t videListeSem(ListeSem_t liste)
{
    Boolen_t resultat = faux;

    if(liste==NULL)
        resultat = vrai;

    return resultat;
}

/* --------------------------------------------------------------------
tete : Renvoie le premier maillon de la liste
 
En entrée: 
    ListeSem_t liste: la liste des semaines

En sortie: la première semaine de la liste, NULL sinon

 -------------------------------------------------------------------- */
Semaine_t tete(ListeSem_t liste)
{

    if(videListeSem(liste))
    {
        printf("Opération interdite\n");
        exit(1);
    }
    else
    {
        return (liste->semaine);
    }
}

/* --------------------------------------------------------------------
insererEnTete : Insère une nouvelle semaine en tête de la liste
 
En entrée: liste : 
    ListeSem_t liste :la liste des semaines
    Semaine_t  s : la semaine à inserer

En sortie: La liste avec l'élement en tête

 -------------------------------------------------------------------- */
ListeSem_t insererEnTete(ListeSem_t liste, Semaine_t s)
{
    MaillonSem_t *sem;

    sem=(MaillonSem_t*)malloc(sizeof(MaillonSem_t)); // allocation d'un maillon
    if (sem==NULL)
    {
        printf("Probleme malloc\n");
        exit(1);
    }
    sem->semaine = s; // mise à jour de la semaine dans le maillon
    sem->suiv=liste; // insertion en tête de la liste en faisant pointer le maillon sur la liste

    return sem;
}

/* --------------------------------------------------------------------
inserer : insère une semaine dans l'ordre des dates
 
En entrée: 
    ListeSem_t liste : la liste des semaines
    Semaine_t  s : la semaine à inserer

En sortie: La liste avec l'élement inséré

 -------------------------------------------------------------------- */
ListeSem_t inserer(ListeSem_t liste, Semaine_t sem)
{
    Semaine_t s_aux;

    if(videListeSem(liste))
    {
        return insererEnTete(liste, sem); // si la liste est vide, on insère en tête
    }

    s_aux = tete(liste); // si la liste n'est pas vide on récupère la tête

    if(strcmp(s_aux.annee, sem.annee) > 0)
    {
        return insererEnTete(liste, sem); // si annee tete de liste superieure à l'année de la semaine à inserer, on insère en tête
    }
    if(strcmp(s_aux.annee, sem.annee) == 0 && strcmp(s_aux.numSem, sem.numSem) > 0)
    {
        return insererEnTete(liste, sem); // si annee tete de liste égale à l'année de la semaine à insérer et semaine de la tete supériere, on insère en tête
    }
    if(strcmp(s_aux.annee, sem.annee) == 0 && strcmp(s_aux.numSem, sem.numSem) == 0)
    {

        (liste->semaine).actions = insererAction((liste->semaine).actions, (sem.actions)->action); // on insère l'action dans la liste d'action de la semaine en question
        return liste;
    }

    liste->suiv = inserer(liste->suiv, sem);
    return liste;
}

/* --------------------------------------------------------------------
afficherSemaine : Affiche une semaine
 
En entrée: 
    Semaine_t sem : la semaine qu'on veut afficher 

En sortie: void

 -------------------------------------------------------------------- */
void afficherSemaine(Semaine_t sem)
{
    printf("\nAnnee : %s\t Semaine Numero : %s\n",sem.annee, sem.numSem);
}

/* --------------------------------------------------------------------
afficherListeSem : Affiche la liste des semaines
 
En entrée: 
    ListeSem_t liste : la liste des semaines

En sortie: void

 -------------------------------------------------------------------- */
void afficherListeSem(ListeSem_t liste)
{
    printf("\n┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈Liste des Semaines┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
    while(!videListeSem(liste))
    {
        afficherSemaine(liste->semaine);
        if(!videListeAction((liste->semaine).actions)) // on vérifie si la semaine contient des actions 
            afficherListeActions((liste->semaine).actions); // si la semaine contient des actions, on les affcihe aussi
        printf("\n┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
        liste=liste->suiv; // on passe à la semaine suivante
    }
}

/* --------------------------------------------------------------------
lireSemaine : lis une ligne du fichier
 
En entrée: 
    FILE * flot : pointeur sur le fichier à lire

En sortie: semaine lue

 -------------------------------------------------------------------- */
Semaine_t lireSemaine (FILE *flot)
{   Semaine_t sem;
    Action_t  act;
    char      jour;

    fscanf(flot,"%4s %2s %c %2s %[^\n]%*c", sem.annee, sem.numSem, &jour, act.heure, act.nom); // lecture d'une ligne 
    act.jour = jour - '0'; // transformation d'un entier en caractère
    sem.actions = insererAction(initAction(), act); // on crée un premier maillon pour la liste d'actions de la semaine
    
    return sem;
}

/* --------------------------------------------------------------------
chargeSemaine : charge les semaines à partir d'un fichier
 
En entrée: 
    char       * nomFichier : Nom du fichier à lire 
    ListeSem_t listeSemaines : la liste des semaines

En sortie: La liste avec les semaines insérées

 -------------------------------------------------------------------- */
ListeSem_t chargeSemaine(char* nomFichier, ListeSem_t listeSemaines)
{   
    Semaine_t s;
    FILE    * flot;

    flot=fopen(nomFichier,"r"); // ouverture du fichier en lecture

    if (flot == NULL) // si l'ouverture s'est mal passee
    {
        printf("Problème d'ouverture du fichier\n");
    }
    if (feof(flot)) // si le fichier est vide
    {
        printf("fichier vide\n");
        return listeSemaines;
    }
    
    s=lireSemaine(flot); // lecture d'une semaine
    while(!feof(flot))
    {
        listeSemaines=inserer(listeSemaines, s); // insertion de la semaine dans la liste
        s=lireSemaine(flot); // lecture d'une semaine
    }

    fclose(flot);
    return listeSemaines;
}

/* --------------------------------------------------------------------
sauvegarder : sauvegarde les semaines et les actions dans un fichier
 
En entrée: 
    char  * nomFichier : Nom du fichier dans lequel on veut ecrire 
    Liste listeSemaines : la liste des semaines

En sortie: void

 -------------------------------------------------------------------- */
void sauvegarder(char* nomFichier, ListeSem_t listeSemaines)
{
    FILE * flot;

    flot=fopen(nomFichier,"w"); // ouverture du fichier en ecriture

    if (flot == NULL) // si l'ouverture s'est mal passee
    {
        printf("Problème d'ouverture du fichier\n");
    }

    while(!videListeSem(listeSemaines)) // parcours de la liste des semaines
    {
        sauvegarderAction(flot, (listeSemaines->semaine).actions, (listeSemaines->semaine).annee,(listeSemaines->semaine).numSem);
        listeSemaines = listeSemaines->suiv;
    }

    fclose(flot);
}

/* --------------------------------------------------------------------
rechSemaineAction : recherche une semaine, puis une action si la semaine est trouvée
 
En entrée: 
    ListeSem_t liste : la liste des semaines
    char     * annee : l'année à trouver
    char     * sem : la semaine à trouver
    int        jour : le jour à trouver
    char     * heure : l'heure de l'action à trouver

En sortie: un Boolen, vrai si l'action existe, faux sinon

 -------------------------------------------------------------------- */
Boolen_t rechSemaineAction(ListeSem_t liste, char annee[], char sem[], int jour, char heure[])
{
    Boolen_t resultat = faux;

    while(liste!=NULL)
    {
        if(strcmp((liste->semaine).annee, annee) == 0 && strcmp((liste->semaine).numSem, sem) == 0) // si on trouve la semaine voulue
        {
            resultat = rechAction((liste->semaine).actions, jour, heure);
        }
        liste=liste->suiv;
    }
    return resultat;
}

/* --------------------------------------------------------------------
supprimerAction : Supprime l'action en fonction de l'annee et du jour et de l'heure
 
En entrée: 
    ListeSem_t liste : la liste des actions 
    char       * annee : annee de la semaine qui contient l'action a supprimer
    char       * numSem : numero de la semaine qui contient l'action a supprimer
    int        jour : numero du jour de l'action a supprimer 
    char       * heure : heure de l'action a supprimer 

En sortie: void

 -------------------------------------------------------------------- */
Boolen_t supprimerAction(ListeSem_t liste, char* annee, char* numSem, int jour, char* heure)
{   
    Boolen_t listeActionVide = faux; // permet de savoir si l'action a été supprimée quand on parcours la liste

    if(rechSemaineAction(liste, annee, numSem, jour, heure)) // si l'action existe dans la liste
    {
        while(liste!=NULL)
        {
            if(strcmp((liste->semaine).annee, annee) == 0 && strcmp((liste->semaine).numSem, numSem) == 0) // si on trouve la semaine voulue
            {
                (liste->semaine).actions = supprimerMaillonAction((liste->semaine).actions, jour, heure); // suppression de l'action dans la liste d'actions
                listeActionVide = videListeAction((liste->semaine).actions); // si la liste des actions est vide après suppression on notifie que l'on doit supprimer la semaine de la liste
            }
            liste = liste->suiv;
        }
        printf("\nLa suppression a ete effectuee\n");
    }
    else{
        printf("\nL'action à supprimer n'existe pas\n");
    }

    return listeActionVide;
}

/* --------------------------------------------------------------------
supprimerEnTeteSemaine : Supprime la semaine en tête de la liste
 
En entrée: 
    ListeSem_t liste : la liste des semaines

En sortie: La liste avec l'element supprimé

 -------------------------------------------------------------------- */
ListeSem_t supprimerEnTeteSemaine(ListeSem_t liste)
{
    MaillonSem_t *maillonSemTemp; // Maillon temporaire qui va permettre de supprimer la tête de liste 
    if(videListeSem(liste)) // si la liste est vide on ne peut rien supprimer, c'est un cas d'erreur
    {
        printf("Suppression d'une semaine sur une liste vide, operation interdite");
        exit(1);
    }
    maillonSemTemp = liste; // recuperation de la semaine en tête de liste
    liste = liste->suiv; // on avance la liste sur le maillon suivant
    free(maillonSemTemp); // on libere le maillon en tete
    return liste;
}

/* --------------------------------------------------------------------
supprimerMaillonSemaine : Supprime la semaine en fonction de l'année et du numéro de semaine
 
En entrée: 
    ListeSem_t liste : la liste des actions ; 
    char       * annee : annee de la semaine ; 
    char       * numSem : numero de la semaine ;

En sortie: La liste avec l'element supprimé ou non

 -------------------------------------------------------------------- */
ListeSem_t supprimerMaillonSemaine(ListeSem_t liste, char* annee, char* numSem)
{   
    Semaine_t semaineTemp;

    if(videListeSem(liste)) // si la liste est vide, on retourne la liste
        return liste;

    semaineTemp = tete(liste);
    if(semaineTemp.annee > annee) // si l'annee en tete est > a l'annee voulue -> semaine pas dans la liste
        return liste;
    if(strcmp(semaineTemp.annee, annee) && strcmp(semaineTemp.numSem, numSem) > 0) // si le jour en tete est = au jour voulu et l'heure > -> action pas dans la liste
        return liste;
    if(strcmp(semaineTemp.annee, annee) == 0 && strcmp(semaineTemp.numSem, numSem) == 0) // si la tete vaut la semaine voulue
        return supprimerEnTeteSemaine(liste); // on la supprime

    liste->suiv=supprimerMaillonSemaine(liste->suiv, annee, numSem); // appel recursif
    return liste;
}

/* --------------------------------------------------------------------
libererSemaines : libère toute la liste des semaines en supprimant chaque maillon
 
En entrée: 
    ListeSem_t liste : la liste des semaines;

En sortie: void

 -------------------------------------------------------------------- */
void libererSemaines(ListeSem_t liste)
{

    while(!videListeSem(liste))// tant que la liste n'est pas vide
    {
        libererActions((liste->semaine).actions);
        liste = supprimerEnTeteSemaine(liste);// on supprime la semaine en tete
    }
}