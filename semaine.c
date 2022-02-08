#include "projet.h"

/* --------------------------------------------------------------------
initSem : Initialise une liste
 
En entrée: void

EN sortie 

 -------------------------------------------------------------------- */
ListeSem initSem(void){
    return NULL;
}

Boolen videListe(ListeSem liste){
    if(liste==NULL)
        return vrai;

    return faux;
}

Semaine tete(ListeSem liste){

    return videListe(liste) ? (liste->semaine) : NULL // si liste non-vide, on retourne la tête de liste
}

void insererEnTete(ListeSem liste){
    MaillonSem *sem;
    sem=(Sem*)malloc(sizeof(Sem)); // allocation d'un maillon
    if (sem==NULL){
        printf("Probleme malloc\n");
        exit(1);
    }
    sem->suiv=liste;
    return sem;
}

void inserer(ListeSem liste, Semaine sem){
    Semaine s_aux;
    if(videListe(liste)){
        return insererEnTete(liste, sem) // si la liste est vide, on insère en tête
    }
    s_aux = tete(liste); // si la liste n'est pas vide on récupère la tête
    if(strcmp(s_aux.annee, sem.annee) > 0){
        return insererEnTete(liste, sem) // si annee tete de liste superieure à l'année de la semaine à inserer, on insère en tête
    }
    liste->suiv = inserer(liste->suiv, sem);
    return liste;
}
