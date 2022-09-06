#include "fonctions.h"

void remplirChevalet(joueur *joueur, char pioche[TAILLE_PIOCHE]) {
    for (int i = 0; i < 10; i++) {
        if (joueur->chevalet[i] == '.') {
            joueur->chevalet[i] = piocher(pioche);
        }
    }
}