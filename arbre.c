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

/*
Arbre_t CreationArbre(char ** listeArbre, int taille)
{
	//noeud i ===  [arbre[i][0],arbre[i][1],arbre[i][2]] === [pere,fils,frere]
	
	int i;
	Arbre_t arbre = NULL; // arbre à retourner
	Noeud_t * cour = NULL; //pointeur qui contient le dernier noeud traiter pour chainer

	Noeud_t * pere = NULL, * fils = NULL, * frere = NULL;
	pere = InitNoeud(listeArbre[0][0]);
	fils = InitNoeud(listeArbre[0][1]);
	frere = InitNoeud(listeArbre[0][2]);
	
	AjoutVerticale(pere, fils);
	AjoutHorizontale(pere, frere);
	
	arbre = pere;
	cour = pere;
	
	free(pere);
	free(fils);
	free(frere);
	
	
	
	
	for (i=1;i<taille;i++) // i = 0 déjà traiter pour la racine de l'arbre
	{
		Noeud_t * pere = NULL, * fils = NULL, * frere = NULL;
		pere = InitNoeud(listeArbre[i][0]);
		fils = InitNoeud(listeArbre[i][1]);
		frere = InitNoeud(listeArbre[i][2]);
		
		AjoutVerticale(pere, fils);
		AjoutHorizontale(pere, frere);
				
		free(pere);
		free(fils);
		free(frere);
	}
}
*/
