#include <stdio.h>


void remplirMatrice(char matrice[27][27]){
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26 - i; j++){
            matrice[i][j] = 'A' + j + i;
        }
    }

    for (int i = 0; i < 27; i++){
        matrice[26 - i][i] = ' ';
    }

    for (int i = 26; i > 0; i--){
        for (int j = 26; j > (26 - i); j--){
            matrice[i][j] = 'A' + j - 27 + i;
        }
    }
}


void afficherMatrice(char matrice[27][27]){
    for (int i = 0; i < 27; i++){
        for (int j = 0; j < 27; j++){
            printf("%c", matrice[i][j]);
            if (j != 26){
                printf("|");
            }
        }
        printf("\n");
    }
}


int main(){
    char matrice[27][27];

    remplirMatrice(matrice);
    afficherMatrice(matrice);

    return 0;
}