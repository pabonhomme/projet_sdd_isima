/**
 * @file test.c
 * @author Paul BONHOMME & Rime LAMRANI (paul.bonhomme@etu.uca.fr & rime.lamrani@etu.uca.fr)
 * @brief fichier .c : fonction de test complet du projet
 * @version 0.1
 * @date 2022-03-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "jour.h"

void mainTest(ListeSem_t liste)
{
	int        nbJour, jourASupp; // choix de l'utilisateur, nombre de jour trouvé pour un motif donné et jour à supprimer
    char       motif[11], anneeASupp[11], numSemASupp[3], heureASupp[3]; // motif donné par l'utilisateur, Annee a supprimer, numero de semaine a supprimer, heure a supprimer

    Jour_t     jourTab[MAX_JOUR], * finJourTab; // initialisation tableau de jours statique et pointeur de fin

    finJourTab = &jourTab[MAX_JOUR]; // affectation du pointeur de fin du tableau de jour

    printf("\n\n═════════════════════INITIALISATION ET LECTURE DU FICHIER═════════════════════\n");

    printf("\nAppuyez sur entrée pour afficher la liste des semaines\n");
    getchar();
	while( getchar() != '\n' );

	printf("\n\n═════════════════════AFFICHAGE DE LA LISTE DES SEMAINES═════════════════════\n");
    afficherListeSem(liste);

	printf("\n\n═════════════════════SUPPRESSION DE DEUX ACTIONS═════════════════════\n");
    printf("\nNous allons supprimer le tp de physique et le tp de systeme de la liste puis afficher la liste à nouveau\n");

    printf("Appuyer sur entrée pour supprimer : \n");
	while( getchar() != '\n' );

	// PREMIERE ACTION
	strcpy(anneeASupp, "2023"); // TP de physique
	strcpy(numSemASupp, "05");
	jourASupp = 3;
	strcpy(heureASupp, "02");

	if(supprimerAction(liste, anneeASupp, numSemASupp, jourASupp, heureASupp))
    {
        liste = supprimerMaillonSemaine(liste, anneeASupp, numSemASupp);
    }

    // DEUXIEME ACTION
	strcpy(anneeASupp, "2019"); // TP de systeme
	strcpy(numSemASupp, "06");
	jourASupp = 1;
	strcpy(heureASupp, "08");

	if(supprimerAction(liste, anneeASupp, numSemASupp, jourASupp, heureASupp))
    {
        liste = supprimerMaillonSemaine(liste, anneeASupp, numSemASupp);
    }

	afficherListeSem(liste);
	printf("\nNous pouvons voir que les deux actions ont bien été supprimées de la liste\n");
	printf("De plus, on voit que la semaine 06 de 2019 a été supprimée de la liste car elle ne contenait plus d'action\n");

	printf("\n\n═════════════════════AFFICHAGE JOUR AVEC MOTIF═════════════════════\n");
	printf("\nNous allons maintenant afficher les actions contenant un motif, nous choisissons le motif \"C\", nous devrions avoir TP de C et TP de C++\n");
	printf("Appuyer sur entrée pour afficher le tableau de jours au motif \"C\" :\n");
	while( getchar() != '\n' );

	// MOTIF "C"
	strcpy(motif, "C");
	nbJour = tableauParMotif(motif, liste, jourTab, finJourTab);
	afficherTableauParMotif(jourTab, motif, nbJour);

	printf("Nous voulons le motif \"TP\", nous en aurons 7 au maximum car nous venons de  supprimer les TP de physique et de systeme \n");
	printf("Appuyer sur entrée pour afficher le tableau de jours au motif \"TP\" : \n");
	while( getchar() != '\n' );

	// MOTIF "TP"
	strcpy(motif, "TP");
	nbJour = tableauParMotif(motif, liste, jourTab, finJourTab);
	afficherTableauParMotif(jourTab, motif, nbJour);

	printf("\n\n═════════════════════SAUVEGARDE DANS UN FICHIER═════════════════════\n");
	printf("\nNous allons maintenant sauvegarder les données dans le fichier \"sauvegarde.txt\"\n");
	printf("Appuyer sur entrée pour sauvegarder : \n");
	while( getchar() != '\n' );


	sauvegarder("sauvegarde.txt", liste); // SAUVEGARDE
	printf("\nOn remarque que les lignes pour le TP de physique et le TP de systeme ne sont pas présentes.\nOuvrez le fichier de sauvegarde pour vérifier et cliquez sur entrée pour continuer.\n");
	while( getchar() != '\n' );

	printf("\n\n═════════════════════CAS D'ERREURS═════════════════════\n");
	printf("\nNous allons maintenant tester différents cas d'erreurs.\n");

	printf("\nCas où aucune action ne contient un motif donné :\n");
	printf("Appuyer sur entrée pour afficher le tableau de jours au motif \"test_err\" :\n");
	while( getchar() != '\n' );
	strcpy(motif, "test_err");
	nbJour = tableauParMotif(motif, liste, jourTab, finJourTab);
	afficherTableauParMotif(jourTab, motif, nbJour);


	printf("\nCas où l'action de l'année 2048 à supprimer n'existe pas : \n");
	printf("Appuyer sur entrée pour continuer : \n");
	while( getchar() != '\n' );

	strcpy(anneeASupp, "2048"); // Action inexistante
	strcpy(numSemASupp, "06");
	jourASupp = 1;
	strcpy(heureASupp, "08");

	if(supprimerAction(liste, anneeASupp, numSemASupp, jourASupp, heureASupp))
    {
        liste = supprimerMaillonSemaine(liste, anneeASupp, numSemASupp);
    }
	printf("\nOn peut voir que l'action a été detectée comme inexistante par l'algorithme.\n");

	printf("\n\n═════════════════════FIN DE LA SERIE DE TEST═════════════════════\n");
	libererSemaines(liste);

}