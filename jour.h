#ifndef projet
#define projet

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "action.h"
#include "semaine.h"
#endif

#define MAX_JOUR 15

typedef struct 
{
	char annee[5];
    char numSem[3];
    int  jour;
    char heure[3];
    char nomAction[11];
}Jour_t;

int tableauParMotif(char* motif, ListeSem_t listeSemaines, Jour_t jourTab[], Jour_t *finJourTab);
void afficherTableauParMotif(Jour_t jourTab[], char* motif, int nbJour);
