#include <stdio.h>
#include "File2.h"
#include <stdlib.h>
#include <time.h>
#include "Pile2.h"

int main(){


	//Test des files:
	/*void AfficherElement(T elt);
	void AfficherFile(File_t F);
	int EstVideFile(File_t F);
	int EstPleineFile(File_t F);
	int NombreElementFile(File_t F);
	T ElementNeutreT();
	T Defiler(File_t *F);
	int Enfiler(File_t *F, T elt)
	*/	

	File_t F = InitFile(TAILLE_MAX);
	AfficherFile(F);
	printf("%d\n", EstVideFile(F));
	printf("%d\n", EstPleineFile(F));

	srand(time(NULL));
	int r = rand()%200;

	for(int i=0; i<r; i++)
	{
		if(!Enfiler(&F, i))
			printf("pb de place\n");
	}

	printf("%d\n", NombreElementFile(F));

	AfficherFile(F);

	while(!EstVideFile(F))
	{
		Defiler(&F);
	}


	//Test des piles:

	/*Pile_t initPile(int taille);
	void AfficherPile(Pile_t F);
	int EstVidePile(Pile_t F);
	int EstPleinePile(Pile_t F);
	int NombreElementPile(Pile_t P)
	T ElementNeutreT();
	T Depiler(Pile_t *P);
	void Empiler(Pile_t *P, T elt);
	void InversionPile(Pile_t *P);*/

	Pile_t P = initPile(TAILLE_MAX);
	AfficherPile(P);
	printf("%d\n", EstVidePile(P));
	printf("%d\n", EstPleinePile(P));

	srand(time(NULL));
	r = rand()%200;

	for(int i=0; i<r; i++)
	{
		if(!Empiler(&P, i))
			printf("pb de place\n");
	}

	printf("%d\n", NombreElementPile(P));

	AfficherPile(P);

	while(!EstVidePile(P))
	{
		Depiler(&P);
	}

	return 0;
}
