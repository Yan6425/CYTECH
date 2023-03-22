#include <stdio.h>
#include <stdlib.h>
#define TAILLE 10


int* remplirSousTbls(int taille, int* tbl, int* plusPetit, int* plusGrand){
    int* taillesSousTbls = malloc(2 * sizeof(int));
    taillesSousTbls[0] = 0;
    taillesSousTbls[1] = 0;
    int pivot = tbl[0];

    for (int i = 1; i < taille; i++){
        if (pivot > tbl[i]){
            plusPetit[taillesSousTbls[0]] = tbl[i];
            taillesSousTbls[0]++;
        }
        else {
            plusGrand[taillesSousTbls[1]] = tbl[i];
            taillesSousTbls[1]++;
        }
    }
    plusPetit[taillesSousTbls[0]] = pivot;
    taillesSousTbls[0]++;

    return taillesSousTbls;
}


void concatener(int* tbl, int taillePlusPetit, int* plusPetit, int taillePlusGrand, int* plusGrand){
    for (int i = 0; i < taillePlusPetit; i++){
        tbl[i] = plusPetit[i];
    }

    for (int i = 0; i < taillePlusGrand; i++){
        tbl[i + taillePlusPetit] = plusGrand[i];
    }
}


void triRapide(int taille, int* tbl){
    if (taille > 1){
        int* plusPetit = malloc(taille * sizeof(int));
        int* plusGrand = malloc(taille * sizeof(int));

        int* taillesSousTbls = remplirSousTbls(taille, tbl, plusPetit, plusGrand);
        int taillePlusPetit = taillesSousTbls[0];
        int taillePlusGrand = taillesSousTbls[1];

        triRapide(taillePlusGrand, plusGrand);
        triRapide(taillePlusPetit, plusPetit);

        concatener(tbl, taillePlusPetit, plusPetit, taillePlusGrand, plusGrand);
        
        free(plusPetit);
        free(plusGrand);
    }
}


void afficher(int taille, int* tbl){
    for (int i = 0; i < taille; i++){
        printf("%d ", tbl[i]);
    }
    printf("\n");
}


int main(){
    int* tbl = malloc(TAILLE * sizeof(int));
    int nombres[TAILLE] = {4, 9, 0, 8, 1, 6, 2, 3, 7, 5};
    for (int i = 0; i < TAILLE; i++){
        tbl[i] = nombres[i];
    }

    afficher(TAILLE, tbl);

    triRapide(TAILLE, tbl);

    afficher(TAILLE, tbl);

    return 0;
}