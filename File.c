

//Dans l'utilisation des fonction, *File est toujours une adresse qui référence une variable
//excistante réellement (passage via '&maFile')
//Le test NULL n'est donc pas nécessaire

//Création de la file

T CreerObjet(int val)
{
	T new_object;
	new_object.element = val;
	return new_object;
}

maillon* CreerMaillon(T objet)
{
	maillon *m = (maillon*)malloc(sizeof(maillon));
	m.valeur = objet;
	m.suivant = NULL;

	return m;
}


file_t CreationFile()
{
	file_t F;
	F.tete = NULL;
	F.queue = NULL;

	return F;
}


int EstVideFile(file_t File)
{
	return File.tete == NULL;
}


int Enfiler(file_t *File, T element)
{
	//Dans une file on ajoute toujours l'element à la fin


	//Code d'erreur
	int insertion_reussi = 0;

	//Création d'un nouveau maillon
	maillon *m = CreerMaillon(element);

	if(m)
	{
		//Allocation réussi
		if(EstVideFile(*File))
		{
			//Insertion en tête et en queue
			File->tete = m;
			File->tete = m;
		}
		else
		{
			//On insère seulement en queue
			//Il y a forcément un element en queue puisque la file n'est pas vide
			File->queue->suivant = m;
			File->queue = m;
		}
		insertion_reussi = 1;
	}
	else
	{
		//L'allocation a échoué
		printf("Problème allocation de mémoire\n");
	}

	return insertion_reussi;
}




T Defiler(file_t *File)
{
	T objet;
	maillon *m;

	if(EstVideFile(*File))
	{
		//On a aucun element
		objet.element = 0;
	}
	else
	{
		m = File->tete;
		objet = m->valeur;
		free(m);
		File->tete = File->tete->suivant;
		if(EstVideFile(*File))
		{
			//L'élément depiler était le seul et donc était aussi en queue
			File->queue = NULL;
		}
	}

	return objet;
}