/**
 * \file fonction.h
 * \author Matthieu Gaudel (matthieu.gaudel9@etu.univ-lorraine.fr)
 * \brief mini bibliothèque de fonctions pour le jeu des allumettes
 * \date 2023-02-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief fonction qui genere un nombre entier aleatoire entre min et max
 * 
 * \param min 
 * \param max 
 * \return int 
 * 
 */
int randint(int min, int max);

/**
 * \brief procedure qui rempli le tableau jeux avec des allumettes
 * 
 * \param jeux le tableau jeux vide
 * \param n_allumettes  le nombre d'allumettes
 * 
 */
void fill_jeu(tab_t *jeux, int n_allumettes);

/**
 * \brief procedure qui affiche le tableau jeux
 * sous cette forme :
 * Il reste 10 allumettes
 * | | | | | | | | | | |
 * | | | | | | | | | | |
 * | | | | | | | | | | | 
 * 
 * \param jeux le tableau jeux
 * \param n_allumettes  le nombre d'allumettes
 * 
 * 
 */
void afficher_jeu(tab_t *jeux, int n_allumettes);

/**
 * \brief procedure qui permet d'afficher les regles
 * 
 */
void afficher_regle();

/**
 * \brief procedure qui permet d'enregistrer qui a perdu dans un fichier texte
 * 
 * \param n_joueur 
 */
void save_score(int n_joueur);
