#include "fonctions.h"

void saisirNombreJoueur(int* n) {
    while (*n < 2 || *n > 4) {
        printf("Combien de joueur veulent participer ?\n");
        scanf(" %d", n);
        if (*n < 2 || *n > 4) {
            printf("/!/ Le nombre de joueur doit etre compris entre 2 et 4. Veuillez reessayez\n");
        }
    }
}