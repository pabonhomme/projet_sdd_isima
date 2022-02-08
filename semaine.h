#ifndef projet
#define projet

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct action{
    char jheure[3];
    char action[10];
}Action;

typedef struct maillonAction{
    Action action;
    struct action *suiv;
}MaillonAction, *ListeAction;

typedef struct semaine{
    char annee[4];
    char sem[2];
    struct action *action;
}Semaine;

typedef struct maillonSem{
    Semaine semaine;
    struct sem *suiv;
}MaillonSem, *ListeSem;








#endif
