#include <stdio.h>

int PGCD(int x, int y) {
    int tmp;

    while (y) {
        tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

int main() {
    int x, y;
    
    printf("Entrez les deux entiers :\n");
    scanf("%d", &x);
    scanf("%d", &y);
    printf("Le PGCD est %d.\n", PGCD(x, y));
    return 0;
}