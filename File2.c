#include <stdio.h>
#include "File2.h"


typedef struct{
	int nbElt;
	int taille;
	int indice_debut;
	int indice_fin;
	T tab[TAILLE_MAX];

}File_t;


/* -------------------------------------------------------------------- */
/* AfficherElement  Affiche un element générique				        */
/*                                                                      */
/* en entrée: rien                                                      */
/*                                                                      */
/* sortie: rien                                                         */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Récuperer un element générique en entrée et associé un affichage     */
/* correspondnat				                                        */
/* -------------------------------------------------------------------- */
void AfficherElement(T elt)
{
	printf("%d", elt);
}


/* -------------------------------------------------------------------- */
/* ElementNeutreT  Retourne ce qui correspond à un element neutre 		*/
/*                                                                      */
/* en entrée: rien                                                      */
/*                                                                      */
/* sortie: rien															*/
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Ici pour notre type générique on considère le 0 comme étant l'element*/
/* neutre 					                                            */
/* -------------------------------------------------------------------- */
T ElementNeutreT()
{
	//Si pointeur on retourne null, sinon on retourne une valeur qui correspond à une valeur neutre/impossible

	return 0;
}


/* -------------------------------------------------------------------- */
/* CreerFile  Creer et initialiser une File_t 					        */
/*                                                                      */
/* en entrée: rien                                                      */
/*                                                                      */
/* sortie: F, une File_t dont les champs sont initialisés à 0 sauf 		*/
/* la taille qui elle depend de la constante définie dans le .h 		*/
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Initialiser une file_t et la retourner								*/
/* -------------------------------------------------------------------- */
File_t CreerFile()
{
	File_t F;
	F.nbElt = 0;
	F.taille = TAILLE_MAX;
	F.indice_debut = 0;
	F.indice_fin = 0;

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
	if(!EstPleineFile(F))
	{
		F->tab[ F.indice_fin ] = elt;
		F->nbElt ++;
		F->indice_fin = (F->indice_fin+1) % F.taille;
		code_retour = 1;
	}
	return code_retour;
}

T Defiler(File_t *F)
{
	T = elementNeutreT();
	if(!EstVideFile(*F))
	{
		T = F->tab[ F->indice_fin ];
		F->indice_fin --;
		F->nbElt --;
		if(F->indice_fin < 0)
		{
			F->indice_fin = F->taille-1;
		}
	}
	else
	{
		printf("La file est vide, aucun element à récuperer.\n");
	}

	return T;
}

