#include "dico.h"
#include "arbre.h"


int main()
{
	/*-----TESTS fonctions de base (InitNoeud, AjoutVerticale, AjoutHorizontale)----*/
	
    //~ Arbre_t arbre;
    //~ Arbre_t prec;
    //~ int i=0;
    //~ char mot[]="";
    //~ arbre = CreationArbre();
    //~ prec = Rechercher(NULL,mot,&i);
    //~ printf("l'adresse de prec = %p\n", prec);
    //~ LibererArbre(arbre);
    //fin test des fonctions de bases.
    
	Arbre_t arbre=NULL;
	
    ChargerMots(&arbre);
    Affichage(&arbre);
    RechercheDico(&arbre, "sc");
   // Affichage(&arbre);
	//~ int tab[3] = T
	//~ if (tolower('A')=='a'){
		//~ printf("A en min: %c\n",tolower('A'));
	//~ }
	/*---------FIN TESTS----------*/
	return 0;
}

