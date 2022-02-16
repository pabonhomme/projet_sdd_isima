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

En sortie: 

 -------------------------------------------------------------------- */
ListeSem_t initSem(void)
{
    return NULL;
}

/* --------------------------------------------------------------------
videListeSem : Vérifie si une liste est vide
 
En entrée: la liste

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
 
En entrée: la liste des semaines

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
 
En entrée: liste : la liste des semaines; s : la semaine à inserer

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
    sem->semaine = s;
    sem->suiv=liste;

    return sem;
}

/* --------------------------------------------------------------------
inserer : insère une semaine
 
En entrée: liste : la liste des semaines; s : la semaine à inserer

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
 
En entrée: sem : une semaine;

En sortie: void

 -------------------------------------------------------------------- */
void afficherSemaine(Semaine_t sem)
{
    printf("\nAnnee : %s\t Semaine Numero : %s\n",sem.annee, sem.numSem);
}

/* --------------------------------------------------------------------
afficherListeSem : Affiche la liste des semaines
 
En entrée: liste : la liste des semaines;

En sortie: void

 -------------------------------------------------------------------- */
void afficherListeSem(ListeSem_t liste)
{
    printf("\n┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈Liste des Semaines┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
    while(!videListeSem(liste))
    {
        afficherSemaine(liste->semaine);
        afficherListeActions((liste->semaine).actions);
        printf("\n┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
        liste=liste->suiv;
    }
}

/* --------------------------------------------------------------------
rechSemaine : recherche une semaine
 
En entrée: liste : la liste des semaines; annee et sem : l'année et la semaine à trouver

En sortie: un Boolen, vrai si l'action existe, faux sinon

 -------------------------------------------------------------------- */
Boolen_t rechSemaine(ListeSem_t liste, char annee[], char sem[])
{
    Boolen_t resultat = faux;

    while(liste!=NULL)
    {
        if(strcmp((liste->semaine).annee, annee) == 0 && strcmp((liste->semaine).numSem, sem) == 0) // si on trouve la semaine voulue
        {
            resultat = vrai;
        }
        liste=liste->suiv;
    }
    return resultat;
}

/* --------------------------------------------------------------------
lireSemaine : lis une ligne du fichier
 
En entrée: flot : pointeur sur le fichier à lire

En sortie: semaine lue

 -------------------------------------------------------------------- */
Semaine_t lireSemaine (FILE *flot)
{   Semaine_t sem;
    Action_t  act;
    char      jour;

    fscanf(flot,"%4s %2s %c %2s %[^\n]%*c", sem.annee, sem.numSem, &jour, act.heure, act.nom); // lecture d'une ligne 
    act.jour = jour - '0';
    sem.actions = insererAction(initAction(), act); // on crée un premier maillon pour la liste d'actions de la semaine
    
    return sem;
}

/* --------------------------------------------------------------------
chargeSemaine : charge les semaines à partir d'un fichier
 
En entrée: nomFichier : Nom du fichier à lire ; liste : la liste des semaines

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
 
En entrée: nomFichier : Nom du fichier dans lequel ecrire ; listeSemaines : la liste des semaines

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