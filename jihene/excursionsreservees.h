#ifndef EXCURSIONSRESERVEES_H_
#define EXCURSIONSRESERVEES_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void ajouter_excursionr(Excursionr er);
void supprimer_excursionr(char identifiant[]);
void modifier_excursionr(char identifiant[],Excursionr erm);

#endif
