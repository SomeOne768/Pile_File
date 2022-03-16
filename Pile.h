#ifndef PILE_H
#define PILE_H

//création du type générique

typedef struct type_générique
{
	int element;
}T;

typedef struct Maillon
{
	T valeur;
	struct maillon * suivant
}maillon_t;

typedef struct Pile
{
	maillon * tete;
}pile_t;

#endif
