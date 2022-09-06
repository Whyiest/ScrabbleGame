#include "fonctions.h"

void initialiserPlateau(casePlateau plateau[LIGNES][COLONNES], int sauvegarde) {
    FILE *plateauInitial = fopen("C:\\Users\\Thomas\\CLionProjects\\Scrabble\\plateauInitial", "r");
    if (!plateauInitial) {
        perror("File opening failed : plateauInitial ");
        return;
    }
    FILE *plateauSauvegarde = fopen("C:\\Users\\Thomas\\CLionProjects\\Scrabble\\sauvegarde", "r");
    if (!plateauSauvegarde) {
        perror("File opening failed : plateauSauvegarde ");
        return;
    }

    for (int l = 0; l < LIGNES; l++) {
        for (int c = 0; c < COLONNES; c++) {
            if (sauvegarde == 1){
                fscanf(plateauSauvegarde, "%c", &plateau[l][c].lettre);
                if(plateau[l][c].lettre == '.'){
                    plateau[l][c].lettre = ' ';
                }
            } else {
                plateau[l][c].lettre = ' ';
            }
            fscanf(plateauInitial, "%c", &plateau[l][c].multiplicateur);
            if(plateau[l][c].multiplicateur == '.'){
              plateau[l][c].multiplicateur = ' ';
            }
        }
    }

    fclose(plateauInitial);
    plateauInitial = NULL;
    fclose(plateauSauvegarde);
    plateauSauvegarde = NULL;
}