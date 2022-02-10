#include "semaine.h"

void affichMenu(void)
    
{   

    printf("             *******************************************************\n");
        printf("             *                                                      *\n");
        printf("             *                 Gestion semaines                     *\n");
        printf("             *                                                      *\n");
        printf("             *******************************************************\n");
        printf("\n                 1- Tests                                                                            \n ");
        printf("\n                 2-                                                                            \n ");
        printf("\n                 3-                                                                   \n");
        printf("\n                 0- quitter                                                                       \n");
        printf("\n              *****************************************************\n");
        printf("\n\n\n\n\n\n\nChoix :");
}
void menu(){
    int choix;
    affichMenu();
    scanf("%d", &choix);
    while(choix>0 && choix<4){
        switch(choix){
            case 0:
                exit(1);
            break;
            case 1:
                printf("Tests\n");
            break;
            case 2:
                printf("Semaine\n");
            break;
            case 3:
                printf("action\n");
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