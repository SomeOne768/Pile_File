/************************************/
/*	Version SDD cours 				*/
/************************************/

#include "commun.h" 
#ifndef PILE2_H
#define PILE2_H
#define TAILLE_MAX 100

typedef struct{
	int taille;
	int sommet_pile;
	T *tab;
}Pile_t;



void AfficherElement(T elt);
Pile_t initPile(int taille);
void AfficherPile(Pile_t F);
int EstVidePile(Pile_t F);
int EstPleinePile(Pile_t F);
int NombreElementPile(Pile_t P)
T ElementNeutreT();
T Depiler(Pile_t *P);
void Empiler(Pile_t *P, T elt)
void InversionPile(Pile_t *P)


#endif