/**
 * \file tabVar1.h
 * \author Matthieu Gaudel (matthieu.gaudel9@etu.univ-lorraine.fr)
 * \brief bibliotheque pour les tableaux
 * \version 0.1
 * \date 2023-02-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TABVAR2_H
#define TABVAR2_H

#include <stdio.h>
#include <stdlib.h>




/**
 * \struct tab
 * \typedef tab_t
 * \brief Tableau de taille variable.
*/

struct tab
{
    int size_max;
    int size;
    int* tab;
};
typedef struct tab tab_t;


/**
 * \brief Cree un tableau de taille variable.
 * 
 * \param \a tmax 
 * \return tab_t* un tableau de taille variable.
 * \example tab_t *p = make(10);
 */
tab_t *make(int tmax);


/**
 * \brief Affiche le tableau.
 * 
 * \param \a p 
 * \example print(p) = [1, 2, 3, 4, 5] 
 */
void print(tab_t *p);

/**
 * \brief Retourne la taille effective du tableau.
 * 
 * \param \a p 
 * \return int 
 * \example len(p) = 5
 */
int len(tab_t *p);

/**
 * \brief renvoie la longeur maximum du tableau.
 * 
 * \param \a p 
 * \return int taille maximum du tableau.
 * \example len_max(p) = 10 si tab_t *p = make(10);
 */
int len_max(tab_t *p);

/**
 * \brief Ajoute une valeur au tableau.
 * 
 * \param \a p 
 * \param \a v 
 * \return int 1 si l'ajout a reussi, 0 sinon.
 * \warning Si le tableau est plein, la fonction renvoie 0.
 * \example add(p, 6) = [1, 2, 3, 4, 5, 6] si avant p = [1, 2, 3, 4, 5]
 */
int add(tab_t *p, int v);

/**
 * \brief Supprime la derniere valeur du tableau.
 * s
 * \param \a p 
 * \return int 1 si la suppression a reussi, 0 sinon.
 * \warning Si le tableau est vide, la fonction renvoie 0.
 * \example remove_t(p) = [1, 2, 3, 4] si avant p = [1, 2, 3, 4, 5]
 */
int remove_t(tab_t *p);

/**
 * \brief Supprime les valeurs jusque l'indice i. 
 *  Elle sert dans le jeu des allumettes.
 * \param p 
 * \param i 
 * \return int 
 * \warning Il faut que i soit inferieur a la taille du tableau. Sinon le programme renvoie 0.
 * \example remove_t_to(p, 2) = [1, 2, 3] si avant p = [1, 2, 3, 4, 5]
 */
int remove_t_to(tab_t *p, int i);

/**
 * \brief Retourne la valeur a l'indice i.
 * 
 * \param \a p : le tableau.
 * \param \a i : l'indice.
 * \return int la valeur a l'indice i ou 0 si echec
 * \warning Il faut que i soit inferieur a la taille du tableau. Sinon le programme renvoie 0.
 * \example get(p, 2) = 3 si  p = [1, 2, 3, 4, 5]
 */
int get(tab_t *p, int i);

#endif