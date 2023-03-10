#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "tabvar2/tabvar2.h"
#include "f_jeu/fonction.h"

int main(int argc, char *argv[]) {
    // Initialisation des variables
    int n_allumettes = atoi(argv[1]);
    tab_t* jeu = make(n_allumettes * 2 );
    int joueur_actuel = 1;
    int choix;
    bool jeu_piege = false;

    srand(time(NULL)); // initialisation du générateur de nombres aléatoires
    
    // Initialisation du tableau d'allumettes
    fill_jeu(jeu, n_allumettes);
    
    do{
        printf("Voulez vous voir les regles ? (0/1) ");
        scanf("%d", &choix);
    }while (choix < 0 || choix > 1);
    if (choix == 1){afficher_regle();}



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

        // On re calcule le nombre d'allumettes restantes
        n_allumettes -= choix;

        // On vérifie si l'jeu est piégée
        for (int i = 0; i < choix && !jeu_piege ; i++) {
            if (get(jeu, n_allumettes - i - 1) == 2) {
                printf("Vous avez pris une allumette piegee ! Le nombre d'allumette est multiplié par 2\n");
                n_allumettes = ( n_allumettes * 2 ); // On multiplie le nombre d'allumettes par 2
                jeu_piege = true; // On met la variable jeu_piege à true pour ne pus prendre en compte les allumettes piégées
            }
        }

        // On retire les allumettes
        rmv_to(jeu, n_allumettes);
        
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
    
    // Sauvegarde du score dans le fichier score.txt
    save_score(joueur_actuel);

    return EXIT_SUCCESS;
}