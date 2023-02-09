#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tabVar2.h"

int main(){
    tab_t *tableau = make(10);

    for (int i = 0; i < 10; i++){
        add(tableau, i);
    }
    printf("Voici le tableau initialise :  ");
    print(tableau);
    printf("\nLe tableau fait %d de longueur", len(tableau));
    printf("\nLe tableau fait %d de longueur maximum", len_max(tableau));
    printf("\nOn supprime un element du tableau :  ");
    remove_t(tableau);
    print(tableau);
    printf("\n L'element a l'index 3 est %d\n", get(tableau, 3));
}