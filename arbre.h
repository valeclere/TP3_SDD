#ifndef ARBRE
#define ARBRE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Noeud_s{
	char lettre;
	struct Noeud_s * lv;
	struct Noeud_s * lh;
}Noeud_t, * Arbre_t;


Noeud_t * InitNoeud(char lettre);
Noeud_t ** Rechercher(Arbre_t * pt_arbre, char * pt_mot, int * indiceMot, int *trouve);
void Insertion(Arbre_t * pt_arbre, char * mot);
void LiberationArbre(Arbre_t * pt_arbre);
#endif
