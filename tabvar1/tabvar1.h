/**
 * \file tabvar1.h
 * \author Matthieu Gaudel (matthieu.gaudel9@etu.univ-lorraine.fr)
 * \brief bibliotheque pour les tableaux
 * \version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TAILLE
#define TAILLE 10000
#include <stdio.h>
#include <stdlib.h>



/**
 * \struct tab
 * \typedef tab_t
 * \brief Tableau de taille variable.
*/

struct tab {
    int size; /*!< Taille effective de \a tab. */
    int tab[TAILLE]; /*!< Tableau avec sa taille memoire. */
};
typedef struct tab tab_t;


/**
 * \brief Crée un tableau de taille variable.
 * 
 * \param tmax Taille maximale du tableau
 * \return tab_t* Pointeur vers un tableau de taille variable
 */
tab_t *make(int tmax);


/**
 * \brief Affiche le contenu du tableau.
 * 
 * \param p Pointeur vers le tableau
 */
void print(tab_t *p);

/**
 * \brief Retourne la taille effective du tableau.
 * 
 * \param p Pointeur vers le tableau
 * \return int Taille effective du tableau
 */
int len(tab_t *p);

/**
 * \brief Retourne la taille maximale du tableau.
 * 
 * \param p Pointeur vers le tableau
 * \return int Taille maximale du tableau
 */
int len_max(tab_t *p);

/**
 * \brief Ajoute une valeur au tableau.
 * 
 * \param p Pointeur vers le tableau
 * \param v Valeur à ajouter
 * \return int 1 si l'ajout a réussi, 0 sinon.
 * 
 * \pre Il ne faut pas que le tableau soit plein.
 * 
 */
int add(tab_t *p, int val);

/**
 * \brief Supprime la dernière valeur du tableau.
 * 
 * \param p Pointeur vers le tableau
 * \return int 1 si la suppression a réussi, 0 sinon.
 * 
 * \pre Il ne faut pas que le tableau soit vide.
 */
int rmv(tab_t *p);

/**
 * \brief Retourne la valeur à l'indice i.
 * 
 * \param p Un pointeur vers le tableau.
 * \param i L'indice de la valeur à récupérer.
 * 
 * \return La valeur à l'indice i ou 0 en cas d'erreur.
 * 
 * \pre Il faut que i soit inférieur à la taille du tableau. Sinon, la fonction renvoie 0.
 * 
 */
int get(tab_t *p, int i);

#endif