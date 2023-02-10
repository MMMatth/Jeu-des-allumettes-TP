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
#ifndef _TABVAR2_H
#define _TABVAR2_H

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
 */
tab_t *make(int tmax);


/**
 * \brief Affiche le tableau.
 * 
 * \param \a p 
 */
void print(tab_t *p);

/**
 * \brief Retourne la taille effective du tableau.
 * 
 * \param \a p 
 * \return int 
 */
int len(tab_t *p);

/**
 * \brief renvoie la longeur maximum du tableau.
 * 
 * \param \a p 
 * \return int taille maximum du tableau.
 */
int len_max(tab_t *p);

/**
 * \brief Ajoute une valeur au tableau.
 * 
 * \param \a p 
 * \param \a v 
 * \return int 1 si l'ajout a reussi, 0 sinon.
 */
int add(tab_t *p, int v);

/**
 * \brief Supprime la derniere valeur du tableau.
 * s
 * \param \a p 
 * \return int 1 si la suppression a reussi, 0 sinon.
 */
int remove_t(tab_t *p);

/**
 * \brief Retourne la valeur a l'indice i.
 * 
 * \param \a p : le tableau.
 * \param \a i : l'indice.
 * \return int la valeur a l'indice i ou 0 si echec
 */
int get(tab_t *p, int i);

#endif