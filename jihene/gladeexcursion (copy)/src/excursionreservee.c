#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "excursionsreservees.h"




void ajouter_excursionr(Excursionr er)
{
	FILE *f;
	f=fopen("excursionsreservees.txt","a+");
	if(f!=NULL)

	{
	fprintf(f,"%s %s %s %s %s %s %s %s %s %d %d \n",er.identifiant,er.id_reservation,er.id_excursion,er.depart,er.arrivee,er.d.jour,er.d.mois,er.d.mois,er.d.annee,er.personne,er.montant);
	fclose(f);
	}
}



void supprimer_excursionr(char identifiant)
{
	FILE*f=NULL;
FILE*f1=NULL;
Excursionr er;
int b=0;
f=fopen("excursions.txt","r");
f1=fopen("excursionsreservees_copie.txt","a");

printf("\n");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %d %d \n",er.identifiant,er.id_reservation,er.id_excursion,er.depart,er.arrivee,er.d.jour,er.d.mois,er.d.mois,er.d.annee,&(er.personne),&(er.montant))!=EOF){
        if((strcmp(er.identifiant,identifiant)!=0))
        {
        fprintf(f1,"%s %s %s %s %s %s %s %s %s %d %d \n",er.identifiant,er.id_reservation,er.id_excursion,er.depart,er.arrivee,er.d.jour,er.d.mois,er.d.mois,er.d.annee,er.personne,er.montant);

        }else
        {
            b=1;
        }

}
if(b==0){
printf("excursion reservée introuvable");
}
fclose(f);
fclose(f1);
remove("excursionreservees.txt");
rename("excursionsreservees_copie.txt","excursionsreservees.txt");
}


void modifier_excursion(char identifiant,Excursionr erm)
{
	strcpy(erm.identifiant,identifiant);
	supprimer_excursionr(identifiant);
	ajouter_excursionr(erm);
}
