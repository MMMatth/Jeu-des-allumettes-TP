#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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
            add(jeu, 2);
        }
        else{
            add(jeu, 1);
        }
    }
}

int fin_jeu(tab_t *jeu, int numero_joueur){
    if (len(jeu) == 1) {
        return 1;
    }
    else if (len(jeu) <= 0) {
        return 0;
    }
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

void supr_batton(tab_t *jeu, int batton){
    for (int i = 1; i <= batton; i++){
        if (get(jeu, len(jeu) - i) == 2) // si un des battons qui suivent le batton pris est un batton piege
        {
            printf("Vous etes tombe sur un batton piege, vous en prennez donc 2 fois plus \n");
            batton *= 2;
        }
    }
    for (int i = 0; i < batton; i++){remove_t(jeu);}
}

void manche(tab_t *jeu, int numero_joueur){
    int batton;

    printf("---- Il reste %d battons ----\n", len(jeu));

    print_jeu(jeu);
    sleep(1);

    // on affiche le numero du joueur
    printf("\n ---- C'est au tour du joueur n %d ---- ", numero_joueur);

    // on verifie que le joueur ne prend que 1, 2 ou 3 battons
    do{
        printf("\nCombien voulez vous en prendre ? (1, 2 ou 3)\t");
        scanf("%d", &batton);
    }while (batton > 3 || batton < 1);

    // on retire les battons pris par le joueur en prenant en compte les battons pieges
    supr_batton(jeu, batton);
    

    // on regarde si le joueur a gagne ou perdu
    if (fin_jeu(jeu, numero_joueur) == 1) printf("\n Le joueur %d a gagne\n", numero_joueur);
    else if (fin_jeu(jeu, numero_joueur) == 0) printf("\n Le joueur %d a perdu\n", numero_joueur); 
}