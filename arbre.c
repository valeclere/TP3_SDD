/* Module contenant les fonctions pour insérer les mots dans l'arbre*/

#include "arbre.h"

Noeud_t * InitNoeud(char lettre)
{
	Noeud_t * pt_Noeud = NULL;
	pt_Noeud =(Noeud_t*)malloc(sizeof(Noeud_t));
	
	if (pt_Noeud == NULL)
	{
		printf("Problème d'allocation !\n");
	}
	
	else
	{
		pt_Noeud->lettre=lettre;
		pt_Noeud->lv=NULL;
		pt_Noeud->lh=NULL;
	}
	
	return pt_Noeud;
}




void AjoutVerticale(Noeud_t * pere, Noeud_t * fils)
{
	if (pere->lv!=NULL)
	{
		printf("Attention fils déjà existant !\n");
	}
	
	else
	{
		pere->lv = fils;
	}
}
	


void AjoutHorizontale(Noeud_t * GrandFrere, Noeud_t * PetitFrere)
{
	if (GrandFrere->lh!=NULL)
	{
		printf("Attention frere déjà existant !\n");
	}
	
	else
	{
		GrandFrere->lh = PetitFrere;
	}
}











