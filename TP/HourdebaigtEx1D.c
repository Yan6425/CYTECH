#include <stdio.h>

int main() {
    /*Déclaration variables*/
    int age;
    char nom[20], prenom[30];

    /*Programme*/
    do {
        printf("Entrez votre âge : ");
        scanf("%d", &age);
    } while (age > 128 || age < 0);
    printf("\nEntrez vos nom et prénom :\n");
    scanf("%s", nom);
    scanf("%s", prenom);
    printf("\nVoici ce que vous avez rentré :\nÂge : %d\nNom : %s\nPrénom : %s\n", age, nom, prenom);
}