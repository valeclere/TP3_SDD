#include "arbre.h"

int main()
{
	/*-----TESTS fonctions de base (InitNoeud, AjoutVerticale, AjoutHorizontale)----*/
	Arbre_t arbre;
	
	arbre = InitNoeud('a');
	Noeud_t * fils = InitNoeud('B');
	Noeud_t * frere = InitNoeud('C');
	AjoutVerticale(arbre, fils);
	AjoutHorizontale(fils, frere);
	
	printf("mot 1 = %c%c \n mot 2 = %c%c\n", arbre->lettre, arbre->lv->lettre, arbre->lettre, arbre->lv->lh->lettre);
	
	printf("l'arbre est cree!!\n");
	
	free(arbre);
	free(fils);
	free(frere);
	/*---------FIN TESTS----------*/
	
	
	return 0;
}

