#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Parametres(){
    int nbCouleurs, nbLignes, nbColonnes;
    char nomJoueur[];
}


void parametrer(struct Parametres parametres){
    printf("Comment t'appelles-tu ?\n");
    scanf("%s", parametres.nomJoueur);
    printf("Quelles dimensions veux-tu pour le plateau ? (4 * 10 conseillé, largeur max : 8)\nnombre de lignes : ");
    scanf("%d", &parametres.nbLignes);
    printf("nombre de colonnes : ");
    scanf("%d", &parametres.nbColonnes);
    printf("Combien de couleurs veux-tu ? (4 à 8, 6 conseillées) : ");
    scanf("%d", &parametres.nbCouleurs);
}


void remplirCouleurs(int nbCouleurs, int couleurs[nbCouleurs]){
    char couleursDipos[8] = {'R', 'V', 'B', 'J', 'O', 'M', 'N', 'G'};
    for (int i = 0; i < nbCouleurs; i++){
        couleurs[i] = couleursDipos[i];
    }
}


void creerCombinaison(int nbColonnes, int nbCouleurs, int couleurs[nbCouleurs], int solution[nbColonnes]){
    srand(time(NULL));
    for (int i = 0; i < nbColonnes; i++){
        solution[i] = couleurs[rand() % nbCouleurs];
    }
}


void remplirIndices(int nbLignes, int indices[nbLignes][2]){
    for (int i = 0; i < nbLignes; i++){
        for (int j = 0; j < nbLignes; j++){
            indices[i][j] = 0;
        }
    }
}


void afficher(int nbLignes, int nbColonnes, char plateau[nbLignes][nbColonnes], int indices[nbLignes][2]){
    for (int i = nbLignes - 1; i >= 0; i--){
        printf("%d", indices[i][0]);
        for (int j = 0; j < nbColonnes; j++){
            printf("|%c", plateau[i][j]);
        }
        printf("|%d\n", indices[i][1]);
    }
}


void jouer(int nbLignes, int nbColonnes, char plateau[nbLignes][nbColonnes], int compteur, int nbCouleurs,char couleurs){
    printf("Entre les 4 couleurs que tu souhaites dans l'ordre parmis les suivantes :\n");
    for (int i = 0; i < nbCouleurs, i++){
        printf();
    }
}


int main(){
    struct Parametres parametres;
    parametrer(parametres);
    char plateau[parametres.nbLignes][parametres.nbColonnes];
    char solution[parametres.nbColonnes];
    char couleurs[parametres.nbCouleurs];
    remplirCouleurs(parametres.nbCouleurs, couleurs);
    creerCombinaison(parametres.nbColonnes, parametres.nbCouleurs, couleurs, solution);
    int indices[parametres.nbLignes][2];
    remplirIndices(parametres.nbLignes, indices);
    
    int compteur = 0;
    printf("Le nombre de couleurs bien placées est affiché à gauche de la ligne et le nombre de couleurs mal placées est affiché à droite.\n\n")
    do {
        afficher(parametres.nbLignes, parametres.nbColonnes, plateau, indices);
        jouer(parametres.nbLignes, parametres.nbColonnes, plateau, compteur, couleurs, parametres.nbCouleurs);
        verifierCombinaison(plateau, compteur, solution);
        compteur++;
    } while (!partieFini(indices, compteur));
    
    feliciter(parametres.nomJoueur);

    return 0;
}