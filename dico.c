/*
 * Module contenant la fonction de lecture du fichier contenant les mots 
 */


#include "dico.h"

void fgets2(char * mot, int n ,FILE * fichier)
{
	int i=0;
	fgets(mot,n,fichier);
	while (mot[i]!='\n') i++;
	mot[i]='\0';
}


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
		while(!feof(fichier))
		{
			fgets2(mot,30,fichier);
			Insertion(pt_arbre,mot);
		}
	}
	fclose(fichier);
	
	return code;
}
