/**
 * @file semaine.h
 * @author Paul BONHOMME & Rime LAMRANI (paul.bonhomme@etu.uca.fr & rime.lamrani@etu.uca.fr)
 * @brief fichier .h : déclaration des types, constantes et prototypes pour les semaines
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
#include "action.h"
#endif

typedef struct
{
    char              annee[5];
    char              numSem[3];
    MaillonAction_t * actions;
}Semaine_t;

typedef struct maillonSem_t
{
    Semaine_t             semaine;
    struct maillonSem_t * suiv;
}MaillonSem_t, *ListeSem_t;

// ------------------FONCTIONS LISTE SEMAINES-------------------------------------
ListeSem_t initSem(void);
Boolen_t   videListeSem(ListeSem_t liste);
Semaine_t  tete(ListeSem_t liste);

ListeSem_t insererEnTete(ListeSem_t liste, Semaine_t s);
ListeSem_t inserer(ListeSem_t liste, Semaine_t sem);

void afficherSemaine(Semaine_t sem);
void afficherListeSem(ListeSem_t liste);

Semaine_t  lireSemaine (FILE *flot);
ListeSem_t chargeSemaine (char* nomFichier, ListeSem_t liste);

void sauvegarder(char* nomFichier, ListeSem_t listeSemaines);

Boolen_t rechSemaineAction(ListeSem_t liste, char annee[], char sem[], int jour, char heure[]);
void supprimerAction(ListeSem_t liste, char* annee, char* numSem, int jour, char* heure);

ListeSem_t supprimerEnTeteSemaine(ListeSem_t liste);
void libererSemaines(ListeSem_t liste);
// -------------------------------------------------------------------------------