#ifndef ARBRE
#define ARBRE

#include <stdbool.h>
#include "dico.h"


typedef struct Noeud_s{
	char lettre;
	struct Noeud_s * lv;
	struct Noeud_s * lh;
}Noeud_t, * Arbre_t;


Noeud_t * InitNoeud(char lettre);
void AjoutVerticale(Noeud_t * pere, Noeud_t * fils);
void AjoutHorizontale(Noeud_t * GrandFrere, Noeud_t * PetitFrere);
Noeud_t * Rechercher(Arbre_t arbre, char * pt_mot, int * indiceMot);
bool Insertion(Arbre_t *pt_arbre, char * mot);
Arbre_t CreationArbre(void);
void LibererArbre(Arbre_t arbre);


#endif
