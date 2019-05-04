#include "arbre.h"

int main()
{
	/*-----TESTS fonctions de base (InitNoeud, AjoutVerticale, AjoutHorizontale)----*/
	
	Arbre_t arbre;
    Arbre_t prec;
    int i=0;
    char mot[]="aCd";
	arbre = CreationArbre();
    prec = Rechercher(arbre,mot,&i);
    printf("l'adresse de prec = %p\n", prec);

	/*---------FIN TESTS----------*/
	
	
	return 0;
}

