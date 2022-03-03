# Gestion d'un échéancier

## Objectifs du projet

Le but de ce projet est de proposer différentes actions sur des listes doublement chainées.
À partir d'un fichier texte, charger une liste de semaine ayant pour chaque semaine une liste
d'actions possible. 

Une ligne du fichier "semaines.txt" se présente sous cette forme : 202201108TPs de SDD
<!-- -->
+ 2022 -> année de la semaine
+ 01   -> numéro de la semaine (01 à 52)
+ 1    -> jour de la semaine (1 à 7)
+ 08   -> heure de la journée (01 à 24)
+ TPs de SDD -> nom de l'action

Lors de la lecture, nous avons décidé de séparer ces informations en deux structures.
Une Semaine_t qui contient l'année et le numéro de semaine, l'autre nommé Action_t contient
le jour de la semaine, l'heure de la journée et le nom de l'action.

Pour voir nos structures de données ainsi que leurs descriptions : Ouvrir l'image "struct_diagramme.png" présente dans le dossier.

Nous sauvegardons les listes dans le fichier "sauvegarde.txt" avec la même forme de ligne
que le fichier de lecture. 

Pour la partie recherche de motif, nous avons créé une structure Jour_t qui va regrouper
toutes les informations d'une action pour un motif donné en paramètre.
Nous créons un tableau (liste contiguë) de structure Jour_t limité à 8 éléments (variable TAILLE_MAX définie dans jour.h).


## Comment lancer l'application ?

Pour lancer le menu : 
+ Ouvrez un terminal
+ Lancez la commande make à partir du dossier de projet
+ Executez ensuite avec la commande : ./projet semaines.txt

La lecture du fichier "semaines.txt" se fait dès le lancement.  
Pour afficher les semaines et les actions : tapez 1.  
Pour sauvegarder les listes dans le fichier "sauvegarde.txt" : tapez 2.  
Pour afficher tous les jours dont le nom de l'action contient un motif précis : tapez 3 et donnez le motif.  
Pour supprimer une action : tapez 4 et donnez les informations de l'action à supprimer.  
Pour lancer la série de test : tapez 5.  

+ Pour supprimer les fichiers .o : make clean
+ Pour supprimer les fichiers .o et l'executable : make rmExec  

## Langages utilisés ?

+ C