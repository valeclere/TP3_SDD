#include "dico.h"
#include "arbre.h"
#include "test.h"

int main()
{
	//Arbre_t arbre=NULL;
    //ChargerMots(&arbre,"mots.txt");
    //Affichage(&arbre,"");
    //RechercheDico(&arbre, "ta");
    //LiberationArbre(&arbre);
    
    test_Charger_Mots();
    test_Rechercher();
    test_Insertion();
    
	/*---------FIN TESTS----------*/
	return 0;
}

