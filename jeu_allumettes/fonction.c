#include <stdlib.h>
#include <stdio.h>

#include "../tabvar2/tabvar2.h"
#include "fonction.h"


int randint(int min, int max){
    return rand() % (max - min + 1) + min;
}

void fill_jeu(tab_t *jeux, int n_allumettes){
    int allumette_piegee = randint(0, n_allumettes - 1);
    for (int i = 0; i < n_allumettes; i++) {
        add(jeux, (i == allumette_piegee) ? 2 : 1);
    }
}

void afficher_jeu(tab_t *jeux, int n_allumettes){
    printf("Il reste %d allumettes.\n", n_allumettes);
    for (int j = 0; j <= 2; j++){
        for (int i = 0; i < n_allumettes; i++) {
            printf("| ");
        }
        printf("\n");
    }
}
