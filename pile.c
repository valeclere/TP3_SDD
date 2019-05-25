#include "pile.h"


/* ----PRESENTATION DU MODULE---- */

/* ------------------------------------------------------------------------------------------------------------ */
/*  Module Pile : permet de gérer la structure pile pour tout type de variable                                  */
/*                                                                                                              */
/*  Structure :                                                                                                 */
/*  	-pile est la structure contenant les infos sur le tableau (taille, nb d'éléments, pointeur sur le tab)  */
/*  	-tableau est la structure contenant les element_t à empiler ou dépiler                                  */
/*  	-element_t est le type de variables présentes dans le tableau                                           */
/*                                                                                                              */
/*  Fonctions :                                                                                                 */
/*  	-initPile                                                                                               */
/*  	-empiler                                                                                                */
/*  	-depiler                                                                                                */
/*  	-estVide                                                                                                */
/*  	-libererPile                                                                                            */
/* ------------------------------------------------------------------------------------------------------------ */




/* ----FONCTIONS DU MODULE---- */

/* ----------------------------------------------------------------------------------------------------------- */
/*  initPile : créer une structure pile au format suivant:                                                     */
/*                                                                                                             */
/*                                                                                                             */
/*  En entrée :                                                                                                */
/*  	-taille = entier correspondant à la taille du tableau contenant les éléments                           */
/*                                                                                                             */
/*  En sortie :                                                                                                */
/*  	-pt_pile = pointeur sur la structure pile créée                                                        */
/* ----------------------------------------------------------------------------------------------------------- */

Pile_t * initPile(int taille)
{
	Pile_t    * pt_pile = NULL; /* pointeur sur la pile */
	element_t * pt_tab = NULL; /* pointeur sur le tableau */
	
	pt_pile = (Pile_t*)malloc(sizeof(Pile_t)); 
	
	 
	if (pt_pile == NULL) /* si l'allocation de la pile échoue */
	{
		printf("problème d'allocation de la pile");
		exit(1); /* sortie immédiate du code en cas de problème d'allocation */
	}
	
	pt_tab = (element_t*)malloc(taille*sizeof(element_t));
	
	if (pt_tab == NULL)  /* si l'allocation du tableau échoue */
	{
		printf("problème d'allocation du tableau");
		free(pt_pile);
		exit(1);
	}
	
	pt_pile->taille = taille; /* la taille du tableau est placé dans la pile */
	pt_pile->nb_elt = 0; /* mise à zéro du nombre d'éléments présent dans la pile| */
	pt_pile->pt_tab = pt_tab; /* l'adresse du tableau est placé dans la pile */

	
	return pt_pile;
}




/* ---------------------------------------------------------------------- */
/*  empiler : ajouter l'élément d'entrée après le dernier élément rentré  */
/*                                                                        */
/*  Entrée :                                                              */
/*  -pt_pile = pointeur sur la pile                                       */
/*  -element = valeur à empiler dans le tableau                           */
/*  -err = code erreur : vaut 0 quand il y a une erreur, 1 sinon          */
/*                                                                        */                                                               
/*  Pas de sortie                                                         */
/* ---------------------------------------------------------------------- */

void empiler(Pile_t * pt_pile, element_t element, int * err)
{
	*err=0;
	element_t * pt_tab = pt_pile->pt_tab; /* récuperer le tableau dans la fonction */
	int nb_elt = pt_pile->nb_elt;
	int taille = pt_pile->taille;
	
	if(nb_elt<taille)
	{	
	*(pt_tab+nb_elt) = element;
	pt_pile->nb_elt = nb_elt + 1;
	*err=1; /* s'il n'y a pas eu d'erreur err=1 */
	}
}




/* ------------------------------------------------------------ */
/*  depiler : retirer le dernier élément rentré dans le tableau */
/*                                                              */
/*  Entrée :                                                    */
/*  	-pt_pile = pointeur sur la pile                         */
/*  -err = code erreur : vaut 0 s'il y a une erreur, 1 sinon    */ 
/*                                                              */
/*  Sortie :                                                    */
/*  	-element = élément retiré                               */
/* ------------------------------------------------------------ */

element_t depiler(Pile_t * pt_pile, int * err)
{
	*err = 0;
	element_t * pt_tab = pt_pile->pt_tab; /* récuperer le tableau dans la fonction */
	int nb_elt = pt_pile->nb_elt;
	element_t element = 0;
	
	if(!estVide(pt_pile))
	{ 
	element = *(pt_tab+nb_elt-1);
	*(pt_tab+nb_elt-1) = 0;
	pt_pile->nb_elt = nb_elt - 1;
	*err = 1; /* s'il n'y a pas eu d'erreur err=1 */
	}
	
	return element;
}




/*  ---------------------------------------------------------------------------------  */
/*  estVide : tester si le tableau de la pile contient des éléments                    */
/*                                                                                     */
/*  Entrée :                                                                           */
/*  -pt_pile = pointeur sur la pile                                                    */
/*                                                                                     */
/*  Sortie :                                                                           */
/*  -vide = booléen qui vaut true(resp. false) si le tableau est vide(resp. non vide)  */
/*  ---------------------------------------------------------------------------------  */

bool estVide(Pile_t * pt_pile)
{
	bool vide = true;  /* variable de type booléenne provenant de la bibliothèque stdbool.h */
	
	if (pt_pile != NULL)
	{
		if (pt_pile->nb_elt != 0)
		{
			vide = false;
		}
	}
	return vide;
}




/* ---------------------------------- */
/*  libererPile : libérer la mémoire  */
/*                                    */
/*  Entrée :                          */
/*  -pointeur sur la pile             */
/*                                    */
/*  Pas de sortie                     */
/* ---------------------------------- */

void libererPile(Pile_t * pt_pile)
{
	free(pt_pile->pt_tab); /* libérer le tableau */
	free(pt_pile); /* libérer la pile */
}



/*  extension d'affichage pour réaliser les tests  */

void affichagePile(Pile_t * pt_pile)
{
	int i=0;
	
	if((pt_pile!=NULL) && (pt_pile->nb_elt!=0))
	{		
		for (i=0;i<pt_pile->taille;i++)
		{
			printf("element n°%d =" FORMAT_ELT, pt_pile->taille-i, pt_pile->pt_tab[pt_pile->taille-i-1]) ;
		}
	}
	
	else 
	{
		printf("pile vide ---> rien à afficher\n");
	}
}

/* ----FIN DU MODULE---- */
