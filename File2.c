#include <stdio.h>
#include <stdlib.h>
#include "File2.h"
#include "commun.h" 

/* -------------------------------------------------------------------- */
/* InitFile  Creer et initialiser une File_t 					        */
/*                                                                      */
/* en entrée: rien                                                      */
/*                                                                      */
/* sortie: F, une File_t dont les champs sont initialisés à 0 sauf 		*/
/* la taille qui elle depend de la constante définie dans le .h 		*/
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Initialiser une file_t et la retourner								*/
/* -------------------------------------------------------------------- */
File_t InitFile(int taille)
{
	File_t F;
	F.nbElt = 0;
	F.taille = taille;
	F.indice_debut = 0;
	F.indice_fin = 0;
	F.tab = (T*)malloc(sizeof(T)*taille);
	
	return F;
}




/* -------------------------------------------------------------------- */
/* AfficherFile  Affiche tous les élements de notre file 		        */
/*                                                                      */
/* en entrée: une File_t                                                */
/*                                                                      */
/* sortie: rien                                                         */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Récuperer une File_t en entrée. Initialiser deux variables locale	*/
/* nombre initialisé avec le nomnbre d'element de la file et parcourir 	*/
/* initialisé avec indice de debut de la file. A l'aide de ces dernieres*/
/* on parcourt la liste à l'aide d'une boucle dans laquelle on decremente*/
/* nombre et on incremente parcourir en verifiant que parcourir soit 	*/
/* toujours un indice valable de notre tableau jusqu'a que nombre =0 	*/
/* Pour chaque element parcourut, on l'affiche 							*/
/* -------------------------------------------------------------------- */

void AfficherFile(File_t F)
{
	int parcourir = F.indice_debut;
	int nombre = F.nbElt;
	while(nombre != 0)
	{
		nombre--;
		AfficherElement(F.tab[parcourir]);
		if(!(nombre%10))
		{
			printf("\n");
		}
		else
		{
			printf(" | ");
		}
		parcourir = (parcourir+1) % F.taille;
	}
}

/* -------------------------------------------------------------------- */
/* EstVideFile  Indique si une File est vide 					        */
/*                                                                      */
/* en entrée: une File_t	                                            */
/*                                                                      */
/* sortie: un entier qui vaut 1 si la file est vide 0 sinon 			*/
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Retourner un boolean qui retourne vrai si le nombre d'element est 0  */
/* -------------------------------------------------------------------- */
int EstVideFile(File_t F)
{
	return F.nbElt == 0;
}

int EstPleineFile(File_t F)
{
	return F.nbElt == F.taille;
}

int NombreElementFile(File_t F)
{
	return F.nbElt;
}


//Fonction qui enfile l'element elt 
int Enfiler(File_t *F, T elt)
{
	//FIFO <=> LILO
	int code_retour = 0;
	if(!EstPleineFile(*F))
	{
		F->tab[ F->indice_fin ] = elt;
		F->nbElt ++;
		F->indice_fin = (F->indice_fin+1) % F->taille;
		code_retour = 1;
	}
	return code_retour;
}

T Defiler(File_t *F)
{
	T tete = ElementNeutreT();
	if(!EstVideFile(*F))
	{
		tete = F->tab[ F->indice_debut ];
		F->indice_debut ++;
		F->nbElt --;
		if(F->indice_debut >= F->taille)
		{
			F->indice_debut = 0;
		}
	}
	else
	{
		printf("La file est vide, aucun element à récuperer.\n");
	}

	return tete;
}

