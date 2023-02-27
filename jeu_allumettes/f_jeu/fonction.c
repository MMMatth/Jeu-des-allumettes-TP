#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../tabvar2/tabvar2.h"
#include "fonction.h"


int randint(int min, int max){
    return rand() % (max - min + 1) + min;
}

void fill_jeu(tab_t *jeux, int n_allumettes){
    int allumette_piegee = randint(0, n_allumettes - 1);
    fill_tab(jeux, 1, n_allumettes);
    jeux->tab[allumette_piegee] = 2;
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

void save_score(int n_joueur){
    FILE *fichier = fopen("score.txt", "a");
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    char timestamp[80];
    strftime(timestamp, 80, "%c", local);
    fprintf(fichier, "Le joueur %d a perdu | %s\n", n_joueur, timestamp);
    fclose(fichier);
}

void afficher_regle(){
    printf("--------------------\n");
    printf("Le jeu des allumettes est un jeu de strategie se jouant a deux.\n");
    printf("Le but du jeu est de ne pas prendre la derniere allumette.\n");
    printf("A chaque tour, un joueur doit prendre entre 1 et 3 allumettes.\n");
    printf("Le joueur qui prend la derniere allumette a perdu.\n");
}