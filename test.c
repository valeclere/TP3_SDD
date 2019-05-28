#include "test.h"

void test_Charger_Mots(){
	printf("------Test de la fonction ChargerMots-------\n");
	Arbre_t arbre=NULL;
	printf("------Cas générale: fichier normal rempli de mot------\n");
	if(ChargerMots(&arbre,"/Users/pereiraloann/desktop/TP_SDD/TP3/TP3_SDD/mots.txt")==0)
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
	if(ChargerMots(&arbre,"/Users/pereiraloann/desktop/TP_SDD/TP3/TP3_SDD/motsVide.txt")==0)
	{
		printf("Chargement du fichier effectué\n");
		Affichage(&arbre,"");
	}
	else{
		printf("PROBLEME Chargement du fichier\n");
	}
    
    printf("\n-----------------------------------------\n");
    printf("--------\tFIN TESTS CHARGER MOTS\t--------\n");
    printf("-----------------------------------------\n\n");
    
	LiberationArbre(&arbre);
}


void test_Rechercher(){
	Arbre_t arbre=NULL; /*utilisée pour les tests de cette fonction*/
	Noeud_t ** prec= NULL;	
	int i=0;
    int trouve=0;
    char mot[20]={0};
	ChargerMots(&arbre,"/Users/pereiraloann/desktop/TP_SDD/TP3/TP3_SDD/mots.txt");
	printf("------Test de la fonction Rechercher-------\n");
	printf("-----------------------------------------\n");
	Affichage(&arbre,"");
	printf("Utilisation de l'arbre ci-dessus pour le test de la recherche\n");
    
	printf("\n-----------------------------------------\n");
	printf("------Cas général 1: recherche d'un motif existant dans l'arbre ------\n");	
	printf("-----------------------------------------\n\n");
	
    strcpy(mot,"co");
	prec = Rechercher(&arbre, mot, &i, &trouve);
	printf("Pour le mot %s lettre pointé par le prec est %c\n",mot,(*prec)->lettre);
    
	printf("\n-----------------------------------------\n");
	printf("------Cas 1: mot non présent dans l'arbre------\n");	
	printf("-----------------------------------------\n");
	
    strcpy(mot,"cheval");
    prec = Rechercher(&arbre, mot, &i, &trouve);
    if(*prec==NULL) printf("\n*prec = NULL\n");
    else printf("Pour le mot %s lettre pointé par le prec est %c",mot,(*prec)->lettre);
	
	printf("\n-----------------------------------------\n");
	printf("------Cas 2: mot vide------\n");	
	printf("-----------------------------------------\n");
    
    prec = Rechercher(&arbre, "", &i, &trouve);
    if(*prec==NULL) printf("\n*prec = NULL\n");
    else printf("Pour le mot %s lettre pointé par le prec est %c",mot,(*prec)->lettre);
    
    printf("\n-----------------------------------------\n");
    printf("------Cas 3: mot existant ------\n");
    printf("-----------------------------------------\n");
    
    strcpy(mot,"coup");
    prec = Rechercher(&arbre, mot, &i, &trouve);
    if(*prec==NULL) printf("\n*prec = NULL\n");
    else printf("Pour le mot %s lettre pointé par le prec est %c",mot,(*prec)->lettre);
    
    printf("\n-----------------------------------------\n");
    printf("--------\tFIN TESTS RECHERCHER\t--------\n");
    printf("-----------------------------------------\n\n");
    LiberationArbre(&arbre);

}

void test_Insertion(){
    Arbre_t arbre=NULL; /*utilisée pour les tests de cette fonction*/
    ChargerMots(&arbre,"/Users/pereiraloann/desktop/TP_SDD/TP3/TP3_SDD/motsInsertion.txt");
    printf("-----------------------------------------\n");
	printf("------Test de la fonction Insertion-------\n");
    printf("-----------------------------------------\n\n");
    Affichage(&arbre,"");
    printf("Utilisation de l'arbre ci-dessus pour le test de l'insertion\n");
    
    printf("\n-----------------------------------------\n");
    printf("------Cas général : insertion d'un mot non présent dans l'arbre------\n");
    printf("-----------------------------------------\n");
    
    Insertion(&arbre, "cheval");
    Affichage(&arbre,"");
    
    printf("\n-----------------------------------------\n");
    printf("------Cas 1: insertion d'un mot déjà existant------\n");
    printf("-----------------------------------------\n");
    
    Insertion(&arbre, "cheval");
    Affichage(&arbre,"");
    
    printf("\n-----------------------------------------\n");
    printf("------Cas 2: insertion d'un mot à la racine------\n");
    printf("-----------------------------------------\n");
    
    Insertion(&arbre, "abeille");
    Affichage(&arbre,"");
    
    printf("\n-----------------------------------------\n");
    printf("------Cas 3: insertion d'un mot à droite------\n");
    printf("-----------------------------------------\n");
    
    Insertion(&arbre, "zebre");
    Affichage(&arbre,"");
    
    printf("\n-----------------------------------------\n");
    printf("------Cas 4: insertion d'un mot vide------\n");
    printf("-----------------------------------------\n");
    
    Insertion(&arbre, "");
    Affichage(&arbre,"");
    
    printf("\n-----------------------------------------\n");
    printf("------Cas 5: insertion d'un mot dans un arbre vide------\n");
    printf("-----------------------------------------\n");

    LiberationArbre(&arbre);
    arbre=NULL;
    Insertion(&arbre, "bougie");
    Affichage(&arbre,"");
    
    printf("\n-----------------------------------------\n");
    printf("--------\tFIN TESTS INSERTION\t--------\n");
    printf("-----------------------------------------\n\n");
    LiberationArbre(&arbre);
}


void test_Recherche_Dico(){
    Arbre_t arbre=NULL; /*utilisée pour les tests de cette fonction*/
    ChargerMots(&arbre,"/Users/pereiraloann/desktop/TP_SDD/TP3/TP3_SDD/mots.txt");
    printf("-----------------------------------------\n");
    printf("------Test de la fonction RechercheDico-------\n");
    printf("-----------------------------------------\n\n");
    Affichage(&arbre,"");
    printf("Utilisation de l'arbre ci-dessus pour le test de la recherche avec motif\n");
    
    printf("\n-----------------------------------------\n");
    printf("------Cas générale: recherche motif qui existe dans l'arbre------\n");
    printf("-----------------------------------------\n");

    RechercheDico(&arbre, "ch");
    
    printf("\n-----------------------------------------\n");
    printf("------Cas 1: recherche motif qui N'existe PAS dans l'arbre------\n");
    printf("-----------------------------------------\n");
    
    RechercheDico(&arbre, "existepas");
    
    printf("\n-----------------------------------------\n");
    printf("------Cas 2: recherche motif vide------\n");
    printf("-----------------------------------------\n");
    
    RechercheDico(&arbre, "");
    
    printf("\n-----------------------------------------\n");
    printf("--------\tFIN TESTS RECHERCHE DICO\t--------\n");
    printf("-----------------------------------------\n\n");
    LiberationArbre(&arbre);
}

void test_Affichage(){
    Arbre_t arbre=NULL; /*utilisée pour les tests de cette fonction*/
    printf("-----------------------------------------\n");
    printf("------Test de la fonction Affichage-------\n");
    printf("-----------------------------------------\n\n");
    Affichage(&arbre,"");
    printf("Utilisation de l'arbre ci-dessus pour le test de l'affichage\n");
    printf("Les cas principaux ont été gérés dans les tests de la fonctions ChargerMots\n");
    
    printf("\n-----------------------------------------\n");
    printf("------Autre Cas: arbre=NULL ------\n");
    printf("-----------------------------------------\n");
    
    Affichage(&arbre, "");
    printf("\nN'affiche rien, car il n'a rien a afficher\n");
    
    printf("\n-----------------------------------------\n");
    printf("--------\tFIN TESTS  AFFICHAGE\t--------\n");
    printf("-----------------------------------------\n\n");
}

void test_Affichage_Motif(){
    printf("-----------------------------------------\n");
    printf("------Test de la fonction AffichageMotif-------\n");
    printf("-----------------------------------------\n\n");
    printf("Tous les cas ont été testés dans les testes de la fonction RechercheMotif.\n");
    
    printf("\n-----------------------------------------\n");
    printf("--------\tFIN TESTS  AFFICHAGE MOTIF\t--------\n");
    printf("-----------------------------------------\n\n");
}
