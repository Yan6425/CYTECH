#include <stdio.h>

void espaces(int i, int taille){
    for (int j = 1; j < taille - i; j++){
        printf(" ");
    }
}

void asterix(int i){
    for (int j = 0; j < i * 2 + 1; j ++){
        printf("*");
    }
}

void losange(){
    int taille;

    scanf("%d", &taille);

    for (int i = 0; i < taille; i++){
        espaces(i, taille);
        asterix(i);
        printf("\n");
    }
    for (int i = taille; i > 0; i--){
        espaces(i, taille);
        asterix(i);
        printf("\n");
    }
}

int main(void){
    losange();
}