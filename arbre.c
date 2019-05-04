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
	
	arbre = InitNoeud('a');
	Noeud_t * fils = InitNoeud('B');
	Noeud_t * frere = InitNoeud('C');
	AjoutVerticale(arbre, fils);
	AjoutHorizontale(fils, frere);
	
    printf("l'adresse de c = %p\n", frere);
	printf("mot 1 = %c%c \n mot 2 = %c%c\n", arbre->lettre, arbre->lv->lettre, arbre->lettre, arbre->lv->lh->lettre);
	
	printf("l'arbre est cree!!\n");
	
//    free(arbre);
//    free(fils);
//    free(frere);
	
	return arbre;
}

Noeud_t * Rechercher(Arbre_t arbre, char * pt_mot, int * indiceMot){
    *indiceMot=0;
    bool arret=false;
    Arbre_t retour=arbre;
    Noeud_t * cour=arbre;
    Noeud_t * prec=arbre;
    while(arret==false){
        while(cour!=NULL && cour->lettre<pt_mot[*indiceMot]){
            prec=cour;
            cour=cour->lh;
        }
        if(cour!=NULL){
            if(cour->lv!=NULL && cour->lettre==pt_mot[*indiceMot]  ){
                prec=cour;
                cour=cour->lv;
                if(pt_mot[*indiceMot+1]=='\0') arret=true;
                (*indiceMot)++;
            }
            else{
                arret=true;
            }
        }
        else arret=true;
    }
    if(cour->lettre==pt_mot[*indiceMot]) retour=cour;
    else retour=prec;
    
    return retour;
}
