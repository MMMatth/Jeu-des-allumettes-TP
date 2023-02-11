#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tabvar2/tabvar2.h"
#include "function_jeu.h"



int main(int argc, char * argv[]){
    int nb_batton = 12;
    tab_t *jeux = make(nb_batton);
    int play = 1;
    fill_jeu(jeux);
    printf("----- Debut de la partie ----- \n");
    while (play){

        // manche avec le joueur 1
        manche(jeux, 1);
        if (fin_jeu(jeux, 1) == 1 || fin_jeu(jeux,1) == 0) break;

        // manche avec le joueur 2
        manche(jeux, 2);
        if (fin_jeu(jeux, 2) == 1 || fin_jeu(jeux,2) == 0) break;


    }
    return EXIT_SUCCESS;
}