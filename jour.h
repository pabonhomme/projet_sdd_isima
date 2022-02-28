/**
 * @file jour.h
 * @author Paul BONHOMME & Rime LAMRANI (paul.bonhomme@etu.uca.fr & rime.lamrani@etu.uca.fr)
 * @brief fichier .h : déclaration des types, constantes et prototypes pour les jour
 * @version 0.1
 * @date 2022-02-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef projet
#define projet // variable qui permet d'éviter les inclusions infinies

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "action.h"
#include "semaine.h"
#endif

#define MAX_JOUR 8 // taille maximale du tableau de jours pour un motif donné

typedef struct 
{
	char annee[5];
    char numSem[3];
    int  jour;
    char heure[3];
    char nomAction[11];
}Jour_t;

// ------------------FONCTIONS JOURS-------------------------------------

int tableauParMotif(char* motif, ListeSem_t listeSemaines, Jour_t jourTab[], Jour_t *finJourTab);
void afficherTableauParMotif(Jour_t jourTab[], char* motif, int nbJour);

// -------------------------------------------------------------------------------