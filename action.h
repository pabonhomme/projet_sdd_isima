#ifndef projet
#define projet

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

typedef struct{
    char jheure[4];
    char action[10];
}Action_t;

typedef struct maillonAction_t{
    Action_t action;
    struct maillonAction_t *suiv;
}MaillonAction_t, *ListeAction_t;