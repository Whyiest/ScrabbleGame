#include "fonctions.h"

void sauvegarder(casePlateau plateau[LIGNES][COLONNES]) {
    FILE *plateauSauvegarde = fopen("C:\\Users\\Thomas\\CLionProjects\\Scrabble\\sauvegarde", "w");
    if (!plateauSauvegarde) {
        perror("File opening failed : plateauSauvegarde ");
        return;
    }

    for (int l = 0; l < LIGNES; l++) {
        for (int c = 0; c < COLONNES; c++) {
            if (plateau[l][c].lettre != ' ') {
                fwrite(&plateau[l][c].lettre, 1, 1, plateauSauvegarde);
            } else {
                fwrite(".", 1, 1, plateauSauvegarde);
            }
        }
    }

    fclose(plateauSauvegarde);
    plateauSauvegarde = NULL;
}