#include "fonctions.h"
#define HAUTEUR = 6
#define LARGEUR = 7

int main(){
    char** grille = creerGrille(HAUTEUR, LARGEUR);
    Joueur* tblJoueur = creerTblJoueurs();
    Joueur gagnant;
    int nJoueur = quiCommence();

    do{
        afficherGrille(grille);
        jouer(tblJoueur[nJoueur], grille);
        gagnant = quiAGagne(grille, tblJoueur);
        nJoueur = !nJoueur;
    } while (!gagnant.existe);
    
    printf("Bravo %s, tu as gagné !", gagnant.prenom);
    return 0;
}