/**
 * \file fonction.h
 * \author Matthieu Gaudel (matthieu.gaudel9@etu.univ-lorraine.fr)
 * \brief mini bibliothèque de fonctions pour le jeu des allumettes
 * \version 0.2
 * \date 2023-02-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * \brief fonction qui permet de choisir un nombre entier aléatoire entre 2 nombres
 * 
 * \param min   le nombre minimum
 * \param max  le nombre maximum
 * \return int  le nombre entier aléatoire
 * 
 * \example int nombre = randint(1, 3);
 * nombre peut valoir 1, 2 ou 3
 */
int randint(int min, int max);

/**
 * \brief fonction qui rempli le tableau jeux avec des allumettes
 * 
 * \param jeux le tableau jeux vide
 * \param n_allumettes  le nombre d'allumettes
 * 
 * \example fill_jeu(jeux, 10);
 * le tableau jeux sera rempli de 10 allumettes dont une qui sera piegée
 * [1, 1, 1, 1, 1, 1, 1, 2, 1, 1]
 */
void fill_jeu(tab_t *jeux, int n_allumettes);

/**
 * \brief fonction qui affiche le tableau jeux
 * 
 * \param jeux le tableau jeux
 * \param n_allumettes  le nombre d'allumettes
 * 
 * \example afficher_jeu(jeux, 10);
 * Il reste 10 allumettes
 * | | | | | | | | | | |
 * | | | | | | | | | | |
 * | | | | | | | | | | | 
 */
void afficher_jeu(tab_t *jeux, int n_allumettes);
