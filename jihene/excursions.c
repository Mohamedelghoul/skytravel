#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "excursions.h"



void ajouter_excursion(Excursion e)
{
	FILE *f;
	f=fopen("excursions.txt","a+");
	if(f!=NULL)

	{
	fprintf(f,"%s %s %s %s %s %s %s %s %s %s %d %d %d \n",e.id,e.depart,e.arrivee,e.d.jour,e.d.mois,e.d.annee,e.duree,e.transport,e.nourriture,e.hebergement,e.nbplacestotal,e.nbplacesrestantes,e.prix);
	fclose(f);
	}
}



void supprimer_excursion(char identifiant[])
{
FILE*f=NULL;
FILE*f1=NULL;
Excursion e;
int b=0;
f=fopen("excursions.txt","r");
f1=fopen("excursions_copie.txt","a");

printf("\n");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d %d %d \n",e.id,e.depart,e.arrivee,e.d.jour,e.d.mois,e.d.annee,e.duree,e.transport,e.nourriture,e.hebergement,&(e.nbplacestotal),&(e.nbplacesrestantes),&(e.prix))!=EOF){
        if((strcmp(e.id,identifiant)!=0))
        {
        fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %d %d %d \n",e.id,e.depart,e.arrivee,e.d.jour,e.d.mois,e.d.annee,e.duree,e.transport,e.nourriture,e.hebergement,e.nbplacestotal,e.nbplacesrestantes,e.prix);

        }else
        {
            b=1;
        }

}
if(b==0){
printf("excursion introuvable");
}
fclose(f);
fclose(f1);
remove("excursion.txt");
rename("excursions_copie.txt","excursions.txt");

}


void modifier_excursion(char identifiant[],Excursion em)
{
	strcpy(em.id,identifiant);
	supprimer_excursion(identifiant);
	ajouter_excursion(em);
}
