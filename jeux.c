#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblio/tabVar2.h"



int randint(int min, int max){
    srand(time(NULL));
    return rand() % (max - min) + min;
}


void remplire_jeux(tab_t *jeux){
    int len_ = len_max(jeux);
    int batton_piege = randint(0, len_);
    for (int i = 0; i < len_; i++){
        if (i == batton_piege){
            add(jeux, 1);
        }
        else{
            add(jeux, 0);
        }
    }
}

int qui_a_gagne(tab_t *jeux){
    if (len(jeux) == 1) return 1;
    else if (len(jeux) <= 0) return 0;
}

void affiche_qui_a_gagne(tab_t *jeux, int numero_joueur){
    if (qui_a_gagne(jeux) == 1){
        printf("Le joueur %d a gagne \n", numero_joueur);
    }
    else if (qui_a_gagne(jeux) == 0){
        printf("Le joueur %d a perdu \n", numero_joueur);
    }
}

void affiche_jeu(tab_t *jeux){
    for (int i = 0; i < len(jeux); i++){
        printf("| ");
    }
    printf("\n");
    for (int i = 0; i < len(jeux); i++){
        printf("| ");
    }
    printf("\n");
}


void tour(tab_t *jeux, int numero_joueur){
    int batton;

    printf("---- Il reste %d battons ----\n", len(jeux));

    affiche_jeu(jeux);

    // on affiche le numero du joueur
    printf("\n ---- C'est au tour du joueur n %d ---- ", numero_joueur);

    // on verifie que le joueur ne prend que 1, 2 ou 3 battons
    do{
        printf("\nCombien voulez vous en prendre ? (1, 2 ou 3)\t", len(jeux));
        scanf("%d", &batton);
    }while (batton > 3 || batton < 1);

    // on verifie si le joueur a pris un batton piege
    for (int i = 1; i <= batton; i++){
        if (get(jeux, len(jeux) - i) == 1){
            printf("Vous etes tombe sur un batton piege, vous prennez 2 fois plus \n");
            batton *= 2;
        }
    }

    // on retire les battons pris par le joueur
    for (int i = 1; i <= batton; i++) remove_t(jeux);

    // on regarde si on a un gagnant
    affiche_qui_a_gagne(jeux, numero_joueur);

}

int main(int argc, char * argv[]){
    int nb_batton = 12;

    tab_t *jeux = make(nb_batton);
    int play = 1;

    remplire_jeux(jeux);

    printf("----- Debut de la partie ----- \n");
    while (play){
        tour(jeux, 1);
        if (qui_a_gagne(jeux) == 1 || qui_a_gagne(jeux) == 0){break;}
        tour(jeux, 2);
        if (qui_a_gagne(jeux) == 1 || qui_a_gagne(jeux) == 0){break;}
    }
    








    return EXIT_SUCCESS;
}