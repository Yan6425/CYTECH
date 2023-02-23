#include <stdio.h>
#include <stdlib.h>


int** allouerTableau(int nb_lignes,int nb_colonnes){
    int** espMem;
    
    espMem = malloc(nb_lignes * sizeof(int*));
    for (int i =0; i < nb_lignes; i++){
        espMem[i] = malloc(nb_colonnes * sizeof(int));
    }

    return espMem;
}


void remplirTab(int** tab){
    for (int i = 0; i < (sizeof(tab) / sizeof(int*)); i++){
        for (int j = 0; j < sizeof(tab[i]) / sizeof(int); j++){
            tab[i][j] = j;
        }
    }
}


void afficherTab(int** tab){
    for (int i = 0; i < (sizeof(tab) / sizeof(int*)); i++){
        for (int j = 0; j < sizeof(tab[i]) / sizeof(int); j++){
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int nb_lignes = 3;
    int nb_colonnes = 4;
    int** tab;

    tab = allouerTableau(nb_lignes, nb_colonnes);
    remplirTab(tab);
    afficherTab(tab);

    return 0;
}