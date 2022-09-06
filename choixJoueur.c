#include "fonctions.h"

void choixJoueur(joueur *joueurEnCours,joueur *joueurconteste, char pioche[TAILLE_PIOCHE], short* quitter,casePlateau plateau[LIGNES][COLONNES], int* premierCoup) {
    int choix = 0;
    printf("\n\nC'est au tour de %s\n" , joueurEnCours->pseudo );
    printf("Votre chevalet: %s\n", joueurEnCours->chevalet);
    printf("Votre score: %d\n", joueurEnCours->score);
    while (choix < 1 || choix > 5) {
        printf("Saisir un mot: 1   Changer une ou plusieurs lettre(s): 2   Passer mon tour: 3   Afficher l'aide: 4   Quitter le jeu: 5\n");
        fflush(stdin);
        scanf(" %d", &choix);
        if (choix < 1 || choix > 5) {
            printf("erreur\n");
        }
    }
    switch (choix) {
        case 1:
            afficherPlateau(plateau);
            saisirMot(plateau, premierCoup, joueurEnCours,joueurconteste);
            remplirChevalet(joueurEnCours, pioche);
            afficherPlateau(plateau);
            break;
        case 2:
            changerLettre(joueurEnCours, pioche);
            break;
        case 3:
            printf("Vous avez decide de passer votre tour.\n");
            break;
        case 4:
            afficherAide();
            choixJoueur(joueurEnCours,joueurconteste, pioche, quitter,plateau,premierCoup);
            break;
        case 5:
            printf("Vous avez quitte le jeu, la partie se sauvegarde.\n");
            *quitter=0;
            break;
    }
}