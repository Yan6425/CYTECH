#include <stdio.h>

int armstrong(int nb) {
    int res = 0;
    int chiffre;

    for (int pDe10 = 1; pDe10 < 1000; pDe10 *= 10) {
        chiffre = (nb / pDe10) % 10;
        res += chiffre * chiffre * chiffre;
    }

    return res == nb;
}


int main() {
    for (int nb = 100; nb < 1000; nb++) {
        if (armstrong(nb)){
            printf("%d\n", nb);
        }
    }

    return 0;
}