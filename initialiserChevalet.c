#include "fonctions.h"

void initialiserChevalet(joueur* joueur, char pioche[TAILLE_PIOCHE]) {
    for (int i = 0; i < MAX_CHEVALET; i++) {
        joueur->chevalet[i] = '\0';
    }
    for (int i = 0; i < 7; i++) {
        joueur->chevalet[i] = piocher(pioche);
    }
    joueur->score=0;
}