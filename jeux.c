#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblio/tabVar2.h"
#include "function_jeu.h"



int main(int argc, char * argv[]){
    int nb_batton = 12;
    tab_t *jeux = make(nb_batton);
    int play = 1;
    fill_jeu(jeux);
    printf("----- Debut de la partie ----- \n");
    while (play){
        manche(jeux, 1);
        if (qui_gagne(jeux) == 1 || qui_gagne(jeux) == 0){break;}
        manche(jeux, 2);
        if (qui_gagne(jeux) == 1 || qui_gagne(jeux) == 0){break;}
    }
    return EXIT_SUCCESS;
}