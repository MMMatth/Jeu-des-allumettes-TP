#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tabVar1.h"

int main(){
    tab_t *t = make(0);
    for (int i = 0; i < 10; i++){
        add(t, i);
    }
    printf("%d\n",len_max(t));
    print(t);


    return EXIT_SUCCESS;
}