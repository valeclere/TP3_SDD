#include "test.h"

void test_Charger_Mots(){
	printf("------Test de la fonction ChargerMots-------\n");
	Arbre_t arbre=NULL;
	printf("------Cas générale: fichier normal rempli de mot------\n");
	if(ChargerMots(&arbre,"mots.txt")==0)
	{
		printf("Chargement du fichier effectué\n");
		Affichage(&arbre,"");
	}
	else{
		printf("PROBLEME Chargement du fichier\n");
	}
	LiberationArbre(&arbre);
	printf("\n-----------------------------------------\n");
	printf("------Cas 1: fichier vide------\n");	
	printf("-----------------------------------------\n");
	 arbre=NULL;
	if(ChargerMots(&arbre,"motsVide.txt")==0)
	{
		printf("Chargement du fichier effectué\n");
		Affichage(&arbre,"");
	}
	else{
		printf("PROBLEME Chargement du fichier\n");
	}
	LiberationArbre(&arbre);
}


void test_Rechercher(){
	Arbre_t arbre=NULL; /*utilisée pour les tests de cette fonction*/
	Noeud_t ** prec= NULL;	
	int i=0;
    int trouve=0;
    char mot[20]={0};
	ChargerMots(&arbre,"mots.txt");
	printf("------Test de la fonction Rechercher-------\n");
	printf("-----------------------------------------\n");
	Affichage(&arbre,"");
	printf("Utilisation de l'arbre ci-dessus pour le test de la recherche\n");
	printf("\n-----------------------------------------\n");
	printf("------Cas général 1: recherche d'un motif existant dans l'arbre ------\n");	
	printf("-----------------------------------------\n");
	strcpy(mot,"co");
	prec = Rechercher(&arbre, mot, &i, &trouve);
	printf("Pour le mot %s lettre pointé par le prec est %c",mot,(*prec)->lettre);
	printf("\n-----------------------------------------\n");
	printf("------Cas 1: mot non présent dans l'arbre------\n");	
	printf("-----------------------------------------\n");
	
	
	printf("\n-----------------------------------------\n");
	printf("------Cas 2: mot vide------\n");	
	printf("-----------------------------------------\n");
	
}

void test_Insertion(){
	printf("------Test de la fonction Insertion-------\n");
	
}


void test_Recherche_Dico(){
	printf("------Test de la fonction RechercheDico-------\n");

}

void test_Affichage(){
	printf("------Test de la fonction Affichage-------\n");
}

void test_Affichage_Motif(){
	printf("------Test de la fonction AffichageMotif-------\n");
}
