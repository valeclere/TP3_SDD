/* Module contenant les fonctions pour insérer les mots dans l'arbre*/

#include "arbre.h"


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
	
	return arbre;
}

Noeud_t ** Rechercher(Arbre_t * pt_arbre, char * pt_mot, int * indiceMot, int * trouve){// à optimiser!!!!
    *indiceMot=0;
    *trouve=0;
    bool arret=false;
    //Arbre_t retour=arbre;
    Noeud_t * cour=*pt_arbre;
    Noeud_t ** prec=pt_arbre;
    while(arret==false){
        while(cour!=NULL && tolower(cour->lettre)<pt_mot[*indiceMot]){
            prec=&(cour->lh);
            cour=cour->lh;
        }
		if(cour!=NULL && tolower(cour->lettre)==pt_mot[*indiceMot]){//si on tombe sur la bonne lettre et que cours à au moins un fils
			prec=&(cour->lv);
			cour=cour->lv;
			if(pt_mot[*indiceMot+1]=='\0'){ // si on est à la fin du mot
				arret=true; 
				*trouve=1;
			}
			else (*indiceMot)++;
		}
		else arret=true;
    }
    //if(*prec!=NULL)printf("lettre prec= %c\n",(*prec)->lettre);
    return prec;
}
//à la fin de rechercher i correspond à l'indice de la première lettre à insérer



void Insertion(Arbre_t * pt_arbre, char * mot){
    int i=0;
    int trouve=0;
    Noeud_t ** prec = Rechercher(pt_arbre, mot, &i, &trouve);
    Noeud_t * nouvLettre=NULL;
    
    nouvLettre=InitNoeud(mot[i]);
	nouvLettre->lettre=mot[i];
	nouvLettre->lh=*prec; // on chaine la nouvelle lettre dans la liste des frères
	*prec=nouvLettre;
	prec=&nouvLettre->lv;
	i++;
    
    while (mot[i]!='\0'){
        nouvLettre=InitNoeud(mot[i]);
		nouvLettre->lettre=mot[i];
		*prec=nouvLettre;
		prec=&nouvLettre->lv;
		i++;
    }
    nouvLettre->lettre = toupper(nouvLettre->lettre);
    //printf("derniere lettre = %c\n", nouvLettre->lettre);
}


void LibererArbre(Arbre_t arbre){
	free(arbre->lv->lh);
	free(arbre->lv);
	free(arbre);
}


