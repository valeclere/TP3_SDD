/* Module contenant les fonctions pour insérer les mots dans l'arbre*/

#include "arbre.h"
#include "pile.h"

/*----------------------------------------------------------------------------------------------------
 * InitNoeud : permet d'allouer un noeud contenant une lettre, le lien vertical et le lien horizontal
 * Entrée : une lettre
 * Sortie : un pointeur sur le noeud créé
-------------------------------------------------------------------------------------------------------*/

Noeud_t * InitNoeud(char lettre)
{
	Noeud_t * pt_Noeud = NULL;
	pt_Noeud =(Noeud_t*)malloc(sizeof(Noeud_t)); /*allocation du noeud*/
	
	if (pt_Noeud == NULL) /*si l'allocation échoue*/
	{
		printf("Problème d'allocation !\n");
		exit(0); /*on quitte le programme*/
	}
	
	else
	{
		pt_Noeud->lettre=lettre; /*on place la lettre dans le noeud*/
		pt_Noeud->lv=NULL; /*on initialise les liens*/
		pt_Noeud->lh=NULL;
	}
	
	return pt_Noeud;
}



/*-------------------------------------------------------------------------------------------------
 * Rechercher : chercher le précédent pour insérer le mot au bon endroit 
 * Entrée : pt_arbre = pointeur sur l'arbre;
 * 			pt_mot = pointeur sur le mot à insérer
 * 			indiceMot = pointeur pour savoir ce qu'il reste à insérer
 * 			trouve = pointeur sur un booléen permettant ===============================================================!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * Sortie : prec = pointeur sur un lien (horizontal ou vertical) pour l'insertion de la fin du mot
---------------------------------------------------------------------------------------------------*/

Noeud_t ** Rechercher(Arbre_t * pt_arbre, char * pt_mot, int * indiceMot, int * trouve){
    *indiceMot=0; /*on initialise le déplacement dans le mot à 0*/
    *trouve=0;
    bool arret=false; /*booléen pour détecter la fin de la recherche*/
    
    Noeud_t * cour=*pt_arbre; /*pointeur de parcours initialisé sur la racine*/
    Noeud_t ** prec=pt_arbre; /*pointeur précédent initialisé sur le pointeur de la racine*/
    while(arret==false){
        while(cour!=NULL && tolower(cour->lettre)<pt_mot[*indiceMot]){ /*parcours horizontal*/
            prec=&(cour->lh);
            cour=cour->lh;
        }
		if(cour!=NULL && tolower(cour->lettre)==pt_mot[*indiceMot]){ /*si on tombe sur la bonne lettre on se déplace verticalement*/
			prec=&(cour->lv);
			cour=cour->lv;
			if(pt_mot[*indiceMot+1]=='\0'){ /*si on est à la fin du mot*/
				arret=true;
				*trouve=1;
			}
			else (*indiceMot)++; /*on se décale dans le mot à insérer*/
		}
		else arret=true; /*on s'arrête si une lettre n'existe pas dans un niveau*/
    }
    return prec;
} /*à la fin de rechercher i correspond à l'indice de la première lettre à insérer*/



/*-----------------------------------------------------
 * Insertion : permet d'insérer un mot dans l'arbre
 * Entrée : pt_arbre = pointeur sur l'arbre
 * 			mot = mot à insérer
------------------------------------------------------*/

void Insertion(Arbre_t * pt_arbre, char * mot){
    int i=0; /*on initialise le déplacement dans le mot à 0*/
    int trouve=0; /*booleen qui permet de savoir si le mot existe déjà dans l'arbre en mémoire*/
    Noeud_t ** prec = Rechercher(pt_arbre, mot, &i, &trouve); /*on récupère prec pour insérer la fin du mot*/
    Noeud_t * nouvLettre=NULL;
    
    
    if(!trouve){
		nouvLettre=InitNoeud(mot[i]); /*allocation d'un nouveau noeud*/
		nouvLettre->lettre=mot[i]; /*on place la prochaine lettre*/
		nouvLettre->lh=*prec; /*on chaine la nouvelle lettre dans la liste des frères*/
		*prec=nouvLettre;
		prec=&nouvLettre->lv; /*on actualise prec sur le nouveau noeud en lien vertical pour insérer toute la suite*/
		i++; /*on se déplace dans le mot*/
		
		while (mot[i]!='\0'){ /*tant qu'on a pas inséré tout le mot on réalise une insertion verticale de la lettre*/
			nouvLettre=InitNoeud(mot[i]);
			nouvLettre->lettre=mot[i];
			*prec=nouvLettre;
			prec=&nouvLettre->lv;
			i++;
		}
		nouvLettre->lettre = toupper(nouvLettre->lettre); /*on transforme la dernière lettre en majuscule*/
	}
}



/*---------------------------------------------------------
 * LiberationArbre : permet de libérer l'arbre en mémoire
 * Entrée : pointeur sur l'arbre
----------------------------------------------------------*/

void LiberationArbre(Arbre_t * pt_arbre){
	Arbre_t      cour=NULL;                          /*utilisation d'un pointeur courant*/
	Arbre_t		 tmp=NULL;
    Pile_t     * pt_pile=NULL;                       /*initialisation de la pile*/
    int          mistake=0;                          /*variable qui acceuille les codes retours*/
    char         mot[30]={0};                        /*mot qui permet l'affichage des mots de l'arbre*/
    int          i=0;                                /*indice pour le parcours de mot*/
    
    pt_pile = initPile(100);                          /*initialisation de la pile pour le parcours en profondeur*/
    cour=*pt_arbre;
    
	while(!estVide(pt_pile) || cour !=NULL){        /*parcours en profondeur*/
        empiler(pt_pile, cour, &mistake); /*on stocke le père dans la pile*/
        cour=cour->lv; /*puis on descend verticalement*/
        while(cour==NULL && !estVide(pt_pile)){ 
            cour=depiler(pt_pile, &mistake); /*on dépile le père*/
            tmp=cour;
            cour=cour->lh; /*on parcourt les frères*/
            free(tmp); /*on libère le noeud dont tous les fils ont été libérés*/
        }
    }
    
    libererPile(pt_pile); /*on libère la pile car le parcours en profondeur est terminé*/
}










