#include <stdio.h>
#include <math.h>


int delta(double a, double b, double c){
    return pow(b, 2) - (4 * a * c);
}


void resoudre(double a, double b, double c, double racines[2]){
    racines[0] = (pow(b, 2) - sqrt(delta(a, b, c))) / (2 * a);
    racines[1] = (pow(b, 2) + sqrt(delta(a, b, c))) / (2 * a);
}


int main(){
    double a, b, c, racines[2];

    printf("Entrez les valeurs des 3 membres du polynome :\n");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    resoudre(a, b, c, racines);
    printf("%lf\n%lf\n", racines[0], racines[1]);

    return 0;
}