#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../tabvar2/tabvar2.h"
#include "fonction.h"

int main(int argc, char *argv[]) {
    // Initialisation des variables
    int n_allumettes = atoi(argv[1]);
    tab_t* jeu = make(n_allumettes);
    int joueur_actuel = 1;
    int choix;

    srand(time(NULL)); // initialisation du générateur de nombres aléatoires
    
    // Initialisation du tableau d'allumettes
    fill_jeu(jeu, n_allumettes);
    
    // Boucle principale
    while (n_allumettes > 1) {
        printf("--------------------\n");

        // Affichage du tableau d'allumettes
        afficher_jeu(jeu, n_allumettes);

        // Choix du nombre d'jeu à prendre
        do{
            printf("Joueur %d, combien d'jeu voulez-vous prendre ? (1-3) ", joueur_actuel);
            scanf("%d", &choix);
        }while (choix < 1 || choix > 3);

        
        // On vérifie si l'jeu est piégée
        for (int i = 0; i < choix; i++) {
            if (get(jeu, n_allumettes - i - 1) == 2) {
                printf("Vous avez pris une allumette piegee ! Vous prenez deux fois plus d'allumettes\n");
                choix *= 2;
            }
        }
        // On retire les allumettes
        rmv_to(jeu, n_allumettes - choix);
        n_allumettes -= choix;
        
        // Changement de joueur
        joueur_actuel = (joueur_actuel == 1) ? 2 : 1;
    }
    
    // Annonce du résultat final
    printf("--------------------\n");
    printf("Il ne reste plus qu'une allumette !\n");
    printf("Joueur %d, vous avez perdu !\n", joueur_actuel);
    printf("--------------------\n");
    
    // Libération de la mémoire allouée pour le tableau d'jeu
    free(jeu->tab);
    free(jeu);
    
    return EXIT_SUCCESS;
}