#include "fonctions.h"


char** creerGrille(int hauteur, int largeur){
    char** grille = malloc(hauteur * sizeof(char*));
    
    for (int i = 0; i < hauteur; i++){
        grille[i] = malloc(largeur * sizeof(char));
        for (int j = 0; j < largeur; j++){
            grille[i][j] = ' ';
        }  
    }
  
  return grille;
}
=====


typedef struct Joueur {
    char* prenom;
    int age;
    int existe;
    char symbole;
} Joueur;


Joueur creerJoueur(int nJoueur){
    Joueur joueur;
    char symboles[2] = {'X', 'O'};
    
    printf("Joueur %d saisie ton prénom : ", nJoueur);
    scanf("%s", joueur.prenom);
    printf("Saisie ton âge : ");
    scanf("%d", &joueur.age);
    joueur.existe = 1;
    joueur.symbole = symboles[nJoueur - 1];
    
    return joueur;
}


Joueur* creerTblJoueurs(){
    Joueur* tblJoueurs = malloc(2 * sizeof(Joueur));

    for (int i = 0; i < 2; i++){
        tblJoueurs[i] = creerJoueur(i + 1);
    }
  
    return tblJoueurs;  
}


void afficherGrille(char** grille){
    for (int i = HAUTEUR - 1; i >= 0; i--){
        for (int j = 0; j < LARGEUR; j++){
            printf("|%c", grille[i][j]);
        }
        printf("|\n");
    }
    for (int i = 1; i <= LARGEUR; i++){
        printf(" %d", i);
    }
    printf("\n\n");
}


void jouer(Joueur joueur, char** grille){
    int choixX;
    int choixY;

    do{
        fflush(stdin);
        printf("%s saisie les coordonnées de la case sur laquelle tu veux jouer :\n", joueur.prenom);
        scanf("%d", &choixX);
        scanf("%d", &choixY);
    } while (choixX < 1 || 3 < choixX || choixY < 1 || 3 < choixY);
    grille[choixX - 1][choixY - 1] = joueur.symbole;
    printf("essaie 1");
}


int lignes(char symbole, char** grille){
    int res;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            res = grille[i][j] == symbole;
        }
    }
    return res;
}


int colonnes(char symbole, char** grille){
    int res;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            res = grille[j][i] == symbole;
        }
    }
    return res;
}


int diags(char symbole, char** grille){
    int res;

    for (int i = 0; i < 2; i++){
        for (int j = 3 * i; j < 3 * !i; j = j - 1 + 2 * i){
            res = grille[j][j] == symbole;
        }
    }
    return res;
}


Joueur quiAGagne(char** grille, Joueur joueur1, Joueur joueur2){
    Joueur gagnant;

    if (lignes(joueur1.symbole, grille) || colonnes(joueur1.symbole, grille) || diags(joueur1.symbole, grille)){
        gagnant = joueur1;
    }
    else if (lignes(joueur2.symbole, grille) || colonnes(joueur2.symbole, grille) || diags(joueur2.symbole, grille)){
        gagnant = joueur2;
    }
    else{
        gagnant.existe = 0;
    }

    return gagnant;
}