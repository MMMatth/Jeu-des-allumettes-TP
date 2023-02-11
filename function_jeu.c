#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tabvar2/tabvar2.h"
#include "function_jeu.h"



int randint(int min, int max){
    srand(time(NULL));
    return rand() % (max - min) + min;
}


void fill_jeu(tab_t *jeu){
    int len_ = len_max(jeu);
    int batton_piege = randint(0, len_);
    for (int i = 0; i < len_; i++){
        if (i == batton_piege){
            add(jeu, 1);
        }
        else{
            add(jeu, 0);
        }
    }
}

int qui_gagne(tab_t *jeu){
    if (len(jeu) == 1) return 1;
    else if (len(jeu) <= 0) return 0;
}

void affiche_qui_gagne(tab_t *jeu, int numero_joueur){
    if (qui_gagne(jeu) == 1) printf("Le joueur %d a gagne \n", numero_joueur);
    else if (qui_gagne(jeu) == 0) printf("Le joueur %d a perdu \n", numero_joueur);
}

void print_jeu(tab_t *jeu){
    for (int i = 0; i < len(jeu); i++){
        printf("| ");
    }
    printf("\n");
    for (int i = 0; i < len(jeu); i++){
        printf("| ");
    }
    printf("\n");
}


void manche(tab_t *jeu, int numero_joueur){
    int batton;

    printf("---- Il reste %d battons ----\n", len(jeu));

    print_jeu(jeu);

    // on affiche le numero du joueur
    printf("\n ---- C'est au tour du joueur n %d ---- ", numero_joueur);

    // on verifie que le joueur ne prend que 1, 2 ou 3 battons
    do{
        printf("\nCombien voulez vous en prendre ? (1, 2 ou 3)\t", len(jeu));
        scanf("%d", &batton);
    }while (batton > 3 || batton < 1);

    // on verifie si le joueur a pris un batton piege
    for (int i = 1; i <= batton; i++){
        if (get(jeu, len(jeu) - i) == 1){
            printf("Vous etes tombe sur un batton piege, vous prennez 2 fois plus \n");
            batton *= 2;
        }
    }

    // on retire les battons pris par le joueur
    for (int i = 1; i <= batton; i++) remove_t(jeu);

    // on regarde si on a un gagnant
    affiche_qui_gagne(jeu, numero_joueur);

}