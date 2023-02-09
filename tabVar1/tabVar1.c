#include "tabVar1.h"


tab_t *make(int tmax){
    tab_t *t = malloc(sizeof(tab_t));
    t->size = tmax;
    return t;
}


void print(tab_t *p){
    int i;
    printf("[");
    for(i=0; i< p->size ; i++){
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
    return sizeof(p->tab)/sizeof(int);
}

int add(tab_t *p, int v){
    if (p->size < len_max(p)){
        p->tab[p->size] = v;
        p->size++;
        return 1; // cas de succes
    }
    return 0; // cas d'erreur
}

int remove_t(tab_t *p){
    if (p->size > 0){
        p->size--;
        return 1;
    }
    return 0; // cas d'erreur
}

int get(tab_t* p, int i){
    if (i < p->size){
        return p->tab[i];
    }
    return 0; // cas d'erreur
}