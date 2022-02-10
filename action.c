#include "action.h"

/* --------------------------------------------------------------------
ListeAction_t : Initialise une liste
 
En entrée: void

En sortie: 

 -------------------------------------------------------------------- */
ListeAction_t initAction(void){
    return NULL;
}

/* --------------------------------------------------------------------
videListeAction : Vérifie si une liste est vide
 
En entrée: la liste

En sortie: un Boolen, vrai si la liste est vide, faux sinon

 -------------------------------------------------------------------- */
Boolen_t videListeAction(ListeAction_t liste){
    if(liste==NULL)
        return vrai;

    return faux;
}

/* --------------------------------------------------------------------
tete : Renvoie le premier maillon de la liste
 
En entrée: la liste des actions

En sortie: la première action de la liste, NULL sinon

 -------------------------------------------------------------------- */
Action_t teteAction(ListeAction_t liste){
    if(videListeAction(liste)){
        printf("Opération interdite\n");
            exit(1);
    }
    else{
        return (liste->action);
    }
}

/* --------------------------------------------------------------------
insererEnTeteAction : Insère une nouvelle action en tête de la liste
 
En entrée: liste : la liste des actions; a : l'action à inserer

En sortie: La liste avec l'élement en tête

 -------------------------------------------------------------------- */
ListeAction_t insererEnTeteAction(ListeAction_t liste, Action_t a){
    MaillonAction_t *act;
    act=(MaillonAction_t*)malloc(sizeof(MaillonAction_t)); // allocation d'un maillon
    if (act==NULL){
        printf("Probleme malloc\n");
        exit(1);
    }
    act->action = a;
    act->suiv=liste;
    return act;
}

/* --------------------------------------------------------------------
insererAction : insère une action
 
En entrée: liste : la liste des actions; a : l'action à inserer

En sortie: La liste avec l'élement inséré

 -------------------------------------------------------------------- */
ListeAction_t insererAction(ListeAction_t liste, Action_t a){
    Action_t a_aux;
    if(videListeAction(liste)){
        return insererEnTeteAction(liste, a); // si la liste est vide, on insère en tête
    }
    a_aux = teteAction(liste); // si la liste n'est pas vide on récupère la tête
    if(a_aux.jour > a.jour){
        return insererEnTeteAction(liste, a); // si jour tete de liste superieure au jour de la semaine à inserer, on insère en tête
    }
    if(a_aux.jour == a.jour && strcmp(a_aux.heure, a.heure) > 0){
        return insererEnTeteAction(liste, a);  // si heure tete de liste superieure à l'heure de la journée à inserer, on insère en tête
    }
    liste->suiv = insererAction(liste->suiv, a);
    return liste;
}

/* --------------------------------------------------------------------
rechAction : recherche une action
 
En entrée: liste : la liste des actions; jour et heure : le jour et l'heure de l'action à trouver

En sortie: un Boolen, vrai si l'action existe, faux sinon

 -------------------------------------------------------------------- */
Boolen_t rechAction(ListeAction_t liste, int jour, char heure[])
{   

    while(liste!=NULL)
    {
        if((liste->action).jour==jour && strcmp((liste->action).heure, heure) == 0)
            {
                return vrai;
            }
        liste=liste->suiv;
    }
    return faux;
}
void AffichListeAction(ListeSem_t liste)
{
    while(!videListeAction(liste))
    {
        printf("\n%s\t%s\n",(liste->action).action);
        liste->action=(liste->action)->suiv;
    }
    printf("\n\t\t┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
}