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
            if(cour->lv!=NULL && cour->lettre==pt_mot[*indiceMot]){//si on tombe sur la bonne lettre et que cours à au moins un fils
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
//à la fin de rechercher i correspond à l'indice de la première lettre à insérer


bool Insertion(Arbre_t *pt_arbre, char * mot){
    int i=0;
    bool retour=false;
    
    Noeud_t * prec = Rechercher(*pt_arbre, mot, &i);
    Noeud_t *nouvLettre=NULL;
    
    if(prec==NULL){                //CAS 1 : arbre vide ou insertion avant le premier élément
        prec=InitNoeud(mot[i]);
        prec->lettre=mot[i]; 
        // pouruoi un noeud contenant lettre = \0 est en racine ???
        prec->lh=*pt_arbre;
        *pt_arbre=prec;
        i++;
    }
    
    else{
    
	    if(prec->lettre!=mot[i]){ // CAS 2 lettre à insérer horizontalement (l'insertion ce fait dans les frères)
	        nouvLettre=InitNoeud(mot[i]);
	        nouvLettre->lettre=mot[i];
	        nouvLettre->lh=prec->lh; // on chaine la nouvelle lettre dans la liste des frères
	        prec->lh=nouvLettre;
	        prec=nouvLettre;
	        i++;
	    }
	    
	    else{
		    if (prec->lettre == mot[i-1] && prec->lv!=NULL){  // CAS 3 : lettre à insérer horizontalement en position 1 insertion (insertion en position 1 des fils) (est-il possible de rassembler le cas 1 et le cas 3 ??
				nouvLettre = InitNoeud(mot[i]);
		        nouvLettre->lettre=mot[i];
		        nouvLettre->lh=prec->lv;  //prec->lv->lh;
		        prec->lv=nouvLettre;
		        prec = nouvLettre;
		        i++;
			}
		}
	
	}
    
    while (mot[i]!='\0'){
        nouvLettre = InitNoeud(mot[i]);
        nouvLettre->lettre=mot[i];
        prec->lv=nouvLettre;
        prec=nouvLettre;
        i++;
    }
    prec->lettre = toupper(prec->lettre);
    
    return retour;
}



void LibererArbre(Arbre_t arbre){
	free(arbre->lv->lh);
	free(arbre->lv);
	free(arbre);
}

