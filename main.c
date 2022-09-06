#include "fonctions.h"

int main() {
    int nbJoueur = 0;
    int premierCoup = 0,sauvegarde = 1;
    short quitter=1;
    char pioche[TAILLE_PIOCHE] = "AAAAAAAAABBCCDDDEEEEEEEEEEEEEEEFFGGHHIIIIIIIIJKLLLLLMMMNNNNNNOOOOOOPPQRRRRRRSSSSSSTTTTTTUUUUUUVVWXYZ??";
    pioche[TAILLE_PIOCHE] = '\0';
    joueur *joueur1, *joueur2, *joueur3, *joueur4;
    joueur1 = malloc(sizeof(joueur));
    joueur2 = malloc(sizeof(joueur));
    joueur3 = malloc(sizeof(joueur));
    joueur4 = malloc(sizeof(joueur));
    casePlateau plateau[LIGNES][COLONNES];
    printf("Souhaitez-vous lancer une nouvelle partie:0 ou charger une partie déja existente:1\n");
    scanf("%d",&sauvegarde);
    if (sauvegarde==0){
        melanger(pioche);
        saisirNombreJoueur(&nbJoueur);
        initial(nbJoueur,joueur1,joueur2,joueur3,joueur4,pioche);
    }
    initialiserPlateau(plateau, sauvegarde);
    quitter=1;

    while (quitter>0){
        if (quitter>0){
        choixJoueur(joueur1,joueur2, pioche, &quitter,plateau,&premierCoup);
        }
        if (quitter>0) {
            if(nbJoueur==2){
                choixJoueur(joueur2,joueur1, pioche, &quitter, plateau, &premierCoup);
            }else{
                choixJoueur(joueur2,joueur3, pioche, &quitter, plateau, &premierCoup);
            }
        }
        if (nbJoueur==3 || nbJoueur==4){
            if (quitter>0) {
                if(nbJoueur==3){
                    choixJoueur(joueur3,joueur1, pioche, &quitter, plateau, &premierCoup);
                }else{
                    choixJoueur(joueur3,joueur4, pioche, &quitter, plateau, &premierCoup);
                }
            }
        }
        if (nbJoueur==4){
            if (quitter>0) {
                choixJoueur(joueur4,joueur1, pioche, &quitter, plateau, &premierCoup);
            }
        }
    }

    free(joueur1);
    free(joueur2);
    free(joueur3);
    free(joueur4);
    sauvegarder(plateau);


    return 0;

}