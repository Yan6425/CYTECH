#include <stdio.h>

int estBissextile(int année) {return (!(année % 4) && (année % 100)) || !(année % 400);}

int dateValide(int mois, int jour, int tblMois[12]) {return 0 < mois && mois < 13 && 0 < jour && jour <= tblMois[mois - 1];}

int main() {
    int année, mois, jour, nJour;
    int tblMois[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    do {
        printf("Entrez la date :\nJour : ");
        scanf("%d", &jour);
        printf("Mois : ");
        scanf("%d", &mois);
        printf("Année : ");
        scanf("%d", &année);
        if (estBissextile(année)) {
            tblMois[1] = 29;
        }
    } while (!dateValide(mois, jour, tblMois));
    

    for (int i = 0; i < mois - 1; i++) {
        nJour += tblMois[i];
    }
    nJour += jour;

    printf("Le numéro du jour est %d.\n", nJour);

    return 0;
}