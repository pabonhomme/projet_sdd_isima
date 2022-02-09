#ifndef projet
#define projet

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "action.h"
#endif

typedef enum
{
	faux,vrai
}Boolen_t;

typedef struct{
    char annee[5];
    char sem[3];
    struct action *action;
}Semaine_t;

typedef struct maillonSem_t{
    Semaine_t semaine;
    struct maillonSem_t *suiv;
}MaillonSem_t, *ListeSem_t;

// FONCTIONS LISTE SEMAINE
ListeSem_t initSem(void);
Boolen_t videListe(ListeSem_t liste);
Semaine_t tete(ListeSem_t liste);
ListeSem_t insererEnTete(ListeSem_t liste, Semaine_t s);
ListeSem_t inserer(ListeSem_t liste, Semaine_t sem);
Semaine_t lireSemaine (FILE *flot);
ListeSem_t chargeSemaine (char* nomFichier, ListeSem_t liste);