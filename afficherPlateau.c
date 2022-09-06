#include "fonctions.h"
void afficherPlateau(casePlateau plateau[LIGNES][COLONNES]){
    for (int l = 0; l < LIGNES; l++) {
        if (l == 0) {
            printf("  |A |B |C |D |E |F |G |H |I |J |K |L |M |N |O ");
        }
        printf("\n");
        for (int c = 0; c < COLONNES; c++) {
            if (c == 0 && l < 9) {
                printf(" %d", l + 1);
            } else if (c == 0) {
                printf("%d", l + 1);
            }
            printf("|%c%c", plateau[l][c].multiplicateur, plateau[l][c].lettre);
        }
    }
    printf("\n\n");
}