#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Joueur {
    char prenom[30];
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


int comparerPrenoms(char prenom1[30], char prenom2[30]){
    int res;
    int nCh1;
    int nCh2;
    for (int i = 0; i < 30; i++){
        nCh1 = (int)prenom1[i];
        nCh2 = (int)prenom2[i];
        if ((int)'A' <= nCh1 && nCh1 <= (int)'Z'){
            nCh1 += 32; 
        }
        if ((int)'A' <= nCh2 && nCh2 <= (int)'Z'){
            nCh2 += 32; 
        }
        if (nCh1 < (int)'a' || nCh1 > (int)'z' || nCh2 < (int)'a' || nCh2 > (int)'z'){
            res = nCh2 < (int)'a' || nCh2 > (int)'z';
            break;
        }
        if (nCh1 != nCh2){
            res = nCh1 > nCh2;
            break;
        }
    }
    return res;
}


int quiChoisi(Joueur joueur1, Joueur joueur2){
    int res;
    if (joueur1.age == joueur2.age){
        if (joueur1.prenom == joueur2.prenom){
            res = rand() % 2;
        }
        else {
            res = comparerPrenoms(joueur1.prenom, joueur2.prenom);
        }
    }
    else{
        res = joueur1.age > joueur2.age;
    }
    return res;
}


void choixSymbole(Joueur tblJoueur[2], int nJoueur){
    char choix;
    char symboles[2] = {'X', 'O'};

    do{
        printf("%s veux-tu jouer les X ou les O ?", tblJoueur[nJoueur].prenom);
        scanf("%c", &choix);
    } while(choix != 'X' && choix != 'O');
    tblJoueur[nJoueur].symbole = choix;
    tblJoueur[!nJoueur].symbole = symboles[choix == 'X'];
}


void afficherGrille(char grille[3][3]){
    for (int i = 0; i < 3; i++){
        printf("%d", i);
        for (int j = 0; j < 3; j++){
            printf("|%c", grille[i][j]);
        }
        printf("|\n");
    }
    printf("  1 2 3\n\n");
}


void jouer(Joueur joueur,char grille[3][3]){
    int choixX;
    int choixY;
    do{
        printf("%s saisie la case sur laquelle tu veux jouer : ", joueur.prenom);
        scanf("%d", &choixX);
        scanf("%d", &choixY);
    } while (choixX < 1 || 3 < choixX || choixY < 1 || 3 < choixY);
    grille[choixX - 1][choixY - 1] = joueur.symbole;
}


int lignes(char symbole, char grille[3][3]){
    int res;
    for (int i = 0; i < 3; i++){
        res = 1;
        for (int j = 0; j < 3; j++){
            res *= grille[i][j] == symbole;
        }
        if (res){
            break;
        }
    }
    return res;
}


int colonnes(char symbole, char grille[3][3]){
    int res;
    for (int i = 0; i < 3; i++){
        res = 1;
        for (int j = 0; j < 3; j++){
            res *= grille[j][i] == symbole;
        }
        if (res){
            break;
        }
    }
    return res;
}


int diags(char symbole, char grille[3][3]){
    int res;
    for (int i = 0; i < 2; i++){
        res = 1;
        for (int j = 3 * i; j < 3 * !i; j = j - 1 + 2 * i){
            res *= grille[j][j] == symbole;
        }
        if (res){
            break;
        }
    }
    return res;
}


Joueur quiAGagne(char grille[3][3], Joueur joueur1, Joueur joueur2){
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


int main(){
    Joueur tblJoueur[2] = {creerJoueur(1), creerJoueur(2)};
    Joueur gagnant;
    char grille[3][3] = {"   ", "   ", "   "};
    srand(time(NULL));

    nJoueur = quiChoisi(tblJoueur[0], tblJoueur[1]);
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