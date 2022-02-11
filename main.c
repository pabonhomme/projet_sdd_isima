#include "semaine.h"

void affichMenu(void)
    
{   
    printf("\n\n             *******************************************************\n");
        printf("             *                                                      *\n");
        printf("             *                 Gestion semaines                     *\n");
        printf("             *                                                      *\n");
        printf("             *******************************************************\n");
        printf("\n                 1- Afficher les listes                                                                            \n ");
        printf("\n                 2-                                                                            \n ");
        printf("\n                 3-                                                                   \n");
        printf("\n                 0- quitter                                                                       \n");
        printf("\n              *****************************************************\n");
        printf("\nChoix :");
}
void menu(){
    int choix;
    ListeSem_t liste = initSem();

    liste = chargeSemaine("semaines.txt", liste);

    affichMenu();
    scanf("%d", &choix);
    while(choix>0 && choix<4){
        switch(choix){
            case 0:
                exit(1);
            break;
            case 1:
                
                AffichListeSem(liste);
            break;
            case 2:
                
            break;
            case 3:
                
            break;
        }
        affichMenu();
        scanf("%d", &choix);
    }
}

int main(int argc, char *argv[]){
    menu();
	return 0;
}