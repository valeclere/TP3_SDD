#ifndef DICO
#define DICO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "pile.h"
int ChargerMots(Arbre_t * pt_arbre, char* path);
void Affichage(Arbre_t *pt_arbre, char *motif);
void RechercheDico(Arbre_t *pt_arbre, char* motif);
#endif
