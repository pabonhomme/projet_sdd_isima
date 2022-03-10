/**
 * @file jour.c
 * @author Paul BONHOMME & Rime LAMRANI (paul.bonhomme@etu.uca.fr & rime.lamrani@etu.uca.fr)
 * @brief fichier .c : fonctions de recherche et d'affichage des actions pour un motif donné
 * @version 0.1
 * @date 2022-02-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "jour.h"

/* --------------------------------------------------------------------
tableauParMotif : Insère les actions contenant le motif voulu
 
En entrée: 
	char       * motif : motif à rechercher 
	ListeSem_t listeSemaines : la liste des semaines 
	Jour_t     jourTab[] : tableau des jours où l'action contient le motif
    Jour_t     * finJourTab : pointeur sur la fin tu tableau de jour

En sortie: int : le nombre de jour trouvé

 -------------------------------------------------------------------- */
int tableauParMotif(char* motif, ListeSem_t listeSemaines, Jour_t jourTab[], Jour_t *finJourTab)
{
	int 	 	  i = 0;
	Boolen_t 	  estRempli = faux; // devient vrai si le tableau atteint la taille maximale
	Jour_t   	  jour; // definition du tableau des jours
	Action_t 	  act; 
	ListeAction_t listeTemp; // liste temporaire des actions pour ne pas modifier la liste d'actions en mémoire

	while(!videListeSem(listeSemaines) && !estRempli) // tant qu'il reste des semaines et que le tableau de jour a de la place
    {
    	listeTemp = (listeSemaines->semaine).actions;
    	while(!videListeAction(listeTemp) && !estRempli) // tant qu'il reste des actions pour une semaine et que le tableau de jour a de la place
    	{
    		act = teteAction(listeTemp); // recuperation de l'action en tête
    		if(strstr(act.nom, motif)!=NULL) // si le nom de l'action contient le motif voulu
    		{
    			strcpy(jour.annee, (listeSemaines->semaine).annee); // copie de l'annee dans le jour
    			strcpy(jour.numSem, (listeSemaines->semaine).numSem); // copie de numSem dans le jour
    			strcpy(jour.heure, act.heure); // copie de l'heure dans le jour
    			strcpy(jour.nomAction, act.nom); // copie du nom de l'action
    			jour.jour = act.jour; // copie du jour

    			jourTab[i] = jour; // insertion du jour dans le tableau des jours
    			if(&jourTab[i] == finJourTab) // si le jour est égal au dernier jour du tableau en comparant adresse courante et pointeur de fin
    				estRempli = vrai; // le tableau est rempli
	        	else
	        		i++; // on avance dans le tableau
    		}
    		listeTemp = listeTemp->suiv; // on avance dans les actions
    	}
        listeSemaines = listeSemaines->suiv; // on avance dans les semaines
    }
    
    return i;
}

/* --------------------------------------------------------------------
afficherTableauParMotif : Affiche la liste des jours contenant le motif

En entrée: 
	Jour_t jourTab[] : tableau des jours où l'action contient le motif 
	char   * motif : motif à rechercher 
	int    nbJour : nombre de jour

En sortie: void

 -------------------------------------------------------------------- */
void afficherTableauParMotif(Jour_t jourTab[], char* motif, int nbJour)
{
	int i = 0;
	if(nbJour != 0)
	{
		printf("Liste des jours contenant le motif : \"%s\"\n", motif);
		printf("nbJour : %d\n", nbJour);
		for(i = 0; i < nbJour; i++)
		{
			printf("\n┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
    		printf("\nNom de l\'action : %s\nAnnee : %s\t Semaine : %s\t Jour : %d\t Heure : %s\n",jourTab[i].nomAction, jourTab[i].annee, jourTab[i].numSem, jourTab[i].jour, jourTab[i].heure);
		}
		printf("\n┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
	}
	else
		printf("Aucune action contenant le motif \"%s\"\n", motif);
}