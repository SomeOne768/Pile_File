/************************************/
/*	Version SDD cours 				*/
/************************************/

#ifndef PILE2_H
#define PILE2_H
#define TAILLE_MAX 100
#include "commun.h" 

typedef struct{
	int taille;
	int sommet_pile;
	T *tab;
}Pile_t;


Pile_t initPile(int taille);
void AfficherPile(Pile_t F);
int EstVidePile(Pile_t F);
int EstPleinePile(Pile_t F);
int NombreElementPile(Pile_t P);
T Depiler(Pile_t *P);
int Empiler(Pile_t *P, T elt);
void InversionPile(Pile_t *P);


#endif