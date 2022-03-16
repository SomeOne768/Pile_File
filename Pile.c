

#include "Pile.h"

//creation int -> T

T CreerObjet(int val)
{
	T objet = malloc(sizeof(T));
	T.element = val;
	return objet;
}

//création maillon

maillon* CreationMaillon(T elt)
{
	maillon * m = (maillon*)malloc(sizeof(maillon));
	m.valeur = elt;
	m.suivant = NULL;
	return m;
}

//création pile

pile_t CreationPile()
{
	pile_t P;
	P.tete = NULL;
	return P;
}
// verif Vide
int EstVidePile(pile P)
{
	int verif = 0;
	if (!(P.tete))
	{
		verif=1;
	}
	return verif;
}
// empiler
int Empiler(pile_t * P,T objet)
{
	maillon * m  = CreationMaillon(objet);
	int inssertionreussie = 0;
	if (m)
	{	
		m->suivant = P->tete;
		P->tete = m;

	}
	else
	{
		inssertionreussie = 1;
	}
	return inssertionreussie;
}

//depiler
T Depiler(pile_t * P)
{
	T objet=0;
	if(EstVideFile(P))
	{
		maillon * m = P->tete;
		objet = m->element;
		P->tete = m->suivant;
		free(m);
	}
	else
	{
		printf("La pile est Vide")
	}
	return T;
}