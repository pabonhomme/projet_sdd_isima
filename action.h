/**
 * @file action.h
 * @author Paul BONHOMME & Rime LAMRANI (paul.bonhomme@etu.uca.fr & rime.lamrani@etu.uca.fr)
 * @brief fichier .h : déclaration des types, constantes et prototypes pour les actions
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef projet
#define projet

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

typedef enum
{
	faux,vrai
}Boolen_t;

typedef struct
{
	int  jour;
    char heure[3];
    char nom[11];
}Action_t;

typedef struct maillonAction_t
{
    Action_t                 action;
    struct maillonAction_t * suiv;
}MaillonAction_t, *ListeAction_t;

// FONCTIONS LISTE ACTIONS
ListeAction_t initAction(void);
Boolen_t      videListeAction(ListeAction_t liste);
Action_t      teteAction(ListeAction_t liste);

ListeAction_t insererEnTeteAction(ListeAction_t liste, Action_t a);
ListeAction_t insererAction(ListeAction_t liste, Action_t a);

void afficherAction(Action_t act);
void afficherListeActions(ListeAction_t liste);

Boolen_t rechAction(ListeAction_t liste, int jour, char heure[]);

void sauvegarderAction(FILE *flot, ListeAction_t liste, char* anneeSem, char* numSem);