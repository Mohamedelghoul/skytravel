#ifndef EXCURSIONS_H_
#define EXCURSIONS_H_
#include <stdlib.h>
#include <stdio.h>

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


void ajouter_excursion(Excursion e);
void supprimer_excursion(char identifiant[]);
void modifier_excursion(char identifiant[],Excursion em);


#endif
