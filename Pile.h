#include "element_generique.h"
#ifndef PILE_H
#define PILE_H
 
// structure du maillon

typedef struct Maillon
{
	T valeur;
	struct maillon * suivant
}maillon_t;

// structure de la Pile
typedef struct Pile
{
	maillon * tete;
}pile_t;

#endif
