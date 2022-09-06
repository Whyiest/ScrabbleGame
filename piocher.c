#include "fonctions.h"

char piocher(char pioche[TAILLE_PIOCHE]) {
    char temp = pioche[0];
    for (int i = 0; i < TAILLE_PIOCHE; i++) {
        pioche[i] = pioche[i + 1];
    }
    return temp;
}