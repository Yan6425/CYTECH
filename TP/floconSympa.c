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

void sapin(){
    int taille;

    printf("Entrez la taille de votre sapin sympa !\n");
    scanf("%d", &taille);
    
    for (int i = 0; i < taille; i++){
        espaces(i, taille);
        asterix(i);
        printf("\n");
    }
    for (int i = 0; i < 2; i ++){
        espaces(0, taille);
        printf("@\n");
    }
}

int main(void){
    sapin();
}