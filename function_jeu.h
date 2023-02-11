/**
 * \file function_jeu.h
 * \author Matthieu Gaudel (matthieu.gaudel9@etu.univ-lorraine.fr)
 * \brief 
 * \version 0.1
 * \date 2023-02-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * \brief 
 * 
 * \param min 
 * \param max 
 * \return int qui est un nombre entier aléatoire entre min et max 
 */
int randint(int min, int max);

/**
 * \brief procedure qui permet de remplir le tableau avec les battons (1 si pieger, 0 sinon)
 * 
 * \param jeu 
 */
void fill_jeu(tab_t *jeu);

/**
 * \brief fonction qui permet de savoir si le joueur a gagné ou non
 * 
 * \param jeu 
 * \return int 1 si le joueur a gagné, 0 sinon
 */
int qui_gagne(tab_t *jeu);

/**
 * \brief procedure qui permet d'afficher le gagnant en fonction de qui_gagne()
 * 
 * \param jeu 
 * \param numero_joueur 
 */
void affiche_qui_gagne(tab_t *jeu, int numero_joueur);

/**
 * \brief procedure qui permet d'afficher le jeu sous le format suivant :
 * | | | | | |
 * | | | | | |
 * \param jeu 
 */
void print_jeu(tab_t *jeu);


/**
 * \brief procedure qui permet faire les manches (c'est la fonction principale)
 * 
 * \param jeu 
 * \param numero_joueur // numero du joueur qui doit jouer
 */
void manche(tab_t *jeu, int numero_joueur);
