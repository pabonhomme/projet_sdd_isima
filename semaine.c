#include "semaine.h"

/* --------------------------------------------------------------------
initSem : Initialise une liste
 
En entrée: void

En sortie: 

 -------------------------------------------------------------------- */
ListeSem_t initSem(void){
    return NULL;
}

/* --------------------------------------------------------------------
videListeSem : Vérifie si une liste est vide
 
En entrée: la liste

En sortie: un Boolen, vrai si la liste est vide, faux sinon

 -------------------------------------------------------------------- */
Boolen_t videListeSem(ListeSem_t liste){
    if(liste==NULL)
        return vrai;

    return faux;
}

/* --------------------------------------------------------------------
tete : Renvoie le premier maillon de la liste
 
En entrée: la liste des semaines

En sortie: la première semaine de la liste, NULL sinon

 -------------------------------------------------------------------- */
Semaine_t tete(ListeSem_t liste){
    if(videListeSem(liste)){
        printf("Opération interdite\n");
            exit(1);
    }
    else{
        return (liste->semaine);
    }
}

/* --------------------------------------------------------------------
insererEnTete : Insère une nouvelle semaine en tête de la liste
 
En entrée: liste : la liste des semaines; s : la semaine à inserer

En sortie: La liste avec l'élement en tête

 -------------------------------------------------------------------- */
ListeSem_t insererEnTete(ListeSem_t liste, Semaine_t s){
    MaillonSem_t *sem;
    sem=(MaillonSem_t*)malloc(sizeof(MaillonSem_t)); // allocation d'un maillon
    if (sem==NULL){
        printf("Probleme malloc\n");
        exit(1);
    }
    sem->semaine = s;
    sem->suiv=liste;
    return sem;
}

/* --------------------------------------------------------------------
inserer : insère une semaine
 
En entrée: liste : la liste des semaines; s : la semaine à inserer

En sortie: La liste avec l'élement inséré

 -------------------------------------------------------------------- */
ListeSem_t inserer(ListeSem_t liste, Semaine_t sem){
    Semaine_t s_aux;
    if(videListeSem(liste)){
        return insererEnTete(liste, sem); // si la liste est vide, on insère en tête
    }
    s_aux = tete(liste); // si la liste n'est pas vide on récupère la tête
    if(strcmp(s_aux.annee, sem.annee) > 0){
        return insererEnTete(liste, sem); // si annee tete de liste superieure à l'année de la semaine à inserer, on insère en tête
    }
    if(strcmp(s_aux.annee, sem.annee) == 0 && strcmp(s_aux.sem, sem.sem) > 0){
        return insererEnTete(liste, sem); // si annee tete de liste égale à l'année de la semaine à insérer et semaine de la tete supériere, on insère en tête
    }
    if(strcmp(s_aux.annee, sem.annee) == 0 && strcmp(s_aux.sem, sem.sem) == 0){
        (liste->semaine).actions = insererAction((liste->semaine).actions, (sem.actions)->action); // on insère l'action dans la liste d'action de la semaine en question
        return liste;
    }
    liste->suiv = inserer(liste->suiv, sem);
    return liste;
}

/* --------------------------------------------------------------------
rechSemaine : recherche une semaine
 
En entrée: liste : la liste des semaines; annee et sem : l'année et la semaine à trouver

En sortie: un Boolen, vrai si l'action existe, faux sinon

 -------------------------------------------------------------------- */
Boolen_t rechSemaine(ListeSem_t liste, char annee[], char sem[])
{
    while(liste!=NULL)
    {
        if(strcmp((liste->semaine).annee, annee) == 0 && strcmp((liste->semaine).sem, sem) == 0)
            {
                return vrai;
            }
        liste=liste->suiv;
    }
    return faux;
}

/* --------------------------------------------------------------------
lireSemaine : lis une ligne du fichier
 
En entrée: flot : pointeur sur le fichier à lire

En sortie: semaine lue

 -------------------------------------------------------------------- */
Semaine_t lireSemaine (FILE *flot)
{   Semaine_t s;
    Action_t a;
    fscanf(flot,"%4s%2s%d%2s%[^\n]%*c", s.annee, s.sem, a.jour, a.heure, a.action);
    s.actions = insererAction(initAction(), a); // on crée un premier maillon pour la liste d'actions de la semaine
    return s;
}

/* --------------------------------------------------------------------
chargeSemaine : charge les semaines à partir d'un fichier
 
En entrée: nomFichier : Nom du fichier à lire ; liste : la liste des semaines

En sortie: La liste avec les semaines insérées

 -------------------------------------------------------------------- */
ListeSem_t chargeSemaine(char* nomFichier, ListeSem_t listeSemaines)
{   int i;
    Semaine_t s;
    FILE*flot;
    flot=fopen(nomFichier,"r");

    if (flot == NULL)
        {
            printf("Problème d'ouverture du fichier\n");
        }
    if (feof(flot))
        {
            printf("fichier vide\n");
            return listeSemaines;
        }
    s=lireSemaine(flot);

    while(!feof(flot))
        {
            listeSemaines=inserer(listeSemaines, s);
            s=lireSemaine(flot);
           
        }
    fclose(flot);
    return listeSemaines;
}

// ListeSem_t verifSemaines(ListeSem_t listeSemaines, Semaine_t s){

//     if(rechSemaine(listeSemaines, s.annee, s.sem)){ // si la semaine existe dejà pour cette action
//         while(strcmp((listeSemaines->semaine).annee, s.annee) == 0 && strcmp((listeSemaines->semaine).sem, s.sem) == 0)
//         {
//             listeSemaines=listeSemaines->suiv; // on cherche le maillon de la semaine voulue
//         }
//         (listeSemaines->semaine).action = insererAction((listeSemaines->semaine).action, s->action); // on insère l'action dans la liste d'action de la semaine en question
        
//     }
//     else{
//         listeSemaines=inserer(listeSemaines, s); // sinon on insère la semaine lue avec l'action dedans
//     }

//     return listeSemaines;
// }