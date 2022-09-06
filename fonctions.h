#ifndef SCRABBLE_FONCTIONS_H
#define SCRABBLE_FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOM 30
#define MAX_CHEVALET 15
#define LIGNES 15
#define COLONNES 15
#define TAILLE_PIOCHE 102
#define MAX_LETTRES 15
#define NOMBRE_ECHANGE 1000

void initialiserPlateau();
void afficherPlateau();
void melanger();
//void calculScore();
void sauvegarder();
void saisirMot();
void saisirNom();
void saisirNombreJoueur();
void remplirChevalet();
void initialiserChevalet();
void choixJoueur();
void afficherAide();
void changerLettre();
void initial();
char piocher();

typedef struct {
    char lettre, multiplicateur;
} casePlateau;

typedef struct {
    char pseudo[MAX_NOM], chevalet[MAX_CHEVALET];
    int score;
} joueur;

#endif
