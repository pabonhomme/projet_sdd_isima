#include "semaine.h"

/* --------------------------------------------------------------------
initSem : Initialise une liste
 
En entrée: void

En sortie: 

 -------------------------------------------------------------------- */
ListeSem initSem(void){
    return NULL;
}

/* --------------------------------------------------------------------
videListe : Vérifie si une liste est vide
 
En entrée: la liste

En sortie: un Boolen, vrai si la liste est vide, faux sinon

 -------------------------------------------------------------------- */
Boolen videListe(ListeSem liste){
    if(liste==NULL)
        return vrai;

    return faux;
}

/* --------------------------------------------------------------------
tete : Renvoie le premier maillon de la liste
 
En entrée: la liste des semaines

En sortie: la première semaine de la liste, NULL sinon

 -------------------------------------------------------------------- */
Semaine tete(ListeSem liste){
    if(videListe(liste)){
        printf("Opération interdite\n");
            exit(1);
    }
    else{
        return (liste->semaine);
    }
}

/* --------------------------------------------------------------------
insererEnTete : Insère une nouvelle semaine en tête de la liste
 
En entrée: liste : la liste des semaines; s : la semaine à inserer

En sortie: La liste avec l'élement en tête

 -------------------------------------------------------------------- */
ListeSem insererEnTete(ListeSem liste, Semaine s){
    MaillonSem *sem;
    sem=(MaillonSem*)malloc(sizeof(MaillonSem)); // allocation d'un maillon
    if (sem==NULL){
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
ListeSem inserer(ListeSem liste, Semaine sem){
    Semaine s_aux;
    if(videListe(liste)){
        return insererEnTete(liste, sem); // si la liste est vide, on insère en tête
    }
    s_aux = tete(liste); // si la liste n'est pas vide on récupère la tête
    if(strcmp(s_aux.annee, sem.annee) > 0 && strcmp(s_aux.sem, sem.sem) > 0){
        return insererEnTete(liste, sem); // si annee tete de liste superieure à l'année de la semaine à inserer, on insère en tête
    }
    liste->suiv = inserer(liste->suiv, sem);
    return liste;
}

/* --------------------------------------------------------------------
lireSemaine : lis une ligne du fichier
 
En entrée: flot : pointeur sur le fichier à lire

En sortie: semaine lue

 -------------------------------------------------------------------- */
Semaine lireSemaine (FILE *flot)
{   Semaine s;
    
    return s;
}

/* --------------------------------------------------------------------
chargeSemaine : charge les semaines à partir d'un fichier
 
En entrée: nomFichier : Nom du fichier à lire ; liste : la liste des semaines

En sortie: La liste avec les semaines insérées

 -------------------------------------------------------------------- */
ListeSem chargeSemaine(char* nomFichier, ListeSem liste)
{   int i;
    Semaine s;
    FILE*flot;
    flot=fopen(nomFichier,"r");

    if (flot == NULL)
        {
            printf("Problème d'ouverture du fichier\n");
        }
    if (feof(flot))
        {
            printf("fichier vide\n");
            return liste;
        }
    s=lireSemaine(flot);

    while(!feof(flot))
        {
             liste=inserer(liste, s);
             s=lireSemaine(flot);
           
        }
    fclose(flot);
    return liste;
}