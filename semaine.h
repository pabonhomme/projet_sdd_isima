#ifndef projet
#define projet

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

typedef enum
{
	faux,vrai
}Boolen;

typedef struct semaine{
    char annee[5];
    char sem[3];
    struct action *action;
}Semaine;

typedef struct maillonSem{
    Semaine semaine;
    struct sem *suiv;
}MaillonSem, *ListeSem;
