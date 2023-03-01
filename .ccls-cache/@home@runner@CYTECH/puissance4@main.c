#include "fonctions.h"
<<<<<<< HEAD
=======
#define HAUTEUR = 6
#define LARGEUR = 7
>>>>>>> e5083f9d5aecceaef44d7858a472ff879df37ee2

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