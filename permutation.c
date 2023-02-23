#include <stdio.h>

void cleVersOrdreColonnes(int tailleCle, char cle[tailleCle], int ordreColonnes[tailleCle]){
    int rang;
    for (int i = 0; i < tailleCle; i++){
        rang = 0;
        for (int j = 0; j < tailleCle; j++){
            if (cle[j] < cle[i] || (cle[j] == cle[i] && j < i)){
                rang++;
            }
        }
        ordreColonnes[rang] = i;
    }
}

void remplirTab(int tailleCle, char tab[tailleCle][tailleCle]){
    for (int i =0; i < tailleCle; i++){
        for (int j = 0; j < tailleCle; j++){
            tab[i][j] = ' ';
        }
    }
}

void crypter(int tailleCle, char cle[tailleCle], char phrase[tailleCle * tailleCle]){
    char tab[tailleCle][tailleCle];
    remplirTab(tailleCle, tab);

    for (int i = 0; i < tailleCle; i++){
        for (int j = 0; j < tailleCle; j++){
            tab[i][j] = phrase[i * tailleCle + j];
        }
    }
    
    int ordreColonnes[tailleCle];
    cleVersOrdreColonnes(tailleCle, cle, ordreColonnes);
    
    for (int i = 0; i < tailleCle; i++){
        for (int j = 0; j < tailleCle; j++){
            phrase[i * tailleCle + j] = tab[j][ordreColonnes[i]];
        }
    }
}

void deCrypter(int tailleCle, char cle[tailleCle], char phrase[tailleCle * tailleCle]){
    char tab[tailleCle][tailleCle];
    remplirTab(tailleCle, tab);

    int ordreColonnes[tailleCle];
    cleVersOrdreColonnes(tailleCle, cle, ordreColonnes);

    for (int i = 0; i < tailleCle; i++){
        for (int j = 0; j < tailleCle; j++){
            tab[j][ordreColonnes[i]] = phrase[i * tailleCle + j];
        }
    }
    
    for (int i = 0; i < tailleCle; i++){
        for (int j = 0; j < tailleCle; j++){
            phrase[i * tailleCle + j] = tab[i][j];
        }
    }
}

int main(){
    char cle[21] = "test ultime ma gueule";
    char phrase[21*21] = "Si ça marche whallah je suis content.";
    crypter(21, cle, phrase);
    printf("%s\n", phrase);
    deCrypter(21, cle, phrase);
    printf("%s\n", phrase);

    return 0;
}