 #include <stdio.h>
 #include <string.h>
 
 int main (void) {
	char saisie[50];
	char verif[50];
	int nb;
	do {
		printf("Entrez un nombre : ");
		scanf("%s", saisie);
		printf("%s", saisie);
		nb = strtoimax(saisie);
		sprintf(verif, "%d", nb);
	} while (!strcmp(saisie, verif));
	printf("Votre nombre est %d.\n", nb);
	return 0;
 }
