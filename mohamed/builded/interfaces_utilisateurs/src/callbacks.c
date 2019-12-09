#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "espaces_utilisateurs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void
on_button_login_clicked                (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *authentification_utilisateur;
	GtkWidget *confirmation_authentification_admin;
	GtkWidget *confirmation_authentification_employee;
  	GtkWidget *confirmation_authentification_client;
	GtkWidget *entry_identifiant;
	GtkWidget *entry_pass;
	GtkWidget *error;
	
	int x;
	char user[100];	
	char pass[100];
	FILE* f=NULL;

	entry_identifiant=lookup_widget(object,"entry_identifiant");
	entry_pass=lookup_widget(object,"entry_pass");
	error=lookup_widget(object,"label_error_authentification");

	strcpy(user,gtk_entry_get_text (GTK_ENTRY(entry_identifiant)));
	strcpy(pass,gtk_entry_get_text (GTK_ENTRY(entry_pass)));
	x=verifier_authentification(user,pass);
	
	f=fopen("actual_user.txt","w");
	if(f!=NULL)
			fprintf(f,"%s",user);
	fclose(f);
	if(x==1)
	{
		authentification_utilisateur=lookup_widget(object,"authentification_utilisateur");
		gtk_widget_destroy(authentification_utilisateur);
		confirmation_authentification_admin = create_confirmation_authentification_admin ();
  		gtk_widget_show (confirmation_authentification_admin);
	}
	if(x==2)
	{
		authentification_utilisateur=lookup_widget(object,"authentification_utilisateur");
		gtk_widget_destroy(authentification_utilisateur);
		confirmation_authentification_employee = create_confirmation_authentification_employee ();
  		gtk_widget_show (confirmation_authentification_employee);
	}
	if(x==3)
	{
		authentification_utilisateur=lookup_widget(object,"authentification_utilisateur");
		gtk_widget_destroy(authentification_utilisateur);
		confirmation_authentification_client = create_confirmation_authentification_client ();
  		gtk_widget_show (confirmation_authentification_client);
	}
	if(x==-1)
	{
		gtk_label_set_text(GTK_LABEL(error),"Vos informations est incorrect ! ressayer autre fois.");
	}

}


void
on_button_confirmation_authentification_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	
	GtkWidget *espace_admin;
	GtkWidget *confirmation_authentification_admin;

	GtkWidget *entry_identifiant;
	GtkWidget *entry_nom_profile_admin;
  	GtkWidget *entry_prenom_profile_admin;
	GtkWidget *entry_cin_profile_admin;
	GtkWidget *entry_pass_profile_admin;
	GtkWidget *label_naissance_profile_admin;
	GtkWidget *entry_identifiant_profile_admin;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	//destroy and show windows
	espace_admin=lookup_widget(object,"espace_admin");
	confirmation_authentification_admin=lookup_widget(object,"confirmation_authentification_admin");
	gtk_widget_destroy(confirmation_authentification_admin);
	espace_admin = create_espace_admin ();
  	gtk_widget_show (espace_admin);

	//remplir mon profile admin
	entry_nom_profile_admin=lookup_widget(espace_admin,"entry_nom_profile_admin");
	entry_prenom_profile_admin=lookup_widget(espace_admin,"entry_prenom_profile_admin");
	entry_cin_profile_admin=lookup_widget(espace_admin,"entry_cin_profile_admin");
	entry_pass_profile_admin=lookup_widget(espace_admin,"entry_pass_profile_admin");
	label_naissance_profile_admin=lookup_widget(espace_admin,"label_naissance_profile_admin");
	entry_identifiant_profile_admin=lookup_widget(espace_admin,"entry_identifiant_profile_admin");

	f=fopen("actual_user.txt","r");
	if(f!=NULL)
		while(!feof(f))
			fscanf(f,"%s",id);
	fclose(f);
	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_profile_admin),id);

	f=fopen("utilisateurs.txt","r");
	if(f!=NULL)
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if(strcmp(id,u.identifiant)==0)
			{
				gtk_entry_set_text(GTK_ENTRY(entry_nom_profile_admin),u.nom);
				gtk_entry_set_text(GTK_ENTRY(entry_prenom_profile_admin),u.prenom);
				gtk_entry_set_text(GTK_ENTRY(entry_cin_profile_admin),u.cin);
				gtk_entry_set_text(GTK_ENTRY(entry_pass_profile_admin),u.mot_de_passe);
				sprintf(naissance,"%d/%d/%d",u.naissance.jour,u.naissance.mois,u.naissance.annee);
				gtk_label_set_text(GTK_LABEL(label_naissance_profile_admin),naissance);
			}
		}
	fclose(f);

	//remplir gestion employee
	GtkWidget *liste;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	char date[100];

	liste=lookup_widget(espace_admin,"treeview_employee_admin");
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

		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f=fopen("utilisateurs.txt","r");
		if(f!=NULL)
		{
			while(fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role)!=EOF)
			{
				if(strcmp(u.role,"client")!=0)
				{
					sprintf(date,"%d/%d/%d",u.naissance.jour,u.naissance.mois,u.naissance.annee);
					gtk_list_store_append(store,&iter);
					gtk_list_store_set(store, &iter, IDENTIFIANT,u.identifiant, NOM, u.nom, PRENOM, u.prenom, CIN, u.cin, DATE,date, ROLE,u.role,-1);
				}
			}
			fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
		}
	}
}


void
on_button_modifier_profile_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_deconnecter_profile_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_search_employee_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ajouter_employee_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_supprimer_employee_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_modifier_employee_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ajouter_client_admin_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_supprimer_client_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_modifier_client_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_deconnecter_profile_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_modifier_profile_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ajouter_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_supprimer_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_modifier_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_deconnecter_profile_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_modifier_profile_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_identifiant_ajouter_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_valider_ajouter_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_ajouter_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_valider_supprimer_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_supprimer_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirmation_ajouter_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirmation_authentification_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirmation_authentification_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirmation_supprimer_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_valider_modifier_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_modifier_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirmation_modifier_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_identifiant_ajouter_client_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_ajouter_client_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_valider_ajouter_client_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirmation_ajouter_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_valider_supprimer_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirmation_supprimer_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_modifier_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_valider_modifier_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirmation_modifier_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_ajouter_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_identifiant_ajouter_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_valider_ajouter_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirmation_ajouter_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_modifier_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_valider_modifier_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirmation_modifier_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_supprimer_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_valider_supprimer_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirmation_supprimer_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

