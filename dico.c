/*
 * Module contenant la fonction de lecture du fichier contenant les mots 
 */


#include "dico.h"

int ChargerMots(Arbre_t * pt_arbre)
{
	int code = 0;
	char mot[30];
	FILE * fichier = NULL;
	fichier = fopen("mots.txt", "r");
	
	if (fichier==NULL)
	{
		printf("probleme d'ouverture du fichier mots\n");
		code = -1;
	}
	else
	{
		fgets(mot,30,fichier);
		mot[strlen(mot)-1] = 0;
		while(!feof(fichier))
		{
			printf("mot == %s\n", mot);
			Insertion(pt_arbre,mot);
			fgets(mot,30,fichier);
			mot[strlen(mot)-1] = 0;
		}
	}
	fclose(fichier);
	
	return code;
}
