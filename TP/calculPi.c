#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


unsigned long long randCo(int precision) {
  return rand();
}


char calcDecimale(int precision) {
  char decimale;
  unsigned long long co;
  /*sprintf(decimales, "%llu", randCo(precision));*/

  co = randCo(precision);
  printf("co : %llu\n", co);
  decimale = (char)co;

  return decimale;
}


int calculer(int longueur, char pi[longueur], int precision) {
  int reussite = 1;
  printf("%s\n", pi);

  for (int i = 0; i < longueur; i++) {
    pi[i] = calcDecimale(precision);
    if (!isdigit(pi[i])) {
      reussite = 0;
    }
    precision *= 10;
  }
  
  return reussite;
}


int main(void){
  char pi[10];
  int longueur = 10;
  int precision = 10;

  srand(time(NULL));

  printf("%d\n", calculer(longueur, pi, precision));
  printf("%s\n", pi);
  
  return 0;
}

