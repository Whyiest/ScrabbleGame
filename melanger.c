#include "fonctions.h"

void melanger(char pioche[TAILLE_PIOCHE]) {
    srand(time(NULL));
    for (int i = 0; i < NOMBRE_ECHANGE; ++i) {
        int a = rand() % (TAILLE_PIOCHE);
        int b = rand() % (TAILLE_PIOCHE);

        char temp = pioche[a];
        pioche[a] = pioche[b];
        pioche[b] = temp;
    }
}