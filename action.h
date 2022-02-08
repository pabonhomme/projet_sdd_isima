#ifndef projet
#define projet

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

typedef struct action{
    char jheure[4];
    char action[10];
}Action;

typedef struct maillonAction{
    Action action;
    struct action *suiv;
}MaillonAction, *ListeAction;