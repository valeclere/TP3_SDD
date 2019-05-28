/*
 * Module contenant la fonction de lecture du fichier contenant les mots 
 */


#include "dico.h"

int ChargerMots(Arbre_t * pt_arbre)
{
    const char* path = "/Users/pereiraloann/desktop/TP_SDD/TP3/TP3_SDD/mots.txt";/*xcode ne prend que des chemins absolus*/
    /*const char* path = "mots.txt"; pour valentin */
	int code = 0;
	char mot[30];
	FILE * fichier = NULL;
	fichier = fopen(path, "r");
	
	if (fichier==NULL)
	{
		printf("probleme d'ouverture du fichier mots\n");
		code = -1;
	}
	else
	{
		fgets(mot,30,fichier);
		mot[strlen(mot)-1] = 0;
		while(!feof(fichier))
		{
			printf("mot == %s\n", mot);
			Insertion(pt_arbre,mot);
			fgets(mot,30,fichier);
			mot[strlen(mot)-1] = 0;
		}
	}
	fclose(fichier);
	
	return code;
}



void Affichage(Arbre_t *pt_arbre){ /*utilisation du parcours en profondeur*/
    Arbre_t cour=NULL;  /*utilisation d'un pointeur courant*/
    cour=*pt_arbre;
    
    Pile_t *pt_pile=NULL;   /*initialisation de la pile*/
    int taille_tab= 10;
    pt_pile = initPile(taille_tab);
    int mistake =0;
    int *err=&mistake;
    
    char mot[30]={NULL}; /*mot qui permet l'affichage des mots de l'arbre*/
    int i=0;
    while(!estVide(pt_pile) || cour !=NULL){
        mot[i]=cour->lettre;
        i++;
        if((int)cour->lettre<90){                   /*(97 à 122 pour les minuscules et 65 à 90 pour les Maj) on arrive à une maj -->fin du mot*/
            mot[i-1]=tolower(mot[i-1]);             /* on passe la dernière lettre en minuscule*/
            mot[strlen(mot)] = 0;                   /* \0 à la fin du mot*/
            printf("%s\n",mot);               /* on affiche le mot*/
        }
        empiler(pt_pile, cour, err);
        cour=cour->lv;
        while(cour==NULL && !estVide(pt_pile)){
            cour=depiler(pt_pile, err);               /*       postfixé        */
            mot[strlen(mot)-1]=0;       /* on supprime la dernière lettre du mot quand on remonte*/
            i--;                        /* on décrémente i pour l'insertion des futurs lettres*/
            cour=cour->lh;                            /*      fin postfixé     */
        }
    }
}


void RechercheDico(Arbre_t *pt_arbre, char* val){
    int indiceMot=0;
    Noeud_t ** noeud=NULL;
    noeud=Rechercher(pt_arbre, val, &indiceMot);
    printf("lettre de noeud:%c\n",(*noeud)->lettre);
    printf("lettre de val:%c\n",val[strlen(val)-1]);
    if(*noeud!=NULL && *pt_arbre!=NULL){
        printf("mot commençant par %s sont:\n",val);
        Affichage(noeud);
    }
    else{
        printf("Aucun mot trouvé commençant par %s.\n",val);
    }
}
