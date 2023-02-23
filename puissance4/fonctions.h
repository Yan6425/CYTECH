#ifndef __puissance4_H_
#define __puissance4_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Joueur Joueur;
char** creerGrille(int hauteur, int largeur);
Joueur creerJoueur(int nJoueur);
Joueur* creerTblJoueurs();
int quiCommence();
void afficherGrille(char** grille);
void jouer(tblJoueur[nJoueur], grille);
Joueur quiAGagne(char** grille, Joueur* tblJoueur);

#endif