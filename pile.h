#ifndef PILE
#define PILE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /* pour récupérer le type bool */
#include "arbre.h"
#define FORMAT_ELT "%c\n" /* format utilisé dans le printf correspondant au type de element_t */
typedef Arbre_t element_t; /* type de variables présentes dans le tableau, ici on considère des int */

typedef struct Pile_s{
	int taille;
	int nb_elt;
	element_t * pt_tab;
}Pile_t;

Pile_t * initPile(int taille);
void empiler(Pile_t * pt_pile, element_t element, int *err);
element_t depiler(Pile_t * pt_pile,int* err);
bool estVide(Pile_t * pt_pile);
void libererPile(Pile_t * pt_pile);
void affichagePile(Pile_t * pt_pile);


#endif
