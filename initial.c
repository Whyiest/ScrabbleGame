#include "fonctions.h"

void initial(int nbJoueur, joueur* joueur1, joueur* joueur2, joueur* joueur3,joueur* joueur4, char pioche[TAILLE_PIOCHE]){
    saisirNom(joueur1);
    saisirNom(joueur2);
    initialiserChevalet(joueur1, pioche);
    initialiserChevalet(joueur2, pioche);
    if (nbJoueur==3 || nbJoueur==4){
        saisirNom(joueur3);
        initialiserChevalet(joueur3, pioche);
        if (nbJoueur==4){
            saisirNom(joueur4);
            initialiserChevalet(joueur4, pioche);
        }
    }
}