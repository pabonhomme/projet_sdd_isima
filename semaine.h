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
}Boolen;

typedef struct{
    char annee[5];
    char sem[3];
    struct action *action;
}Semaine;

typedef struct maillonSem{
    Semaine semaine;
    struct maillonSem *suiv;
}MaillonSem, *ListeSem;

// FONCTIONS LISTE SEMAINE
ListeSem initSem(void);
Boolen videListe(ListeSem liste);
Semaine tete(ListeSem liste);
ListeSem insererEnTete(ListeSem liste, Semaine s);
ListeSem inserer(ListeSem liste, Semaine sem);
Semaine lireSemaine (FILE *flot);
ListeSem chargeSemaine (char* nomFichier, ListeSem liste);