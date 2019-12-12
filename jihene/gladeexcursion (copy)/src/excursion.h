#ifndef EXCURSIONS_H_
#define EXCURSIONS_H_
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>

typedef struct date
{
	char jour[10];
	char mois[10];
	char annee[10];
}Date;


typedef struct excursion
{	
	char id[20];
  	char depart[20];
	char arrivee[20];
	char duree[20];
	Date d;
	char transport[30];
	char nourriture[20];
	char hebergement[30];
	int nbplacestotal;
	int nbplacesrestantes;
	int prix;
}Excursion;

typedef struct date1
{
	char jour[10];
	char mois[10];
	char annee[10];
}Date1;





typedef struct excursionr
{
	char identifiant[10];
	char id_excursion[10];
	char id_reservation[10];
	char depart[20];
	char arrivee[20];
	Date1 d;
	int personne;
	int montant;
}Excursionr;

void ajouter_excursion(Excursion e);
void supprimer_excursion(char identifiant[]);
void modifier_excursion(char identifiant[],Excursion em);
void afficher_excursion(GtkWidget *liste);
int code_excursion();
int verifier_code(char C[]);
int verifier_code1(char C[]);
int nombre_ville(char pays[]);
int choix_villes(int n, char tab[50][20]);
int remplir_combo_id(char tab[50][50]);
void cherExcursion(char mak[],char rouna[],char rouna1[],char rouna2[],char rouna3[],char rouna4[],char rouna5[],char rouna6[],char rouna7[],char rouna8[],char rouna9[],char rouna10[],char rouna11[]);
void ajouter_excursionr(Excursionr er);
int code_excursionr();


#endif
