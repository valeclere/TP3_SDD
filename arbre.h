#ifndef ARBRE
#define ARBRE

#include "dico.h"


typedef struct Noeud_s{
	char lettre;
	struct Noeud_s * lv;
	struct Noeud_s * lh;
}Noeud_t, * Arbre_t;


Noeud_t * InitNoeud(char lettre);
void AjoutVerticale(Noeud_t * pere, Noeud_t * fils);
void AjoutHorizontale(Noeud_t * GrandFrere, Noeud_t * PetitFrere);
Arbre_t CreationArbre(char ** arbre, int taille)

#endif