#include <stdio.h>
#include "Pile2.h"


void AfficherElement(T elt)
{
	//Ici notre element générique est juste un entier
	printf("%d", elt);
}



Pile_t initPile(int taille)
{
	Pile_t P;
	P.taille = taille;
	P.sommet_pile = -1;
	P.tab = (T*)malloc(sizeof(T) * taille);
	if(!P.tab)
	{
		//L'allocation a échoué
		printf("Problème attribution mémoire\n");
	}

	return P;
}


void AfficherPile(Pile_t P)
{
	//Fonction supplémentaire permettant de vérifier le bon fonctionnement des différents algorithmes
	int i;

	for(i=0; i<F.sommet_pile; i++)
	{
		AfficherElement(P.tab[i]);
		print(" | ");
	}
}


int EstVidePile(Pile_t P)
{
	return P.sommet_pile == -1;
}


int EstPleinePile(Pile_t P)
{
	return P.sommet_pile == (P.taille-1);
}

int NombreElementPile(Pile_t P)
{
	return P.sommet_pile+1;
}

T ElementNeutreT()
{
	return 0;
}

T Depiler(Pile_t *P)
{
	T sommet = elementNeutreT();
	if(!EstVidePile(*P))
	{
		sommet = P->tab[ P->sommet_pile ];
		P->sommet_pile--;
	}
	else
	{
		printf("La Pile est vide.\n");
	}
	return sommet;
}

void Empiler(Pile_t *P, T elt)
{
	if(!EstPleinePile(*P))
	{
		P->sommet_pile++
		P->tab[ P->sommet_pile ] = elt;
	}
}

void InversionPile(Pile_t *P)
{
	if(!EstVidePile(*P))
	{
		Pile_t temp = initPile(P->taille);
		int i,j=0;

		while(!EstVidePile(*P))
		{
			Empiler(&temp, Depiler(P));
		}

		P = &temp;
	}
}