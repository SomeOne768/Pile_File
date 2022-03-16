#ifndef FILE_H
#define FILE_H


//Création de notre type générique

typedef struct type_generique{
	int element;
}T;


typedef struct maillon{
	T valeur;
	struct maillon *suivant;
}maillon_t;


typedef struct file
{
	maillon *tete;
	maillon *queue;
}file_t;


#endif