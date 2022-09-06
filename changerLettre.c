#include "fonctions.h"

void changerLettre (joueur *joueurEnCours, char* pioche){
    char lettreAChanger[MAX_CHEVALET];
    printf("Votre chevalet: %s\n", joueurEnCours->chevalet);

    printf("Veuillez ecrire les lettres que vous souhaitez changer (sous la forme ABCDEFG, maximum 7 lettres):\n");
    scanf("%s", lettreAChanger);

    for(int i =0; i <strlen(lettreAChanger); i++){
        for(int j = 0; j < strlen(joueurEnCours->chevalet); j++){
            if(lettreAChanger[i] == joueurEnCours->chevalet[j]){
                for(int k = 0; k < strlen(pioche); k++) {
                    if (pioche[k] == '\0') {
                        pioche[k] = lettreAChanger[i];
                    }
                }
                joueurEnCours->chevalet[j] = '.';
                lettreAChanger[i] = '+';
            }
        }
    }

    for(int i = 0; i < strlen(joueurEnCours->chevalet); i++){
        if(joueurEnCours->chevalet[i] == '.'){
            joueurEnCours->chevalet[i] = piocher(pioche);
        }
    }
    printf("Votre chevalet est desormais: %s\n", joueurEnCours->chevalet);
}