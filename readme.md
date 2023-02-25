# Jeux avec tableau variable
## Présentation du TP
Ce projet a pour but de créer une bibliothèque permettant de simplifier la programmation de jeux utilisant des tableaux de taille variable. Cette bibliothèque sera utilisée pour implémenter le jeu des allumettes. Le projet est réalisé dans le cadre du cours de programmation en C de l'Université de Lorraine.

## Jeux des allumettes
### Présentation du jeux
Le jeu des allumettes est un jeu de réflexion se jouant à deux joueurs. Le jeu se joue avec n allumettes au départ. Les joueurs jouent à tour de rôle. À son tour, un joueur doit enlever entre une et trois allumettes. Le joueur qui prend la dernière allumette a perdu.

## Exemple de jeu qui peut utiliser cette bibliothèque
### La bataille navale
La bataille navale est un jeu pour deux joueurs.
Chaque joueur place ses navires sur une grille de dimensions généralement 10x10, sans que l'adversaire ne les voit.
Les joueurs tirent tour à tour des missiles sur les cases de la grille ennemie en tentant de toucher les navires adverses.
Si un joueur touche une case occupée par un navire ennemi, il peut continuer à tirer jusqu'à ce qu'il manque sa cible.
Le premier joueur à couler tous les navires ennemis remporte la partie.
Donc on peut utiliser cette bibliothèque pour la grille de jeu et les navires avec un tableau à deux dimension.

## Nouvelle fonctionnalité dans la bibliothèque tabvar2.h
- une fonction rmv_to pour enlever plusieur elements de la liste 
- une fonction fill_tab pour remplir le tableau avec une valeur donnée

## Nouvelle fonctionnalité dans le jeux des allumettes
- l'affichage du jeux sous la forme de batton
- historique des perdant dans un fichier txt
- j'affiche les regles du jeux si le joueur le demande

## To do list :
- [x] Utiliser le argv
- [x] transformer tableau 0 1 et tableau 1 2
- [x] int atoi(char * s);
- [x]  Proposer de nouvelles fonctions à ajouter à la bibliothèque permettant de simplifier la programmation du jeu des allumettes. Attention : ces fonctions doivent rester générales !
- [x] Proposer un autre jeu ou programme qui pourrait utiliser cette bibliothèque. L’implémentation n’est pas nécessaire.
- [ ] Si le temps le permet, proposer et implémenter des extensions au jeu des allumettes.
