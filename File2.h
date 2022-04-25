/************************************/
/*	Version SDD cours 				*/
/************************************/



#ifndef FILE2_H
#define FILE2_H
#define TAILLE_MAX 100

typedef int T;

typedef struct{
	int nbElt;
	int taille;
	int indice_debut;
	int indice_fin;
	T tab[TAILLE_MAX];

}File_t;


void AfficherElement(T elt);
File_t CreerFile();
void AfficherFile(File_t F);
int EstVideFile(File_t F);
int EstPleineFile(File_t F);
int NombreElementFile(File_t F);
T ElementNeutreT();
T Defiler(File_t *F);


#endif