#include "fonctions.h"

void saisirNom(joueur *joueur) {
        printf("Saisissez le nom du joueur :\n");
        fflush(stdin);
        fgets(joueur->pseudo, MAX_NOM, stdin);
        joueur->pseudo[strlen(joueur->pseudo) - 1] = '\0';
}