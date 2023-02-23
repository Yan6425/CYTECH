#include <stdio.h>
#include "fonctions.h"
#define HAUTEUR = 6
#define LARGEUR = 7

int main(){
    char** grille = malloc(HAUTEUR * sizeof(char*));
    Joueur* tblJoueur = malloc(2 * sizeof(Joueur));
    tblJoueur[0] = creerJoueur(1);
    tblJoueur[1] = creerJoueur(2);
    Joueur gagnant;
    srand(time(NULL));
    int nJoueur = quiChoisi(tblJoueur[0], tblJoueur[1]);
    choixSymbole(tblJoueur, nJoueur);
    nJoueur = tblJoueur[0].symbole == 'O';

    do{
        afficherGrille(grille);
        jouer(tblJoueur[nJoueur], grille);
        gagnant = quiAGagne(grille, tblJoueur[0], tblJoueur[1]);
        nJoueur = !nJoueur;
    } while (!gagnant.existe);
    
    printf("Bravo %s, tu as gagné !", gagnant.prenom);
    return 0;
}