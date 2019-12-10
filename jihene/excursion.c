#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "excursion.h"
#include <time.h>



int verifier_code(char C[])
{
	Excursion e;
	FILE* f=NULL;
	f=fopen("excursion.txt","r");
	if(f !=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s",e.id);
			if (strcmp(C,e.id)==0)
				return (1);
		}
	}
	return (0);
}

int code_excursion()
{
	int A;
	srand(time(NULL));
	A=rand()%900;
	A=A+100;
	return(A);
}



void ajouter_excursion(Excursion e)
{
	FILE *f;
	f=fopen("excursion.txt","a+");
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
f=fopen("excursion.txt","r");
f1=fopen("excursion_copie.txt","a");

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
rename("excursion_copie.txt","excursion.txt");


}





void afficher_excursion(GtkWidget *liste)
{	




	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	
	GtkListStore *store;

	char id[20];
  	char depart[20];
	char arrivee[20];
	char duree[20];
	char da[50];
	char dte[50];
	Date d;
	char transport[30];
	char nourriture[20];
	char hebergement[30];
	int nbplacestotal;
	int nbplacesrestantes;
	char places[70];
	int prix;
	char prix1[20];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	enum 
{
ID,
DA,
DUREE,
DATE,
TRANSPORT,
HEBERGEMENT,
PLACES,
PRIX,
COLUMNS
};

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Depart/Arrivée",renderer,"text",DA,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Durée",renderer,"text",DUREE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Date",renderer,"text",DATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Transport",renderer,"text",TRANSPORT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Hébergement",renderer,"text",HEBERGEMENT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Disponibilité",renderer,"text",PLACES,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Prix",renderer,"text",PRIX,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		f=fopen("excursion.txt","r");
		if(f==NULL)
		{
			return;
		}
		else 
		{
			f=fopen("excursion.txt","a+");
   			while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d %d %d \n",id,depart,arrivee,d.jour,d.mois,d.annee,duree,transport,nourriture,hebergement,&nbplacestotal,&nbplacesrestantes,&prix)!=EOF)

 			 {	strcpy(da,depart);
				strcat(da,"/");
				strcat(da,arrivee);
				strcpy(dte,d.jour);
				strcat(dte,"/");
				strcat(dte,d.mois);
				strcat(dte,"/");
				strcat(dte,d.annee);
				sprintf(places,"%d/%d",nbplacestotal,nbplacesrestantes);
				sprintf(prix1,"%d dt",prix);
				
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,ID,id,DA,da,DATE,dte,DUREE,duree,TRANSPORT,transport,HEBERGEMENT,hebergement,PLACES,places,PRIX,prix1,-1);
			}
			fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
			g_object_unref(store);
		}
		}
	

}






		void modifier_excursion(char identifiant[],Excursion em)
{
				strcpy(em.id,identifiant);
				supprimer_excursion(identifiant);
				ajouter_excursion(em);
}
