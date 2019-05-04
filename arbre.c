/* Module contenant les fonctions pour insérer les mots dans l'arbre*/

#include "arbre.h"
#include <stdbool.h>
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
	//~ if (pere->lv!=NULL)
	//~ {
		//~ printf("Attention fils déjà existant !\n");
	//~ }
	
	pere->lv = fils;

}
	


void AjoutHorizontale(Noeud_t * GrandFrere, Noeud_t * PetitFrere)
{
	//~ if (GrandFrere->lh!=NULL)
	//~ {
		//~ printf("Attention frere déjà existant !\n");
	//~ }
		
	GrandFrere->lh = PetitFrere;
}

Arbre_t CreationArbre(void)
{
	Arbre_t arbre;
	
	arbre = InitNoeud('z');
	Noeud_t * fils = InitNoeud('B');
	Noeud_t * frere = InitNoeud('C');
	AjoutVerticale(arbre, fils);
	AjoutHorizontale(fils, frere);
	
    printf("l'adresse de z = %p\n", arbre);
    printf("l'adresse de B = %p\n", fils);
    printf("l'adresse de C = %p\n", frere);

	printf("mot 1 = %c%c \nmot 2 = %c%c\n", arbre->lettre, arbre->lv->lettre, arbre->lettre, arbre->lv->lh->lettre);
	
	printf("l'arbre est cree!!\n");
	
//    free(arbre);
//    free(fils);
//    free(frere);
	
	return arbre;
}

Noeud_t * Rechercher(Arbre_t arbre, char * pt_mot, int * indiceMot){// à optimiser!!!!
    *indiceMot=0;
    bool arret=false;
    //Arbre_t retour=arbre;
    Noeud_t * cour=arbre;
    Noeud_t * prec=NULL;
    while(arret==false){
        while(cour!=NULL && cour->lettre<pt_mot[*indiceMot]){
            prec=cour;
            cour=cour->lh;
        }
        if(cour!=NULL){// si la première lettre n'est pas plus loin dans l'alphabet
            if(cour->lv!=NULL && cour->lettre==pt_mot[*indiceMot]  ){//si on tombe sur la bonne lettre et que cours à au moins un fils
                prec=cour;
                cour=cour->lv;
                if(pt_mot[*indiceMot+1]=='\0') arret=true; // si on est à la fin du mot
                (*indiceMot)++;
            }
            else{
                arret=true;
            }
        }
        else arret=true;
    }
    if(cour!=NULL) if(cour->lh == NULL && cour->lv==NULL) prec=cour;
    return prec;
}
