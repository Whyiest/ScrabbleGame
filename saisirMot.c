#include "fonctions.h"

int contestation(joueur *joueur1,joueur *joueurConteste,int contest){
    char ouiOuNon[4];
    printf("%s souhaitez vous contester l'orthographe du/des mot(s) forme(s) (OUI ou NON)?\n",joueurConteste->pseudo);
    fflush(stdin);
    scanf("%s",ouiOuNon);
    contest=strcmp("NON\0",ouiOuNon);
    if(contest!=0){
     printf("Veuillez verifier la validite du mot dans un dictionnaire. Le mot existe t'il (OUI ou NON)?\n");
        fflush(stdin);
        scanf("%s",ouiOuNon);
        contest=strcmp("OUI\0",ouiOuNon);
        if (contest==0){
            printf("Le mot est valide,%s substitue 10 points a %s\n",joueur1->pseudo,joueurConteste->pseudo);
            joueur1->score +=10;
            joueurConteste->score -=10;
        }
        else{
            printf("Le mot est faux,%s substitue 10 points a %s\n",joueurConteste->pseudo,joueur1->pseudo);
            joueur1->score -=10;
            joueurConteste->score +=10;
        }
    }
    return contest;
}



    void calculScore(char mot[MAX_LETTRES], casePlateau plateau[LIGNES][COLONNES], joueur *joueur1, char position, int ligne,int icolonne) {
        int multiplicationMot = 1;
        int multiplicationLettre = 1;
        int score=0;
        if (position == 'V') {
            for (int i = 0; i < strlen(mot); i++) {
                if (plateau[ligne + i][icolonne].multiplicateur == '@') {
                    multiplicationMot *= 2;
                    plateau[ligne + i][icolonne].multiplicateur = ' ';
                }
                if (plateau[ligne + i][icolonne].multiplicateur == '$') {
                    multiplicationMot *= 3;
                    plateau[ligne + i][icolonne].multiplicateur = ' ';
                }
            }
        } else {
            for (int i = 0; i < strlen(mot); i++) {
                if (plateau[ligne][icolonne + i].multiplicateur == '@') {
                    multiplicationMot *= 2;
                    plateau[ligne][icolonne + i].multiplicateur = ' ';
                }
                if (plateau[ligne][icolonne + i].multiplicateur == '$') {
                    multiplicationMot *= 3;
                    plateau[ligne][icolonne + i].multiplicateur = ' ';
                }
            }
        }
        for (int i = 0; i < strlen(mot); i++) {
            if (mot[i] == 'A' || mot[i] == 'E' || mot[i] == 'I' || mot[i] == 'L' || mot[i] == 'N' || mot[i] == 'O' ||
                mot[i] == 'R' || mot[i] == 'S' || mot[i] == 'T' || mot[i] == 'U') {
                multiplicationLettre = 1;
            }
            if (mot[i] == 'D' || mot[i] == 'G' || mot[i] == 'M') {
                multiplicationLettre = 2;
            }
            if (mot[i] == 'B' || mot[i] == 'C' || mot[i] == 'P') {
                multiplicationLettre = 3;
            }
            if (mot[i] == 'F' || mot[i] == 'H' || mot[i] == 'V') {
                multiplicationLettre = 4;
            }
            if (mot[i] == 'J' || mot[i] == 'Q') {
                multiplicationLettre = 8;
            }
            if (mot[i] == 'K' || mot[i] == 'W' || mot[i] == 'X' || mot[i] == 'Y' || mot[i] == 'Z') {
                multiplicationLettre = 10;
            }
            if (position == 'V') {
                if (plateau[ligne + i][icolonne].multiplicateur == '&') {
                    multiplicationLettre *= 2;
                    plateau[ligne + i][icolonne].multiplicateur = ' ';
                }
                if (plateau[ligne + i][icolonne].multiplicateur == '%') {
                    multiplicationLettre *= 3;
                    plateau[ligne + i][icolonne].multiplicateur = ' ';
                }
            } else {
                if (plateau[ligne][icolonne + i].multiplicateur == '&') {
                    multiplicationLettre *= 2;
                    plateau[ligne][icolonne + i].multiplicateur = ' ';
                }
                if (plateau[ligne][icolonne + i].multiplicateur == '%') {
                    multiplicationLettre *= 3;
                    plateau[ligne][icolonne + i].multiplicateur = ' ';
                }

            }
            score += multiplicationLettre;
        }
        score *= multiplicationMot;
        joueur1->score += score;
    }


void saisirMot(casePlateau plateau[LIGNES][COLONNES], int* premierCoup, joueur *joueur1,joueur *joueurConteste) {
    char mot[MAX_LETTRES];
    char position;
    short milieu=0, horsChamp=1, lettreenCommun=0, superposition=1, ecrase=1;
    int contest=1;
    int ligne = 0, i, nbSimilaireLettreMotPlateau=0;
    char colonne;
    int icolonne;
    char ChevaletMemoire[MAX_CHEVALET], motMemoire[MAX_LETTRES];
    int nbSimilaireLettreMotChevalet=0;
    strcpy(ChevaletMemoire, joueur1->chevalet);
    while(contest != 0 ) {
        ecrase=0;
        strcpy(joueur1->chevalet, ChevaletMemoire);
        while (milieu == 0 || horsChamp == 0 || lettreenCommun == 0 || superposition == 0 || strlen(mot) < 2 || ecrase == 0) {
            printf("Votre chevalet:%s\n", joueur1->chevalet);
            milieu = 0;
            horsChamp = 1;
            lettreenCommun = 0;
            superposition = 1;
            ecrase = 1;
            contest = 1;
            if (*premierCoup == 1) {
                milieu = 1;
            }
            nbSimilaireLettreMotPlateau = 0;
            nbSimilaireLettreMotChevalet = 0;
            printf("Veuillez saisir votre mot.\n");
            fflush(stdin);
            scanf(" %s", mot);
            printf("Colonne:\n");
            fflush(stdin);
            scanf(" %c", &colonne);
            printf("Ligne:\n");
            fflush(stdin);
            scanf(" %d", &ligne);
            ligne--;
            icolonne = (int) colonne - 65;
            printf("Voulez-vous placer le mot a la verticale (taper V)? ou a l'horizontal (taper H)?\n");
            fflush(stdin);
            scanf("%c", &position);
            strcpy(ChevaletMemoire, joueur1->chevalet);
            strcpy(motMemoire, mot);


            if (position == 'V') {
                for (i = 0; i < strlen(mot); i++) {
                    if(icolonne==0||icolonne==14){
                        if (icolonne==0){
                            if (plateau[ligne + i][1].lettre != ' '){

                            }
                        } else{
                            if (plateau[ligne + i][13].lettre != ' '){
                                superposition=2;

                            }
                        }
                    }else
                    {if ((plateau[ligne + i][icolonne + 1].lettre == ' ' && plateau[ligne + i][icolonne - 1].lettre != ' ') ||
                         (plateau[ligne + i][icolonne + 1].lettre != ' ' && plateau[ligne + i][icolonne - 1].lettre == ' ')) {
                            superposition = 2;

                        }
                    }
                    if (*premierCoup == 0) {
                        if (plateau[ligne + i][icolonne].multiplicateur == 35) {
                            milieu = 1;
                        }
                    }
                    if (plateau[ligne + i][icolonne].lettre == mot[i]) {
                        nbSimilaireLettreMotPlateau++;
                    } else {
                        if (plateau[ligne + i][icolonne].lettre != ' ') {
                            ecrase = 0;
                        }
                        for (int k = 0; k < strlen(joueur1->chevalet); ++k) {
                            if (joueur1->chevalet[k] == mot[i]) {
                                joueur1->chevalet[k] = '.';
                                mot[i] = '+';
                                nbSimilaireLettreMotChevalet++;
                            }
                        }
                    }
                    if (ligne + i > 14 || ligne + i < 0 || icolonne < 0 || icolonne > 14) {
                        horsChamp = 0;
                    }
                }
            } else {
                for (i = 0; i < strlen(mot); i++) {
                    if(ligne==0||ligne==14){
                        if (ligne==0){
                            if (plateau[ligne + 1][icolonne + i].lettre != ' '){
                                superposition=2;
                            }
                        } else{
                            if (plateau[ligne - 1][icolonne + i].lettre != ' '){
                                superposition=2;
                            }
                        }
                    }else
                    {if ((plateau[ligne + 1][icolonne + i].lettre == ' ' && plateau[ligne - 1][icolonne + i].lettre != ' ') ||
                         (plateau[ligne + 1][icolonne + i].lettre != ' ' && plateau[ligne - 1][icolonne + i].lettre == ' ')) {
                            superposition = 2;
                        }
                    }
                    if (plateau[ligne][icolonne + i].lettre == mot[i]) {
                        nbSimilaireLettreMotPlateau++;
                    } else {
                        if (plateau[ligne][icolonne + i].lettre != ' ') {
                            ecrase = 0;
                        }
                        for (int k = 0; k < strlen(joueur1->chevalet); k++) {
                            if (joueur1->chevalet[k] == mot[i]) {
                                joueur1->chevalet[k] = '.';
                                mot[i] = '+';
                                nbSimilaireLettreMotChevalet++;
                            }
                        }
                    }
                    if (*premierCoup == 0) {
                        if (plateau[ligne][icolonne + i].multiplicateur == 35) {
                            milieu = 1;
                        }
                    }
                    if (ligne > 14 || ligne < 0 || icolonne + i < 0 || icolonne + i > 14) {
                        horsChamp = 0;
                    }

                }
            }
            strcpy(mot, motMemoire);
            if (*premierCoup == 1) {
                if (nbSimilaireLettreMotPlateau < 1) {
                    superposition--;
                }
            }
            if (nbSimilaireLettreMotChevalet + nbSimilaireLettreMotPlateau == strlen(mot)) {
                lettreenCommun = 1;
            }
            if (milieu == 0) {
                strcpy(joueur1->chevalet, ChevaletMemoire);
                printf("Veuillez placer le mot au milieu.\n");
            }
            if (strlen(mot) < 2) {
                strcpy(joueur1->chevalet, ChevaletMemoire);
                printf("Votre mot est trop petit.\n");
            }
            if (ecrase != 1 || horsChamp == 0 || lettreenCommun != 1 || superposition == 0) {
                strcpy(joueur1->chevalet, ChevaletMemoire);
                printf("Votre mot est soit mal place, soit vous ne possedez pas les lettres.\n");
            }
        }
        contest = contestation(joueur1, joueurConteste, contest);
    }

    if (position == 'V') {
        for (i = 0; i < strlen(mot); i++) {
            plateau[ligne + i][icolonne].lettre = mot[i];
        }
    } else {
        for (i = 0; i < strlen(mot); i++) {
            plateau[ligne][icolonne+i].lettre = mot[i];
        }
    }
    calculScore(mot,plateau,joueur1,position,ligne,icolonne);
    if (strcmp(joueur1->chevalet,".......")==0){
        printf("BRAVO VOUS A SCRABBLE\n");
        joueur1->score+=50;
    }
    *premierCoup=1;
    printf("Votre nouveau score est de:%d\n\n", joueur1->score);
}

