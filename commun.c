#include <stdio.h>
#include "commun.h"

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
};


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