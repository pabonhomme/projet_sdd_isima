#include "projet.h"


ListeSem initSem(){
    return NULL;
}
void tete(ListeSem liste){
    if(liste==NULL){
        
    }
}
void insererEnTete(ListeSem liste){
    MaillonSem *sem;
    sem=(Sem*)malloc(sizeof(Sem));
    if (sem==NULL){
        printf("Probleme malloc\n");
        exit(1);
    }
    sem->suiv=liste;
    return sem;
}

void insertion(ListeSem liste, Semaine sem){
    if(liste->suiv.annee=NULL){

    }

}
