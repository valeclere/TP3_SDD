#include "dico.h"
#include "arbre.h"


int main()
{
	Arbre_t arbre=NULL;
	
    ChargerMots(&arbre);
    //Affichage(&arbre,"");
    RechercheDico(&arbre, "ta");
    LiberationArbre(&arbre);
	/*---------FIN TESTS----------*/
	return 0;
}

