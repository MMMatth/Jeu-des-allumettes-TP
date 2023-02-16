/**
 * \file tabVar1.h
 * \author Matthieu Gaudel (matthieu.gaudel9@etu.univ-lorraine.fr)
 * \brief Bibliothèque pour les tableaux
 * \version 0.1
 * \date 2023-02-09
 * 
 * \copyright Copyright (c) 2023
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
    int size_max; // Taille maximale du tableau
    int size;     // Taille effective du tableau
    int* tab;     // Tableau d'entiers
};
typedef struct tab tab_t;

/**
 * \brief Crée un tableau de taille variable.
 * 
 * \param tmax Taille maximale du tableau
 * \return tab_t* Pointeur vers un tableau de taille variable
 * 
 * \example tab_t *p = make(10);
 */
tab_t *make(int tmax);

/**
 * \brief Affiche le contenu du tableau.
 * 
 * \param p Pointeur vers le tableau
 * 
 * \example print(p) = [1, 2, 3, 4, 5] 
 */
void print(tab_t *p);

/**
 * \brief Retourne la taille effective du tableau.
 * 
 * \param p Pointeur vers le tableau
 * \return int Taille effective du tableau
 * 
 * \example len(p) = 5
 */
int len(tab_t *p);

/**
 * \brief Retourne la taille maximale du tableau.
 * 
 * \param p Pointeur vers le tableau
 * \return int Taille maximale du tableau
 * 
 * \example len_max(p) = 10 si tab_t *p = make(10);
 */
int len_max(tab_t *p);

/**
 * \brief Ajoute une valeur au tableau.
 * 
 * \param p Pointeur vers le tableau
 * \param v Valeur à ajouter
 * \return int 1 si l'ajout a réussi, 0 sinon.
 * 
 * \warning Si le tableau est plein, la fonction renvoie 0.
 * 
 * \example add(p, 6) = [1, 2, 3, 4, 5, 6] si avant p = [1, 2, 3, 4, 5]
 */
int add(tab_t *p, int v);

/**
 * \brief Remplit le tableau avec la valeur v jusqu'à la taille n.
 * 
 * \param p Pointeur vers le tableau
 * \param v Valeur à ajouter
 * \param n Nombre de fois où la valeur est ajoutée
 * 
 * \example fill_tab(p, 6, 3) = [6,6,6] si avant p = [] 
 */
void fill_tab(tab_t *p, int v, int n);

/**
 * \brief Supprime la dernière valeur du tableau.
 * 
 * \param p Pointeur vers le tableau
 * \return int 1 si la suppression a réussi, 0 sinon.
 * 
 * \warning Si le tableau est vide, la fonction renvoie 0.
 * 
 * \example rmv(p) = [1, 2, 3, 4] si avant p = [1, 2, 3, 4, 5]
 */
int rmv(tab_t *p);

/**
 * \brief Supprime les valeurs jusqu'à l'indice i.
 * 
 * Cette fonction est utilisée dans le jeu des allumettes.
 * 
 * \param p Un pointeur vers le tableau à modifier.
 * \param i L'indice jusqu'où supprimer les valeurs (exclu).
 * 
 * \return Un entier indiquant si la suppression s'est bien passée.
 *         1 : suppression réussie
 *         0 : échec (i supérieur ou égal à la taille du tableau)
 * 
 * \warning Il faut que i soit inférieur à la taille du tableau. Sinon, la fonction renvoie 0.
 * 
 * \example rmv_to(p, 2) = [1, 2, 3] si avant p = [1, 2, 3, 4, 5]
 */
int rmv_to(tab_t *p, int i);

/**
 * \brief Retourne la valeur à l'indice i.
 * 
 * \param p Un pointeur vers le tableau.
 * \param i L'indice de la valeur à récupérer.
 * 
 * \return La valeur à l'indice i ou 0 en cas d'erreur.
 * 
 * \warning Il faut que i soit inférieur à la taille du tableau. Sinon, la fonction renvoie 0.
 * 
 * \example get(p, 2) = 3 si p = [1, 2, 3, 4, 5]
 */
int get(tab_t *p, int i);


#endif