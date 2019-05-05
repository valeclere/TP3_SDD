#include "arbre.h"

int main()
{
	/*-----TESTS fonctions de base (InitNoeud, AjoutVerticale, AjoutHorizontale)----*/
	
	Arbre_t arbre;
    Arbre_t prec;
    int i=0;
    char mot[]="";
	arbre = CreationArbre();
    prec = Rechercher(NULL,mot,&i);
    printf("l'adresse de prec = %p\n", prec);
    
    LibererArbre(arbre);

	/*---------FIN TESTS----------*/
	
	
	return 0;
}

