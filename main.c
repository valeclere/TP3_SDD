#include "dico.h"
#include "arbre.h"


int main()
{
	/*-----TESTS fonctions de base (InitNoeud, AjoutVerticale, AjoutHorizontale)----*/
	
//    Arbre_t arbre;
//    Arbre_t prec;
//    int i=0;
//    char mot[]="";
//    arbre = CreationArbre();
//    prec = Rechercher(NULL,mot,&i);
//    printf("l'adresse de prec = %p\n", prec);
//    LibererArbre(arbre);
    //fin test des fonctions de bases.
	Arbre_t arbre=NULL;


//    Insertion(pt_arbre, "banc");
//    Insertion(pt_arbre, "alpha");
//    Insertion(pt_arbre, "grand");
//    Insertion(pt_arbre, "bleu"); //on n'est pas obligé de déclarer un pointeur 
      //~ Insertion(&arbre, "alpha");
      //~ Insertion(&arbre, "alle");
    
	ChargerMots(&arbre);
	
	
	/*---------FIN TESTS----------*/
	
	
	return 0;
}

