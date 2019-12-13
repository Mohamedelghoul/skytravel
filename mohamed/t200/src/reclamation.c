#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reclamation.h"
#include <gtk/gtk.h>



void ajouter_reclamation(reclamation r)
{
FILE* f;
f=fopen("reclamation.txt","a");
if (f!=NULL)
{
fprintf(f,"%d %s %s %d %d %d %s %s %s \n",r.id_rec,r.id_client,r.type,r.date.jour,r.date.mois,r.date.annee,r.etat,r.text,r.reponse);
fclose(f);
}
}
void supprimer_reclamation(int R)
{
reclamation r;
char fichier[30];
sprintf(fichier,"t%d.txt",R);
remove(fichier);
sprintf(fichier,"r%d.txt",R);
remove(fichier);
FILE *fichierIN=NULL;
FILE *fichierOUT=NULL;
if((fichierIN=fopen("reclamation.txt","r"))==NULL)
printf("erreur ouverture fichier lecture supprimer\n");
if((fichierOUT=fopen("reclamation_copie.txt","w"))==NULL)
{
fclose(fichierIN);
printf("erreur ouverture fichier ecriture supprimer\n");
}
while(fscanf(fichierIN,"%d %s %s %d %d %d %s %s %s \n",&r.id_rec,r.id_client,r.type,&r.date.jour,&r.date.mois,&r.date.annee,r.etat,r.text,r.reponse)!=EOF)
{
if (R!=r.id_rec)
{
fprintf(fichierOUT,"%d %s %s %d %d %d %s %s %s \n",r.id_rec,r.id_client,r.type,r.date.jour,r.date.mois,r.date.annee,r.etat,r.text,r.reponse);
}}
fclose(fichierIN);
fclose(fichierOUT);
remove("reclamation.txt");
rename("reclamation_copie.txt","reclamation.txt");
}
int calculer_reclamation()
{
reclamation r;
int nb=100;
FILE* f=NULL;
f=fopen("reclamation.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%d %s %s %d %d %d %s %s %s \n",&r.id_rec,r.id_client,r.type,&r.date.jour,&r.date.mois,&r.date.annee,r.etat,r.text,r.reponse)!=EOF)
{
nb++;
}
}
fclose(f);
return nb;
}

char get_text_file(char txt[])
{
	char a[20];
	char b[1000]="\0";
	FILE* f=NULL;
	f=fopen(txt,"r");
	while(!feof(f))
	{
		fscanf(f,"%s ",a);
		strcat(b,a);
		strcat(b," ");
	}
	fclose(f);
	return b;
}
void set_text_file(char fichiertxt[], char text[])
{
	FILE* f=NULL;
	f=fopen(fichiertxt,"w");
	fprintf(f,"%s",text);
	fclose(f);
}
void afficher_reclamation_client(GtkWidget *liste)
{
	enum
	{
		ID_REC,
		TYPE,
		DATE,
		ETAT,
		COLUMNS
	};
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char idclient[20];
	char id_rec[20];
	char id_client[20];
	char type[20];
	char date[20];
	char etat[20];
	char text[20];
	char reponse[20];
	int jour,mois,annee;
	store=NULL;

	FILE *f=NULL;
	FILE *f1=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    ID Reclamation", renderer,"text",ID_REC,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Type",renderer, "text",TYPE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Etat", renderer, "text",ETAT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f=fopen("reclamation.txt","r");
		f1=fopen("actual_user.txt","r");
		

		if(f!=NULL)
		{
			if(f1!=NULL)
			{
				fscanf(f1,"%s",idclient);
				while(fscanf(f,"%s %s %s %d %d %d %s %s %s \n",id_rec,id_client,type,&jour,&mois,&annee,etat,text,reponse)!=EOF)
				{
					if(strcmp(id_client,idclient)==0)
					{
						if((strcmp(etat,"non_lu")==0) || (strcmp(etat,"lu")==0))
							{strcpy(etat,"envoyee");}
						sprintf(date,"%d/%d/%d",jour,mois,annee);	
						gtk_list_store_append(store,&iter);
						gtk_list_store_set(store, &iter, ID_REC, id_rec, TYPE, type, DATE, date, ETAT,etat,-1);
					}
				}
				fclose(f1);
			}
			fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
		}
	}
}

void afficher_reclamation_admin(GtkWidget *liste)
{
	enum
	{
		ID_REC,
		ID_CLIENT,
		TYPE,
		DATE,
		ETAT,
		COLUMNS
	};
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id_rec[20];
	char id_client[20];
	char type[20];
	char date[20];
	char etat[20];
	char text[20];
	char reponse[20];
	int jour,mois,annee;
	store=NULL;

	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    ID Reclamation", renderer,"text",ID_REC,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    ID Client",renderer, "text",ID_CLIENT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Type",renderer, "text",TYPE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Etat", renderer, "text",ETAT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);


		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f=fopen("reclamation.txt","r");

		if(f!=NULL)
		{
			while(fscanf(f,"%s %s %s %d %d %d %s %s %s \n",id_rec,id_client,type,&jour,&mois,&annee,etat,text,reponse)!=EOF)
			{
				if((strcmp(etat,"non_lu")==0) || (strcmp(etat,"lu")==0))
				{
					sprintf(date,"%d/%d/%d",jour,mois,annee);	
					gtk_list_store_append(store,&iter);
					gtk_list_store_set(store, &iter, ID_REC, id_rec, ID_CLIENT, id_client, TYPE, type, DATE, date, ETAT,etat,-1);
				}
			}
			fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
		}
	}
}

int remplir_combo_reclamation_client(char tab[50][50])
{
	int n=0;
	char idclient[20];
	char id_client[20];
	char id_rec[20];
	char type[20];
	char date[20];
	char etat[20];
	char text[20];
	char reponse[20];
	char jour[20];
	char mois[20];
	char annee[20];
	FILE* f=fopen("reclamation.txt","r");
	FILE* f1=fopen("actual_user.txt","r");
	if(f!=NULL)
	{
		if(f1!=NULL)
		{
			fscanf(f1,"%s",idclient);
			while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",id_rec,id_client,type,jour,mois,annee,etat,text,reponse)!=EOF)
			{
				if(strcmp(id_client,idclient)==0)
				{
					strcpy(tab[n],id_rec);
					n++;
				}
			}
		}
	fclose(f);
	}
	return n;
}

int remplir_combo_reclamation_admin(char tab[50][50])
{
	int n=0;
	char id_client[20];
	char id_rec[20];
	char type[20];
	char date[20];
	char etat[20];
	char text[20];
	char reponse[20];
	char jour[20];
	char mois[20];
	char annee[20];
	FILE* f=fopen("reclamation.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",id_rec,id_client,type,jour,mois,annee,etat,text,reponse)!=EOF)
		{
			if((strcmp(etat,"non_lu")==0) || (strcmp(etat,"lu")==0))
			{
				strcpy(tab[n],id_rec);
				n++;
			}
		}
	fclose(f);}
	return n;
}

int remplir_combo_type_reclamation(char tab[50][50])
{
	char id_rec[20];
	char id_client[20];
	char type[20];
	char date[20];
	char etat[20];
	char text[20];
	char reponse[20];
	char jour[20];
	char mois[20];
	char annee[20];
	int n=0;
	reclamation r;
	FILE* f=fopen("/home/tarek/Desktop/t200/src/reclamation.txt","r");
	if(f!=NULL)
	{
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",id_rec,id_client,type,jour,mois,annee,etat,text,reponse)!=EOF)
	{
		
		strcpy(tab[n],type);
		n++;
	}
	fclose(f);}
	return n;
}




