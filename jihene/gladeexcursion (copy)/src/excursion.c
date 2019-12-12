#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "excursion.h"
#include <time.h>


    
  int remplir_combo_id(char tab[50][50])
	{
		int n=0,j,k,l;
		char id_ex[30],a[20],b[20],c[20],d[20],e[20],ff[20],g[20],h[20],i[20];
		FILE* f=fopen("excursion.txt","r");
		if (f!=NULL)
		{
			 while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d %d %d \n",id_ex,a,b,c,d,e,ff,g,h,i,&j,&k,&l)!=EOF)
			{strcpy(tab[n],id_ex);
				n++;
		}
	fclose(f);}
	return n;
	}


   



   int nombre_ville(char pays[])
	{
	int var=0;

	if (strcmp(pays,"Allemagne ")==0)
		var=1;
	if (strcmp(pays,"France ")==0)
		var=2;
	if (strcmp(pays,"Turquie")==0)
		var=3;
	if (strcmp(pays,"Tunisie")==0)
		var=4;
	if (strcmp(pays,"Suisse")==0)
		var=5;
	if (strcmp(pays,"Espagne")==0)
		var=6;
	if (strcmp(pays,"Italie")==0)
		var=7;
	if (strcmp(pays,"Maroc")==0)
		var=8;
	return var;
	}

   
   int choix_villes(int n, char tab[50][20])
	{ int nb,i=0,k; char ville[20];
	  FILE* f=fopen("/home/jihene/Desktop/gladeexcursion/src/villes.txt","r");
	    if (f!=NULL)
            {
		while (fscanf(f,"%d %s \n",&nb,ville)!=EOF)
		   {	 
			if (nb==n) 
			{
				strcpy(tab[i],ville);
				i++;k++;
			}
		   }	
	
           }
			
	return k;

	}

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


int verifier_code1(char C[])
{
	char id[20];
	FILE* f=NULL;
	f=fopen("utilisateurs.txt","r");
	if(f !=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s",id);
			if (strcmp(C,id)==0)
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



int code_excursionr()
{
	int A;
	srand(time(NULL));
	A=rand()%9000;
	A=A+1000;
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



void ajouter_excursionr(Excursionr er)
{	Date1 d;
	FILE *f;
	f=fopen("excursionreservee.txt","a+");
	if(f!=NULL)

	{
	fprintf(f,"%s %s %s %s %s %s %s %s %d %d \n",er.identifiant,er.id_excursion,er.id_reservation,er.depart,er.arrivee,er.d.jour,er.d.mois,er.d.annee,er.personne,er.montant);
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
REPAS,
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
		column=gtk_tree_view_column_new_with_attributes("Repas",renderer,"text",REPAS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Disponibilité",renderer,"text",PLACES,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Prix",renderer,"text",PRIX,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
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
				gtk_list_store_set(store,&iter,ID,id,DA,da,DATE,dte,DUREE,duree,TRANSPORT,transport,HEBERGEMENT,hebergement,REPAS,nourriture,PLACES,places,PRIX,prix1,-1);
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





	void cherExcursion(char mak[],char rouna[],char rouna1[],char rouna2[],char rouna3[],char rouna4[],char rouna5[],char rouna6[],char rouna7[],char rouna8[],char rouna9[],char rouna10[],char rouna11[])
{
	char st1[20];char st2[20];
	char st3[20];char st4[20];char st5[20];char st6[20];
	char st7[20];char st8[20];char st9[20];char st10[20];
	char st11[20];char st12[20];char st13[20];
	
	FILE *f;
    f = fopen("excursion.txt", "r");
	if(f==NULL)
	{

		return;
	}		
	else 
    {
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,&st11,&st12,&st13)!=EOF)
        {
		if ((strcmp(mak,st1)==0))
		{
	strcpy(rouna,st2);
	strcpy(rouna1,st3);
	strcpy(rouna2,st4);
	strcpy(rouna3,st5);
	strcpy(rouna4,st6);
	strcpy(rouna5,st7);
	strcpy(rouna6,st8);
	strcpy(rouna7,st9);
	strcpy(rouna8,st10);
	strcpy(rouna9,st11);
	strcpy(rouna10,st12);
	strcpy(rouna11,st13);
			
		}
		}
    }
    fclose(f);
}
