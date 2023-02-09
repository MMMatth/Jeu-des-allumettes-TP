#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabVar2.h"


int debut_de_partie(){
    int batton;
    scanf("%d", &batton);
    return 0;
}

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

int round(tab_t *jeux, int nb_batton, int numero_joueur){
    int batton;
    printf("C'est au tour du joueur n° %d \n", numero_joueur);
    printf("Il reste %d battons, combien voulez vous en prendre ? (1, 2 ou 3)\n");

    do{
        scanf("%d", &batton);
    }while (batton > 3 || batton < 1);

    for (int i = 1; i <= batton; i++){
        if (get(jeux, len(jeux) - i) == 1){
            printf("Vous êtes tombé sur un batton piege, vous devez en prendre 2 fois plus ");
            batton *= 2;
        }
    }
    if (batton > nb_batton){
        printf("Vous avez perdu, vous avez pris le dernier batton");
    }else{
        printf("Il reste %d battons", nb_batton - batton);
        for (int i = 1; i <= batton; i++){
            remove_t(jeux);
        }
    }
    return batton;
    }
}}

int main(int argc, char * argv[]){
    int nb_batton = 12;

    tab_t *jeux = make(nb_batton);
    int play = 1;


    printf("----- Debut de la partie ----- \n");
    while (play){
        round()
    }
    remplire_jeux(jeux);








    return EXIT_SUCCESS;
}