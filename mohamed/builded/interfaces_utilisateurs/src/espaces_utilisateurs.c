#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "espaces_utilisateurs.h"
#include <gtk/gtk.h>
#include <time.h>



void ajouter_utilisateur(utilisateur u)
{
	FILE* f=NULL;
	f=fopen("utilisateurs.txt","a");
	if(f!=NULL)
	{
		fprintf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,u.naissance.jour,u.naissance.mois,u.naissance.annee,u.cin,u.role);
		fclose(f);
		//compare_u.role
	}
}

int verifier_authentification (char user[], char pass[])
{
	FILE* f=NULL;
	utilisateur u;
	f=fopen("utilisateurs.txt","r");
	if(f !=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if(strcmp(user,u.identifiant)==0)
			{
				if(strcmp(pass,u.mot_de_passe)==0)
					{
						fclose(f);
						if(strcmp(u.role,"admin")==0)
							return(1);
						if(strcmp(u.role,"employee")==0)
							return(2);
						if(strcmp(u.role,"client")==0)
							return (3);
					}
			}
		}
		return(-1);
		fclose(f);
	}

}

void supprimer_utilisateur(char identifiant[])
{
	utilisateur u;
	FILE *fichierIn=NULL;
	FILE *fichierOut=NULL;
	fichierIn=fopen("utilisateurs.txt","r");
	fichierOut=fopen("utilisateurs_copie.txt","w");

	if(fichierIn!=NULL)
	{
		if(fichierOut!=NULL)
		{
			while(fscanf(fichierIn,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role)!=EOF)
			{
				if(strcmp(u.identifiant,identifiant)!=0)
					fprintf(fichierOut,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,u.naissance.jour,u.naissance.mois,u.naissance.annee,u.cin,u.role);
			}
		}
	}

	fclose(fichierIn);
	fclose(fichierOut);	
	remove("utilisateurs.txt");
	rename("utilisateurs_copie.txt","utilisateurs.txt");
}

int verifier_identifiant(char I[])
{
	utilisateur u;
	FILE* f=NULL;
	f=fopen("utilisateurs.txt","r");
	if(f !=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if (strcmp(I,u.identifiant)==0)
				return (1);
		}
	}
	return (0);
}
int generer_identifiant()
{
	int A;

	srand(time(NULL));
	A=rand()%90000;
	A=A+10000;
	return A;
}

void afficher_treeview_employee_admin(GtkWidget *liste)
{

	enum
	{
		IDENTIFIANT,
		NOM,
		PRENOM,	
		CIN,
		DATE,
		ROLE,
		COLUMNS
	};

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	FILE* f=NULL;
	char date[100]="\0";
	char identifiant[30];
	char mot_de_passe[30];
	char nom[30];
	char prenom[30];
	int jour,mois,annee;
	char cin[30];
	char role[30];

	
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Identifiant", renderer, "text",IDENTIFIANT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Nom",renderer, "text",NOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Prenom", renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    CIN", renderer,"text",CIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Date_de_naissance", renderer, "text",DATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Role", renderer, "text",ROLE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f=fopen("utilisateurs.txt","r");
		if(f!=NULL)
		{
			while(fscanf(f,"%s %s %s %s %d %d %d %s %s \n",identifiant,mot_de_passe,nom,prenom,&jour,&mois,&annee,cin,role)!=EOF)
			{
				if((strcmp(role,"admin")==0) || (strcmp(role,"employee")==0))
				{
					sprintf(date,"%d/%d/%d",jour,mois,annee);
					gtk_list_store_append(store,&iter);
					gtk_list_store_set(store, &iter, IDENTIFIANT,identifiant, NOM, nom, PRENOM, prenom, CIN, cin, DATE,date, ROLE,role,-1);
				}
			}
			fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
		}
	}
}

void afficher_treeview_client_admin(GtkWidget *liste)
{

	enum
	{
		IDENTIFIANT,
		NOM,
		PRENOM,	
		CIN,
		DATE,
		COLUMNS
	};

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	FILE* f=NULL;
	char date[100]="\0";
	char identifiant[30];
	char mot_de_passe[30];
	char nom[30];
	char prenom[30];
	int jour,mois,annee;
	char cin[30];
	char role[30];

	
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Identifiant", renderer, "text",IDENTIFIANT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Nom",renderer, "text",NOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Prenom", renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    CIN", renderer,"text",CIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("    Date_de_naissance", renderer, "text",DATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f=fopen("utilisateurs.txt","r");
		if(f!=NULL)
		{
			while(fscanf(f,"%s %s %s %s %d %d %d %s %s \n",identifiant,mot_de_passe,nom,prenom,&jour,&mois,&annee,cin,role)!=EOF)
			{
				if(strcmp(role,"client")==0)
				{
					sprintf(date,"%d/%d/%d",jour,mois,annee);
					gtk_list_store_append(store,&iter);
					gtk_list_store_set(store, &iter, IDENTIFIANT,identifiant, NOM, nom, PRENOM, prenom, CIN, cin, DATE,date,-1);
				}
			}
			fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
		}
	}
}

/*int remplir_combobox_numero(utilisateur T[])
{
	int n=0;
	FILE* f=NULL;
	f=fopen("utilisateur.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %d %d %s %s \n",T[n].identifiant,T[n].mot_de_passe,T[n].nom,T[n].prenom,&T[n].naissance.jour,&T[n].naissance.mois,&T[n].naissance.annee,T[n].cin,T[n].role)!=EOF);
		{n++;}
	}
	fclose(f);
	return n;


}*/




