#include <stdio.h>
#include <stdlib.h>

#include "tabvar2.h"


tab_t* make(int tmax){
    tab_t * p = malloc(sizeof(tab_t));
    p->tab = malloc(tmax * sizeof(int));
    p->size = 0;
    p->size_max = tmax;
    return p;
}


void print(tab_t *p){
    int i;
    printf("[");
    for(i=0; i < p->size ; i++){
        if (!(i==0 || i== p->size)){
            printf(" ,");
        }
        printf("%d", p->tab[i]);
    }
    printf("]");
}

int len(tab_t *p){
    return p->size;
}

int len_max(tab_t *p){
    return p->size_max;
}

int add(tab_t *p, int v){
    if (p->size < p->size_max)
    {
        p->tab[p->size] = v;
        p->size++;
        return 1; // cas de succes
    }
    return 0; // cas d'erreur
}


void fill_tab(tab_t *p, int v, int n){
    for(int i=0; i < n && i < p->size_max; i++){
        add(p, v); // ajoute la valeur
    }
}



int rmv(tab_t *p){
    if (p->size > 0){
        p->size--;
        return 1;
    }
    return 0; // cas d'erreur
}

int rmv_to(tab_t *p, int i){
    for (int j = p->size ; j > i ; j--){
        p->size--;
        if (p->size == 0){
            return 0; // cas d'erreur
        }
    }
    return 1; // cas de succes
}

int get(tab_t* p, int i){
    if (i < p->size){
        return p->tab[i];
    }
    return 0; // cas d'erreur
}
