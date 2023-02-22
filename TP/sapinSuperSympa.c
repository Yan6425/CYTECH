#include <stdio.h>            
#include <stdlib.h>        
#include <time.h>          


void espaces(int taille,
             int tailleArbre[2],
             char arbre[tailleArbre[0]][tailleArbre[1]],
             int nbEspacesTronc){
  for (int i = 0; i < tailleArbre[0]; i++){
    for (int j = 0; j < tailleArbre[1]; j++){
      arbre[i][j] = ' ';
    }
    arbre[i][tailleArbre[1] - 1] = '\0';
  }
}


void asterisques(int taille, 
                 int tailleArbre[2],
                 char arbre[tailleArbre[0]][tailleArbre[1]]){
  int nbEspaces;
  for (int i = 0; i < taille; i++){
    nbEspaces = taille - 1 - i;
    for (int j = nbEspaces; j < tailleArbre[1] - 1 - nbEspaces; j++){
      arbre[i][j] = '*';
    }
  }
}


void tronc(int taille,
           int tailleTronc[2],
           int nbEspacesTronc,
           int tailleArbre[2],
           char arbre[tailleArbre[0]][tailleArbre[1]]){
  for (int i = taille; i < tailleArbre[0]; i++){
    for (int j = nbEspacesTronc; j < nbEspacesTronc + tailleTronc[1]; j++){
      arbre[i][j] = '@';
    }
  }
}


void afficherArbre(int tailleArbre[2], char arbre[tailleArbre[0]][tailleArbre[1]]){
  for (int i = 0; i < tailleArbre[0]; i++){
    printf("%s\n", arbre[i]);
  }
}


void coordsPourBoules(int nbBoules, int boules[nbBoules][2], int taille){
  srand(time(NULL));
  for (int i = 0; i < nbBoules; i++){
    boules[i][0] = (rand() % 2 + 1) + i * 3;
    boules[i][1] = rand() % (boules[i][0] * 2) + taille - boules[i][0];
  }
}


void placerBoules(int tailleArbre[2], char arbre[tailleArbre[0]][tailleArbre[1]], int nbBoules, int boules[nbBoules][2]){
  char symboles[2] = {'/', '\\'};
  for (int i = 0; i < nbBoules; i++){
    for (int j = 0; j < 4; j++){
      arbre[boules[i][0] + (j / 2)][boules[i][1] + (j % 2)] = symboles[(j / 2) ^ (j % 2)];
    }
  }
}


void faireLeSapin(int taille){
  int tailleTronc[2] = {1 + taille / 5,
                        taille / 7 * 2 + 1};
  int nbEspacesTronc = taille - (tailleTronc[1] + 1) / 2;
  int tailleArbre[2] = {taille + tailleTronc[0],
                        taille * 2};
  char arbre[tailleArbre[0]][tailleArbre[1]];
  int nbBoules = (taille - 1) / 3;
  int boules[nbBoules][2];
  
  espaces(taille, tailleArbre, arbre, nbEspacesTronc);
  asterisques(taille, tailleArbre, arbre);
  tronc(taille, tailleTronc, nbEspacesTronc, tailleArbre, arbre);
  coordsPourBoules(nbBoules, boules, taille);
  placerBoules(tailleArbre, arbre, nbBoules, boules);
  afficherArbre(tailleArbre, arbre);
}


int main(void) {
  int taille;

  printf("Entrez la taille de votre sapin super sympa :\n");
  scanf("%d", &taille);
  faireLeSapin(taille);
  return 0;
}