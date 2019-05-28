/*
 * Module contenant la fonction de lecture du fichier contenant les mots 
 */

/* ----------------------------------------------------------------------------------------------------------- */
/*  ChargerMots : permet de charger tous les mots contenu dans le fichier mots.txt et de les insérer dans un  */
/*                arbre.                                                                                       */
/*                                                                                                             */
/*                                                                                                             */
/*  En entrée :                                                                                                */
/*      -pt_arbre = pointeur sur la structure arbre qui est elle même un pointeur sur la strucutre Noeud       */
/*		-path = chaine de caractère correspondant au nom du fichier que l'on veut charger					   */
/*                                                                                                             */
/*  En sortie :                                                                                                */
/*      -code = entier qui permet de déterminer si l'exécution du chargement des mots s'est bien passé ou non  */
/* ----------------------------------------------------------------------------------------------------------- */
#include "dico.h"

int ChargerMots(Arbre_t * pt_arbre, char* path)
{
   /* const char* path = "/Users/pereiraloann/desktop/TP_SDD/TP3/TP3_SDD/mots.txt";xcode ne prend que des chemins absolus*/
	//const char* path = "mots.txt";
	int code = 0;
	char mot[30];               /*chaine de caractère qui acceuille les différents mots lu*/
	FILE * fichier = NULL;
	fichier = fopen(path, "r");
	
	if (fichier==NULL)          /*on teste si l'ouverture du fichier s'est bien passé*/
	{
		printf("probleme d'ouverture du fichier mots\n");
		code = -1;
	}
	else
	{
		fgets(mot,30,fichier);  /*on lit la première ligne du fichier et on met le mot lu dans mot*/
		mot[strlen(mot)-1] = 0; /*on ajoute à la fin du mot \0*/
		while(!feof(fichier))   /*tant qu'on est pas à la fin du mot*/
		{
			Insertion(pt_arbre,mot);    /*on insert le mot lu précédemment dans l'arbre*/
			fgets(mot,30,fichier);      /*on lit la ligne suivante*/
			mot[strlen(mot)-1] = 0;
		}
	}
	fclose(fichier);            /*on ferme le flot*/
	
	return code;                /*retour du code d'erreur*/
}

/* ----------------------------------------------------------------------------------------------------------- */
/*  Affichage : Permet d'afficher tous les mots présent dans l'arbre par ordre alphabétique, ou d'afficher     */
/*                seulement les mots commençant par un certains motif.                                         */
/*                                                                                                             */
/*  En entrée :                                                                                                */
/*      -pt_arbre = pointeur sur la structure arbre qui est elle même un pointeur sur la strucutre Noeud       */
/*      -motif = chaine de caractère correspondant au motif que l'on veut afficher                             */
/* ----------------------------------------------------------------------------------------------------------- */

void Affichage(Arbre_t *pt_arbre, char *motif){
    Arbre_t      cour=NULL;                          /*utilisation d'un pointeur courant*/
    Pile_t     * pt_pile=NULL;                       /*initialisation de la pile*/
    int          mistake=0;                          /*variable qui acceuille les codes retours*/
    char         mot[30]={0};                        /*mot qui permet l'affichage des mots de l'arbre*/
    int          i=0;                                /*indice pour le parcours de mot*/
    
    
    pt_pile = initPile(10);                          /*initialisation de la pile (taille=10) */
    cour=*pt_arbre;
    
    while(!estVide(pt_pile) || cour !=NULL){        /*utilisation du parcours en profondeur*/
                                                                     /*     préfixé     */
        mot[i]=cour->lettre;                        /*on insére dans mot la lettre présente dans le noeud pointé par cour*/
        i++;                                        /*on incrémente i pour décaler la futur insertion*/
        if((int)cour->lettre<90){                   /*(97 à 122 pour les minuscules et 65 à 90 pour les Maj)on a une maj-->fin du mot*/
            mot[i-1]=tolower(mot[i-1]);             /* on passe la dernière lettre en minuscule*/
            mot[strlen(mot)] = 0;                   /* \0 à la fin du mot*/
            if(motif==NULL)                         /* si on ne renseigne pas de motif lors de l'appel de la fonction*/
            printf("%s\n",mot);                     /* on affiche le mot normalement*/
            else
            printf("%s%s\n",motif,mot);             /*sinon on est obligé d'afficher le préfix (correspondant au motif) avant le mot*/
        }                                                           /*     fin préfixé     */
        empiler(pt_pile, cour, &mistake);           /*on empile le cour dans la pile pour le bon déroulement du parcours en profondeur*/
        cour=cour->lv;                              /*on descend dans les fils du courant*/
        
        while(cour==NULL && !estVide(pt_pile)){     /*tant que le courant est nul et que la vide n'est pas vide*/
            cour=depiler(pt_pile, &mistake);                        /*       postfixé        */
            mot[strlen(mot)-1]=0;                   /* on supprime la dernière lettre du mot quand on remonte*/
            i--;                                    /* on décrémente i pour l'insertion des futurs lettres*/
            cour=cour->lh;                                          /*      fin postfixé     */
        }
    }
    libererPile(pt_pile);
}

/* ----------------------------------------------------------------------------------------------------------- */
/*  RechercheDico : Permet de faire une recherche dans l'arbre des mots commençant par un certain motif.       */
/*                                                                                                            */
/*  En entrée :                                                                                                */
/*      -pt_arbre = pointeur sur la structure arbre qui est elle même un pointeur sur la strucutre Noeud       */
/*      -motif = chaine de caractère correspondant au motif que l'on veut afficher                             */
/* ----------------------------------------------------------------------------------------------------------- */

void RechercheDico(Arbre_t *pt_arbre, char* motif){
    int             indiceMot=0;                /*indice qui permet de savoir ou la lecture du fichier s'est faite*/
    int             trouve=0;                   /*entier qui détermine si l'on a bien la présence du motif dans l'arbre*/
    Noeud_t      ** noeud=NULL;
    
    noeud=Rechercher(pt_arbre, motif, &indiceMot, &trouve); /*noeud va pointé à l'endroit de son précédent*/
    
    if(trouve==1 && *pt_arbre!=NULL){                         /*si on a le motif dans l'arbre et que l'abre n'est pas vide*/
        printf("mot commençant par %s sont:\n",motif);
        Affichage(noeud,motif);                              /*on appelle la fonction affichage avec le noeud et le motif*/
    }
    else{                                                   /*sinon cela signifie que le motif n'est pas dans l'arbre*/
        printf("Aucun mot trouvé commençant par %s.\n",motif);
    }
}

