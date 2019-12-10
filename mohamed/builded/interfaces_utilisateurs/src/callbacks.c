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
#include <time.h>


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
	GtkWidget *treeview_emp;
	GtkWidget *treeview_client;

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

	//remplir gestion client admin
	treeview_client=lookup_widget(espace_admin,"treeview_client_admin");
	afficher_treeview_client_admin(treeview_client);

	//remplir gestion employee admin
	treeview_emp=lookup_widget(espace_admin,"treeview_employee_admin");
	afficher_treeview_employee_admin(treeview_emp);


}


void
on_button_modifier_profile_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	utilisateur u;
	utilisateur user;
	int A,B,C;
	char date[20];
	FILE* f=NULL;

	GtkWidget *entry_nom_profile_admin;
  	GtkWidget *entry_prenom_profile_admin;
  	GtkWidget *entry_pass_profile_admin;
	GtkWidget *entry_cin_profile_admin;
	GtkWidget *entry_identifiant_profile_admin;
	GtkWidget *label_naissance_profile_admin;

	entry_nom_profile_admin=lookup_widget(object,"entry_nom_profile_admin");
	entry_prenom_profile_admin=lookup_widget(object,"entry_prenom_profile_admin");
	entry_pass_profile_admin=lookup_widget(object,"entry_pass_profile_admin");
	entry_cin_profile_admin=lookup_widget(object,"entry_cin_profile_admin");
	entry_identifiant_profile_admin=lookup_widget(object,"entry_identifiant_profile_admin");
	label_naissance_profile_admin=lookup_widget(object,"label_naissance_profile_admin");

	strcpy(u.identifiant,gtk_entry_get_text(GTK_ENTRY(entry_identifiant_profile_admin)));
	strcpy(u.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(entry_pass_profile_admin)));
	strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom_profile_admin)));
	strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(entry_prenom_profile_admin)));
	strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(entry_cin_profile_admin)));

	strcpy(date,gtk_label_get_text(GTK_LABEL(label_naissance_profile_admin)));
	sscanf(date,"%d/%d/%d",&A,&B,&C);
	u.naissance.jour=A;
	u.naissance.mois=B;
	u.naissance.annee=C;

	f=fopen("utilisateurs.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %d %d %s %s \n",user.identifiant,user.mot_de_passe,user.nom,user.prenom,&user.naissance.jour,&user.naissance.mois,&user.naissance.annee,user.cin,user.role)!=EOF)
		{
			if(strcmp(user.identifiant,u.identifiant)==0)
				strcpy(u.role,user.role);
		}
	}

	supprimer_utilisateur(u.identifiant);
	ajouter_utilisateur(u);
	//zyd wyn code mtaa label information lena 
}


void
on_button_deconnecter_profile_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *espace_admin;
	GtkWidget *authentification_utilisateur;

	espace_admin=lookup_widget(object,"espace_admin");
	gtk_widget_destroy(espace_admin);
	authentification_utilisateur=lookup_widget(object,"authentification_utilisateur");
	authentification_utilisateur=create_authentification_utilisateur();
	gtk_widget_show(authentification_utilisateur);
}


void
on_button_search_employee_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ajouter_employee_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *ajouter_employee;
	GtkWidget *espace_admin;

	espace_admin=lookup_widget(object,"espace_admin");
	gtk_widget_destroy(espace_admin);

	ajouter_employee=lookup_widget(object,"ajouter_employee");
	ajouter_employee = create_ajouter_employee ();
  	gtk_widget_show (ajouter_employee);
}


void
on_button_supprimer_employee_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *supprimer_employee;
	GtkWidget *espace_admin;
	GtkWidget *combobox_supprimer_employer;

	int n,i;
	utilisateur T[50];

	espace_admin=lookup_widget(object,"espace_admin");
	supprimer_employee=lookup_widget(object,"supprimer_employee");

	supprimer_employee = create_supprimer_employee ();
  	gtk_widget_show (supprimer_employee);
	gtk_widget_destroy(espace_admin);

	/*combobox_supprimer_employer=lookup_widget(supprimer_employee,"combobox_supprimer_employer");
	n=remplir_combobox_numero(T);
	for(i=0;i<n;i++)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combobox_supprimer_employer),_(T[i].identifiant));*/
	
}

void
on_button_modifier_employee_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *choisir_identifiant_modifier_employee;
	GtkWidget *espace_admin;

	espace_admin=lookup_widget(object,"espace_admin");
	gtk_widget_destroy(espace_admin);

	choisir_identifiant_modifier_employee=lookup_widget(object,"choisir_identifiant_modifier_employee");
	choisir_identifiant_modifier_employee = create_choisir_identifiant_modifier_employee ();
  	gtk_widget_show (choisir_identifiant_modifier_employee);
}


void
on_button_ajouter_client_admin_clicked (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *ajouter_client_admin;
	GtkWidget *espace_admin;

	espace_admin=lookup_widget(object,"espace_admin");
	gtk_widget_destroy(espace_admin);

	ajouter_client_admin=lookup_widget(object,"ajouter_client_admin");
	ajouter_client_admin = create_ajouter_client_admin ();
  	gtk_widget_show (ajouter_client_admin);
}


void
on_button_supprimer_client_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *supprimer_client_admin;
	GtkWidget *espace_admin;

	espace_admin=lookup_widget(object,"espace_admin");
	supprimer_client_admin=lookup_widget(object,"supprimer_client_admin");

	supprimer_client_admin = create_supprimer_client_admin ();
  	gtk_widget_show (supprimer_client_admin);
	gtk_widget_destroy(espace_admin);
}


void
on_button_modifier_client_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *choisir_identifiant_modifier_client_admin;
	GtkWidget *espace_admin;

	espace_admin=lookup_widget(object,"espace_admin");
	gtk_widget_destroy(espace_admin);

	choisir_identifiant_modifier_client_admin=lookup_widget(object,"choisir_identifiant_modifier_client_admin");
	choisir_identifiant_modifier_client_admin = create_choisir_identifiant_modifier_client_admin();
  	gtk_widget_show (choisir_identifiant_modifier_client_admin);
}


void
on_button_modifier_profile_employee_clicked
                                        (GtkWidget    *object,
                                        gpointer         user_data)
{
	utilisateur u;
	utilisateur user;
	int A,B,C;
	char date[20];
	FILE* f=NULL;

	GtkWidget *entry_identifiant_profile_employee;
	GtkWidget *entry_nom_profile_employee;
	GtkWidget *entry_prenom_profile_employee;
	GtkWidget *entry_cin_profile_employee;
	GtkWidget *entry_pass_profile_employee;
	GtkWidget *label_naissance_profile_employee;
	GtkWidget *treeview_client_employee;

	entry_nom_profile_employee=lookup_widget(object,"entry_nom_profile_employee");
	entry_prenom_profile_employee=lookup_widget(object,"entry_prenom_profile_employee");
	entry_pass_profile_employee=lookup_widget(object,"entry_pass_profile_employee");
	entry_cin_profile_employee=lookup_widget(object,"entry_cin_profile_employee");
	entry_identifiant_profile_employee=lookup_widget(object,"entry_identifiant_profile_employee");
	label_naissance_profile_employee=lookup_widget(object,"label_naissance_profile_employee");

	strcpy(u.identifiant,gtk_entry_get_text(GTK_ENTRY(entry_identifiant_profile_employee)));
	strcpy(u.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(entry_pass_profile_employee)));
	strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom_profile_employee)));
	strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(entry_prenom_profile_employee)));
	strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(entry_cin_profile_employee)));

	strcpy(date,gtk_label_get_text(GTK_LABEL(label_naissance_profile_employee)));
	sscanf(date,"%d/%d/%d",&A,&B,&C);
	u.naissance.jour=A;
	u.naissance.mois=B;
	u.naissance.annee=C;

	f=fopen("utilisateurs.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %d %d %s %s \n",user.identifiant,user.mot_de_passe,user.nom,user.prenom,&user.naissance.jour,&user.naissance.mois,&user.naissance.annee,user.cin,user.role)!=EOF)
		{
			if(strcmp(user.identifiant,u.identifiant)==0)
				strcpy(u.role,user.role);
		}
	}

	supprimer_utilisateur(u.identifiant);
	ajouter_utilisateur(u);
	//zyd wyn code mtaa label information lena 
}


void
on_button_deconnecter_profile_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *espace_employee;
	GtkWidget *authentification_utilisateur;

	espace_employee=lookup_widget(object,"espace_employee");
	gtk_widget_destroy(espace_employee);
	authentification_utilisateur=lookup_widget(object,"authentification_utilisateur");
	authentification_utilisateur=create_authentification_utilisateur();
	gtk_widget_show(authentification_utilisateur);
}


void
on_button_ajouter_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *ajouter_client_employee;
	GtkWidget *espace_employee;

	espace_employee=lookup_widget(object,"espace_employee");
	gtk_widget_destroy(espace_employee);

	ajouter_client_employee=lookup_widget(object,"ajouter_client_employee");
	ajouter_client_employee = create_ajouter_client_employee ();
  	gtk_widget_show (ajouter_client_employee);
}


void
on_button_supprimer_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *espace_employee;
	GtkWidget *supprimer_client_employee;

	espace_employee=lookup_widget(object,"espace_employee");
	gtk_widget_destroy(espace_employee);
	supprimer_client_employee=lookup_widget(object,"supprimer_client_employee");
	supprimer_client_employee=create_supprimer_client_employee();
	gtk_widget_show(supprimer_client_employee);
}


void
on_button_modifier_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *espace_employee;
	GtkWidget *choisir_identifiant_modifier_client_employee;

	espace_employee=lookup_widget(object,"espace_employee");
	gtk_widget_destroy(espace_employee);
	choisir_identifiant_modifier_client_employee=lookup_widget(object,"choisir_identifiant_modifier_client_employee");
	choisir_identifiant_modifier_client_employee=create_choisir_identifiant_modifier_client_employee();
	gtk_widget_show(choisir_identifiant_modifier_client_employee);
}


void
on_button_deconnecter_profile_client_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *espace_client;
	GtkWidget *authentification_utilisateur;

	espace_client=lookup_widget(object,"espace_client");
	gtk_widget_destroy(espace_client);
	authentification_utilisateur=lookup_widget(object,"authentification_utilisateur");
	authentification_utilisateur=create_authentification_utilisateur();
	gtk_widget_show(authentification_utilisateur);
}


void
on_button_modifier_profile_client_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	utilisateur u;
	utilisateur user;
	int A,B,C;
	char date[20];
	FILE* f=NULL;

	GtkWidget *entry_nom_profile_client;
  	GtkWidget *entry_prenom_profile_client;
  	GtkWidget *entry_pass_profile_client;
	GtkWidget *entry_cin_profile_client;
	GtkWidget *entry_identifiant_profile_client;
	GtkWidget *label_naissance_profile_client;

	entry_nom_profile_client=lookup_widget(object,"entry_nom_profile_client");
	entry_prenom_profile_client=lookup_widget(object,"entry_prenom_profile_client");
	entry_pass_profile_client=lookup_widget(object,"entry_pass_profile_client");
	entry_cin_profile_client=lookup_widget(object,"entry_cin_profile_client");
	entry_identifiant_profile_client=lookup_widget(object,"entry_identifiant_profile_client");
	label_naissance_profile_client=lookup_widget(object,"label_naissance_profile_client");

	strcpy(u.identifiant,gtk_entry_get_text(GTK_ENTRY(entry_identifiant_profile_client)));
	strcpy(u.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(entry_pass_profile_client)));
	strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom_profile_client)));
	strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(entry_prenom_profile_client)));
	strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(entry_cin_profile_client)));

	strcpy(date,gtk_label_get_text(GTK_LABEL(label_naissance_profile_client)));
	sscanf(date,"%d/%d/%d",&A,&B,&C);
	u.naissance.jour=A;
	u.naissance.mois=B;
	u.naissance.annee=C;

	f=fopen("utilisateurs.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %d %d %s %s \n",user.identifiant,user.mot_de_passe,user.nom,user.prenom,&user.naissance.jour,&user.naissance.mois,&user.naissance.annee,user.cin,user.role)!=EOF)
		{
			if(strcmp(user.identifiant,u.identifiant)==0)
				strcpy(u.role,user.role);
		}
	}

	supprimer_utilisateur(u.identifiant);
	ajouter_utilisateur(u);
	//zyd wyn code mtaa label information lena 
}


void
on_button_identifiant_ajouter_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *entry_identifiant_ajouter_employee;

	char id[20];
	int A;

	do
	{

		A=generer_identifiant();
		sprintf(id,"U%d",A);

	}
	while(verifier_identifiant(id)==1);

	entry_identifiant_ajouter_employee=lookup_widget(object,"entry_identifiant_ajouter_employee");
	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_ajouter_employee),id);
}


void
on_button_annuler_ajouter_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *ajouter_employee;
	GtkWidget *espace_admin;

	ajouter_employee=lookup_widget(object,"ajouter_employee");
	gtk_widget_destroy(ajouter_employee);


	//code espace employee mriguel
	GtkWidget *entry_identifiant;
	GtkWidget *entry_nom_profile_admin;
  	GtkWidget *entry_prenom_profile_admin;
	GtkWidget *entry_cin_profile_admin;
	GtkWidget *entry_pass_profile_admin;
	GtkWidget *label_naissance_profile_admin;
	GtkWidget *entry_identifiant_profile_admin;
	GtkWidget *treeview_emp;
	GtkWidget *treeview_client;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	espace_admin=lookup_widget(object,"espace_admin");
	espace_admin = create_espace_admin ();
  	gtk_widget_show (espace_admin);


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

	//remplir gestion client admin
	treeview_client=lookup_widget(espace_admin,"treeview_client_admin");
	afficher_treeview_client_admin(treeview_client);

	//remplir gestion employee admin
	treeview_emp=lookup_widget(espace_admin,"treeview_employee_admin");
	afficher_treeview_employee_admin(treeview_emp);

}


void
on_button_valider_ajouter_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	utilisateur u;
	int A;
	
	GtkWidget *ajouter_employee;
	GtkWidget *confirmation_ajouter_employee;

	GtkWidget *entry_nom_ajouter_employee;
  	GtkWidget *entry_prenom_ajouter_employee;
  	GtkWidget *entry_pass_ajouter_employee;
	GtkWidget *entry_cin_ajouter_employee;
	GtkWidget *entry_identifiant_ajouter_employee;
	GtkWidget *spinbutton_jour_ajouter_employee;
	GtkWidget *spinbutton_mois_ajouter_employee;
	GtkWidget *spinbutton_annee_ajouter_employee;
	GtkWidget *combobox_role_ajouter_employee;

	entry_nom_ajouter_employee=lookup_widget(object,"entry_nom_ajouter_employee");
	entry_prenom_ajouter_employee=lookup_widget(object,"entry_prenom_ajouter_employee");
	entry_pass_ajouter_employee=lookup_widget(object,"entry_pass_ajouter_employee");
	entry_cin_ajouter_employee=lookup_widget(object,"entry_cin_ajouter_employee");
	entry_identifiant_ajouter_employee=lookup_widget(object,"entry_identifiant_ajouter_employee");
	spinbutton_jour_ajouter_employee=lookup_widget(object,"spinbutton_jour_ajouter_employee");
	spinbutton_mois_ajouter_employee=lookup_widget(object,"spinbutton_mois_ajouter_employee");
	spinbutton_annee_ajouter_employee=lookup_widget(object,"spinbutton_annee_ajouter_employee");
	combobox_role_ajouter_employee=lookup_widget(object,"combobox_role_ajouter_employee");

	strcpy(u.identifiant,gtk_entry_get_text(GTK_ENTRY(entry_identifiant_ajouter_employee)));
	strcpy(u.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(entry_pass_ajouter_employee)));
	strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom_ajouter_employee)));
	strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(entry_prenom_ajouter_employee)));
	strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(entry_cin_ajouter_employee)));

	strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_role_ajouter_employee)));

	if(strcmp(u.role,"Employee")==0)
		strcpy(u.role,"employee");
	
	if(strcmp(u.role,"Administrateur")==0)
		strcpy(u.role,"admin");

	u.naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_jour_ajouter_employee));
	u.naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_mois_ajouter_employee));
	u.naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_annee_ajouter_employee));

	ajouter_utilisateur(u);

	ajouter_employee=lookup_widget(object,"ajouter_employee");
	gtk_widget_destroy(ajouter_employee);
	confirmation_ajouter_employee=lookup_widget(object,"confirmation_ajouter_employee");
	confirmation_ajouter_employee = create_confirmation_ajouter_employee ();
  	gtk_widget_show (confirmation_ajouter_employee);
	
}


void
on_button_annuler_supprimer_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *espace_admin;
	GtkWidget *supprimer_employee;

	supprimer_employee=lookup_widget(object,"supprimer_employee");
	gtk_widget_destroy(supprimer_employee);

	//code espace client mriguel
	GtkWidget *entry_identifiant;
	GtkWidget *entry_nom_profile_admin;
  	GtkWidget *entry_prenom_profile_admin;
	GtkWidget *entry_cin_profile_admin;
	GtkWidget *entry_pass_profile_admin;
	GtkWidget *label_naissance_profile_admin;
	GtkWidget *entry_identifiant_profile_admin;
	GtkWidget *treeview_emp;
	GtkWidget *treeview_client;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	//destroy and show windows
	espace_admin=lookup_widget(object,"espace_admin");
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

	//remplir gestion client admin
	treeview_client=lookup_widget(espace_admin,"treeview_client_admin");
	afficher_treeview_client_admin(treeview_client);

	//remplir gestion employee admin
	treeview_emp=lookup_widget(espace_admin,"treeview_employee_admin");
	afficher_treeview_employee_admin(treeview_emp);
}


void
on_button_valider_supprimer_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_confirmation_ajouter_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *confirmation_ajouter_employee;
	GtkWidget *espace_admin;
	GtkWidget *confirmation_authentification_admin;

	GtkWidget *entry_identifiant;
	GtkWidget *entry_nom_profile_admin;
  	GtkWidget *entry_prenom_profile_admin;
	GtkWidget *entry_cin_profile_admin;
	GtkWidget *entry_pass_profile_admin;
	GtkWidget *label_naissance_profile_admin;
	GtkWidget *entry_identifiant_profile_admin;
	GtkWidget *treeview_emp;
	GtkWidget *treeview_client;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	confirmation_ajouter_employee=lookup_widget(object,"confirmation_ajouter_employee");
	gtk_widget_destroy(confirmation_ajouter_employee);


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

	//remplir gestion client admin
	treeview_client=lookup_widget(espace_admin,"treeview_client_admin");
	afficher_treeview_client_admin(treeview_client);

	//remplir gestion employee admin
	treeview_emp=lookup_widget(espace_admin,"treeview_employee_admin");
	afficher_treeview_employee_admin(treeview_emp);
}


void
on_button_confirmation_authentification_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *confirmation_authentification_employee;
  	GtkWidget *espace_employee;


	//code mriguel
	GtkWidget *entry_identifiant_profile_employee;
	GtkWidget *entry_nom_profile_employee;
	GtkWidget *entry_prenom_profile_employee;
	GtkWidget *entry_cin_profile_employee;
	GtkWidget *entry_pass_profile_employee;
	GtkWidget *label_naissance_profile_employee;
	GtkWidget *treeview_client_employee;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	espace_employee=lookup_widget(object,"espace_employee");
	confirmation_authentification_employee=lookup_widget(object,"confirmation_authentification_employee");
	gtk_widget_destroy(confirmation_authentification_employee);
	espace_employee = create_espace_employee ();
  	gtk_widget_show (espace_employee);

	entry_identifiant_profile_employee=lookup_widget(espace_employee,"entry_identifiant_profile_employee");
	entry_nom_profile_employee=lookup_widget(espace_employee,"entry_nom_profile_employee");
	entry_prenom_profile_employee=lookup_widget(espace_employee,"entry_prenom_profile_employee");
	entry_cin_profile_employee=lookup_widget(espace_employee,"entry_cin_profile_employee");
	entry_pass_profile_employee=lookup_widget(espace_employee,"entry_pass_profile_employee");
	label_naissance_profile_employee=lookup_widget(espace_employee,"label_naissance_profile_employee");
	treeview_client_employee=lookup_widget(espace_employee,"treeview_client_employee");

	f=fopen("actual_user.txt","r");
	if(f!=NULL)
		while(!feof(f))
			fscanf(f,"%s",id);
	fclose(f);
	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_profile_employee),id);

	f=fopen("utilisateurs.txt","r");
	if(f!=NULL)
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if(strcmp(id,u.identifiant)==0)
			{
				gtk_entry_set_text(GTK_ENTRY(entry_nom_profile_employee),u.nom);
				gtk_entry_set_text(GTK_ENTRY(entry_prenom_profile_employee),u.prenom);
				gtk_entry_set_text(GTK_ENTRY(entry_cin_profile_employee),u.cin);
				gtk_entry_set_text(GTK_ENTRY(entry_pass_profile_employee),u.mot_de_passe);
				sprintf(naissance,"%d/%d/%d",u.naissance.jour,u.naissance.mois,u.naissance.annee);
				gtk_label_set_text(GTK_LABEL(label_naissance_profile_employee),naissance);
			}
		}
	fclose(f);

	treeview_client_employee=lookup_widget(espace_employee,"treeview_client_employee");
	afficher_treeview_client_admin(treeview_client_employee);
}


void
on_button_confirmation_authentification_client_clicked
                                        (GtkWidget      *object,
                                        gpointer         user_data)
{
	GtkWidget *confirmation_authentification_client;
	GtkWidget *espace_client;

	GtkWidget *entry_identifiant_profile_client;
	GtkWidget *entry_nom_profile_client;
	GtkWidget *entry_prenom_profile_client;
	GtkWidget *entry_cin_profile_client;
	GtkWidget *entry_pass_profile_client;
	GtkWidget *label_naissance_profile_client;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	espace_client=lookup_widget(object,"espace_client");
	confirmation_authentification_client=lookup_widget(object,"confirmation_authentification_client");
	gtk_widget_destroy(confirmation_authentification_client);
	espace_client = create_espace_client ();
  	gtk_widget_show (espace_client);

	entry_identifiant_profile_client=lookup_widget(espace_client,"entry_identifiant_profile_client");
	entry_nom_profile_client=lookup_widget(espace_client,"entry_nom_profile_client");
	entry_prenom_profile_client=lookup_widget(espace_client,"entry_prenom_profile_client");
	entry_cin_profile_client=lookup_widget(espace_client,"entry_cin_profile_client");
	entry_pass_profile_client=lookup_widget(espace_client,"entry_pass_profile_client");
	label_naissance_profile_client=lookup_widget(espace_client,"label_naissance_profile_client");

	f=fopen("actual_user.txt","r");
	if(f!=NULL)
		while(!feof(f))
			fscanf(f,"%s",id);
	fclose(f);
	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_profile_client),id);

	f=fopen("utilisateurs.txt","r");
	if(f!=NULL)
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if(strcmp(id,u.identifiant)==0)
			{
				gtk_entry_set_text(GTK_ENTRY(entry_nom_profile_client),u.nom);
				gtk_entry_set_text(GTK_ENTRY(entry_prenom_profile_client),u.prenom);
				gtk_entry_set_text(GTK_ENTRY(entry_cin_profile_client),u.cin);
				gtk_entry_set_text(GTK_ENTRY(entry_pass_profile_client),u.mot_de_passe);
				sprintf(naissance,"%d/%d/%d",u.naissance.jour,u.naissance.mois,u.naissance.annee);
				gtk_label_set_text(GTK_LABEL(label_naissance_profile_client),naissance);
			}
		}
	fclose(f);
}

//mizel
void
on_button_confirmation_supprimer_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

//mizel
void
on_button_valider_modifier_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

//mizel
void
on_button_annuler_modifier_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	


}

//mizel
void
on_button_confirmation_modifier_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_ajouter_client_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *ajouter_client_admin;
	GtkWidget *espace_admin;

	ajouter_client_admin=lookup_widget(object,"ajouter_client_admin");
	gtk_widget_destroy(ajouter_client_admin);


	//code espace client mriguel
	GtkWidget *entry_identifiant;
	GtkWidget *entry_nom_profile_admin;
  	GtkWidget *entry_prenom_profile_admin;
	GtkWidget *entry_cin_profile_admin;
	GtkWidget *entry_pass_profile_admin;
	GtkWidget *label_naissance_profile_admin;
	GtkWidget *entry_identifiant_profile_admin;
	GtkWidget *treeview_emp;
	GtkWidget *treeview_client;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	//destroy and show windows
	espace_admin=lookup_widget(object,"espace_admin");
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

	//remplir gestion client admin
	treeview_client=lookup_widget(espace_admin,"treeview_client_admin");
	afficher_treeview_client_admin(treeview_client);

	//remplir gestion employee admin
	treeview_emp=lookup_widget(espace_admin,"treeview_employee_admin");
	afficher_treeview_employee_admin(treeview_emp);
}


void
on_button_valider_ajouter_client_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	utilisateur u;
	int A;
	
	GtkWidget *ajouter_client_admin;
	GtkWidget *confirmation_ajouter_client_admin;

	GtkWidget *entry_nom_ajouter_client_admin;
  	GtkWidget *entry_prenom_ajouter_client_admin;
  	GtkWidget *entry_pass_ajouter_client_admin;
	GtkWidget *entry_cin_ajouter_client_admin;
	GtkWidget *entry_identifiant_ajouter_client_admin;
	GtkWidget *spinbutton_jour_ajouter_client_admin;
	GtkWidget *spinbutton_mois_ajouter_client_admin;
	GtkWidget *spinbutton_annee_ajouter_client_admin;
	GtkWidget *combobox_role_ajouter_client_admin;

	entry_nom_ajouter_client_admin=lookup_widget(object,"entry_nom_ajouter_client_admin");
	entry_prenom_ajouter_client_admin=lookup_widget(object,"entry_prenom_ajouter_client_admin");
	entry_pass_ajouter_client_admin=lookup_widget(object,"entry_pass_ajouter_client_admin");
	entry_cin_ajouter_client_admin=lookup_widget(object,"entry_cin_ajouter_client_admin");
	entry_identifiant_ajouter_client_admin=lookup_widget(object,"entry_identifiant_ajouter_client_admin");
	spinbutton_jour_ajouter_client_admin=lookup_widget(object,"spinbutton_jour_ajouter_client_admin");
	spinbutton_mois_ajouter_client_admin=lookup_widget(object,"spinbutton_mois_ajouter_client_admin");
	spinbutton_annee_ajouter_client_admin=lookup_widget(object,"spinbutton_annee_ajouter_client_admin");
	combobox_role_ajouter_client_admin=lookup_widget(object,"combobox_role_ajouter_client_admin");

	strcpy(u.identifiant,gtk_entry_get_text(GTK_ENTRY(entry_identifiant_ajouter_client_admin)));
	strcpy(u.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(entry_pass_ajouter_client_admin)));
	strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom_ajouter_client_admin)));
	strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(entry_prenom_ajouter_client_admin)));
	strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(entry_cin_ajouter_client_admin)));

	strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_role_ajouter_client_admin)));

	strcpy(u.role,"client");


	u.naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_jour_ajouter_client_admin));
	u.naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_mois_ajouter_client_admin));
	u.naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_annee_ajouter_client_admin));

	ajouter_utilisateur(u);

	ajouter_client_admin=lookup_widget(object,"ajouter_client_admin");
	gtk_widget_destroy(ajouter_client_admin);
	confirmation_ajouter_client_admin=lookup_widget(object,"confirmation_ajouter_client_admin");
	confirmation_ajouter_client_admin = create_confirmation_ajouter_client_admin ();
  	gtk_widget_show (confirmation_ajouter_client_admin);
	
}


void
on_button_identifiant_ajouter_client_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *entry_identifiant_ajouter_client_admin;

	char id[20];
	int A;

	do
	{

		A=generer_identifiant();
		sprintf(id,"C%d",A);

	}
	while(verifier_identifiant(id)==1);

	entry_identifiant_ajouter_client_admin=lookup_widget(object,"entry_identifiant_ajouter_client_admin");
	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_ajouter_client_admin),id);
}


void
on_button_confirmation_ajouter_client_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
  	GtkWidget *confirmation_ajouter_client_admin;
	GtkWidget *espace_admin;

	GtkWidget *entry_identifiant;
	GtkWidget *entry_nom_profile_admin;
  	GtkWidget *entry_prenom_profile_admin;
	GtkWidget *entry_cin_profile_admin;
	GtkWidget *entry_pass_profile_admin;
	GtkWidget *label_naissance_profile_admin;
	GtkWidget *entry_identifiant_profile_admin;
	GtkWidget *treeview_emp;
	GtkWidget *treeview_client;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	confirmation_ajouter_client_admin=lookup_widget(object,"confirmation_ajouter_client_admin");
	gtk_widget_destroy(confirmation_ajouter_client_admin);


	//show window espace admin
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

	//remplir gestion client admin
	treeview_client=lookup_widget(espace_admin,"treeview_client_admin");
	afficher_treeview_client_admin(treeview_client);

	//remplir gestion employee admin
	treeview_emp=lookup_widget(espace_admin,"treeview_employee_admin");
	afficher_treeview_employee_admin(treeview_emp);
}


void
on_button_annuler_supprimer_client_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *espace_admin;
	GtkWidget *supprimer_client_admin;

	supprimer_client_admin=lookup_widget(object,"supprimer_client_admin");
	gtk_widget_destroy(supprimer_client_admin);

	//code espace client mriguel
	GtkWidget *entry_identifiant;
	GtkWidget *entry_nom_profile_admin;
  	GtkWidget *entry_prenom_profile_admin;
	GtkWidget *entry_cin_profile_admin;
	GtkWidget *entry_pass_profile_admin;
	GtkWidget *label_naissance_profile_admin;
	GtkWidget *entry_identifiant_profile_admin;
	GtkWidget *treeview_emp;
	GtkWidget *treeview_client;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	//destroy and show windows
	espace_admin=lookup_widget(object,"espace_admin");
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

	//remplir gestion client admin
	treeview_client=lookup_widget(espace_admin,"treeview_client_admin");
	afficher_treeview_client_admin(treeview_client);

	//remplir gestion employee admin
	treeview_emp=lookup_widget(espace_admin,"treeview_employee_admin");
	afficher_treeview_employee_admin(treeview_emp);
}

//mizel
void
on_button_valider_supprimer_client_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

//mizel
void
on_button_confirmation_supprimer_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

//mizel
void
on_button_annuler_modifier_client_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{

}

//mizel
void
on_button_valider_modifier_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

//mizel
void
on_button_confirmation_modifier_client_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_identifiant_ajouter_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *entry_identifiant_ajouter_client_employee;

	char id[20];
	int A;

	do
	{

		A=generer_identifiant();
		sprintf(id,"C%d",A);

	}
	while(verifier_identifiant(id)==1);

	entry_identifiant_ajouter_client_employee=lookup_widget(object,"entry_identifiant_ajouter_client_employee");
	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_ajouter_client_employee),id);

}


void
on_button_annuler_ajouter_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *ajouter_client_employee;
	GtkWidget *espace_employee;

	ajouter_client_employee=lookup_widget(object,"ajouter_client_employee");
	gtk_widget_destroy(ajouter_client_employee);
	
	//code mriguel
	GtkWidget *entry_identifiant_profile_employee;
	GtkWidget *entry_nom_profile_employee;
	GtkWidget *entry_prenom_profile_employee;
	GtkWidget *entry_cin_profile_employee;
	GtkWidget *entry_pass_profile_employee;
	GtkWidget *label_naissance_profile_employee;
	GtkWidget *treeview_client_employee;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	espace_employee=lookup_widget(object,"espace_employee");

	espace_employee = create_espace_employee ();
  	gtk_widget_show (espace_employee);

	entry_identifiant_profile_employee=lookup_widget(espace_employee,"entry_identifiant_profile_employee");
	entry_nom_profile_employee=lookup_widget(espace_employee,"entry_nom_profile_employee");
	entry_prenom_profile_employee=lookup_widget(espace_employee,"entry_prenom_profile_employee");
	entry_cin_profile_employee=lookup_widget(espace_employee,"entry_cin_profile_employee");
	entry_pass_profile_employee=lookup_widget(espace_employee,"entry_pass_profile_employee");
	label_naissance_profile_employee=lookup_widget(espace_employee,"label_naissance_profile_employee");
	treeview_client_employee=lookup_widget(espace_employee,"treeview_client_employee");

	f=fopen("actual_user.txt","r");
	if(f!=NULL)
		while(!feof(f))
			fscanf(f,"%s",id);
	fclose(f);
	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_profile_employee),id);

	f=fopen("utilisateurs.txt","r");
	if(f!=NULL)
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if(strcmp(id,u.identifiant)==0)
			{
				gtk_entry_set_text(GTK_ENTRY(entry_nom_profile_employee),u.nom);
				gtk_entry_set_text(GTK_ENTRY(entry_prenom_profile_employee),u.prenom);
				gtk_entry_set_text(GTK_ENTRY(entry_cin_profile_employee),u.cin);
				gtk_entry_set_text(GTK_ENTRY(entry_pass_profile_employee),u.mot_de_passe);
				sprintf(naissance,"%d/%d/%d",u.naissance.jour,u.naissance.mois,u.naissance.annee);
				gtk_label_set_text(GTK_LABEL(label_naissance_profile_employee),naissance);
			}
		}
	fclose(f);

	treeview_client_employee=lookup_widget(espace_employee,"treeview_client_employee");
	afficher_treeview_client_admin(treeview_client_employee);
}


void
on_button_valider_ajouter_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	utilisateur u;
	int A;
	
	GtkWidget *ajouter_client_employee;
	GtkWidget *confirmation_ajouter_client_employee;

	GtkWidget *entry_nom_ajouter_client_employee;
  	GtkWidget *entry_prenom_ajouter_client_employee;
  	GtkWidget *entry_pass_ajouter_client_employee;
	GtkWidget *entry_cin_ajouter_client_employee;
	GtkWidget *entry_identifiant_ajouter_client_employee;
	GtkWidget *spinbutton_jour_ajouter_client_employee;
	GtkWidget *spinbutton_mois_ajouter_client_employee;
	GtkWidget *spinbutton_annee_ajouter_client_employee;
	GtkWidget *combobox_role_ajouter_client_employee;

	entry_nom_ajouter_client_employee=lookup_widget(object,"entry_nom_ajouter_client_employee");
	entry_prenom_ajouter_client_employee=lookup_widget(object,"entry_prenom_ajouter_client_employee");
	entry_pass_ajouter_client_employee=lookup_widget(object,"entry_pass_ajouter_client_employee");
	entry_cin_ajouter_client_employee=lookup_widget(object,"entry_cin_ajouter_client_employee");
	entry_identifiant_ajouter_client_employee=lookup_widget(object,"entry_identifiant_ajouter_client_employee");
	spinbutton_jour_ajouter_client_employee=lookup_widget(object,"spinbutton_jour_ajouter_client_employee");
	spinbutton_mois_ajouter_client_employee=lookup_widget(object,"spinbutton_mois_ajouter_client_employee");
	spinbutton_annee_ajouter_client_employee=lookup_widget(object,"spinbutton_annee_ajouter_client_employee");
	combobox_role_ajouter_client_employee=lookup_widget(object,"combobox_role_ajouter_client_employee");

	strcpy(u.identifiant,gtk_entry_get_text(GTK_ENTRY(entry_identifiant_ajouter_client_employee)));
	strcpy(u.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(entry_pass_ajouter_client_employee)));
	strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom_ajouter_client_employee)));
	strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(entry_prenom_ajouter_client_employee)));
	strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(entry_cin_ajouter_client_employee)));

	strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_role_ajouter_client_employee)));

	strcpy(u.role,"client");
	
	u.naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_jour_ajouter_client_employee));
	u.naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_mois_ajouter_client_employee));
	u.naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_annee_ajouter_client_employee));

	ajouter_utilisateur(u);

	ajouter_client_employee=lookup_widget(object,"ajouter_client_employee");
	gtk_widget_destroy(ajouter_client_employee);
	confirmation_ajouter_client_employee=lookup_widget(object,"confirmation_ajouter_client_employee");
	confirmation_ajouter_client_employee = create_confirmation_ajouter_client_employee ();
  	gtk_widget_show (confirmation_ajouter_client_employee);
}


void
on_button_confirmation_ajouter_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *confirmation_ajouter_client_employee;
	GtkWidget *espace_employee;

	confirmation_ajouter_client_employee=lookup_widget(object,"confirmation_ajouter_client_employee");
	gtk_widget_destroy(confirmation_ajouter_client_employee);
	
	//code mriguel
	GtkWidget *entry_identifiant_profile_employee;
	GtkWidget *entry_nom_profile_employee;
	GtkWidget *entry_prenom_profile_employee;
	GtkWidget *entry_cin_profile_employee;
	GtkWidget *entry_pass_profile_employee;
	GtkWidget *label_naissance_profile_employee;
	GtkWidget *treeview_client_employee;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	espace_employee=lookup_widget(object,"espace_employee");

	espace_employee = create_espace_employee ();
  	gtk_widget_show (espace_employee);

	entry_identifiant_profile_employee=lookup_widget(espace_employee,"entry_identifiant_profile_employee");
	entry_nom_profile_employee=lookup_widget(espace_employee,"entry_nom_profile_employee");
	entry_prenom_profile_employee=lookup_widget(espace_employee,"entry_prenom_profile_employee");
	entry_cin_profile_employee=lookup_widget(espace_employee,"entry_cin_profile_employee");
	entry_pass_profile_employee=lookup_widget(espace_employee,"entry_pass_profile_employee");
	label_naissance_profile_employee=lookup_widget(espace_employee,"label_naissance_profile_employee");
	treeview_client_employee=lookup_widget(espace_employee,"treeview_client_employee");

	f=fopen("actual_user.txt","r");
	if(f!=NULL)
		while(!feof(f))
			fscanf(f,"%s",id);
	fclose(f);
	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_profile_employee),id);

	f=fopen("utilisateurs.txt","r");
	if(f!=NULL)
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if(strcmp(id,u.identifiant)==0)
			{
				gtk_entry_set_text(GTK_ENTRY(entry_nom_profile_employee),u.nom);
				gtk_entry_set_text(GTK_ENTRY(entry_prenom_profile_employee),u.prenom);
				gtk_entry_set_text(GTK_ENTRY(entry_cin_profile_employee),u.cin);
				gtk_entry_set_text(GTK_ENTRY(entry_pass_profile_employee),u.mot_de_passe);
				sprintf(naissance,"%d/%d/%d",u.naissance.jour,u.naissance.mois,u.naissance.annee);
				gtk_label_set_text(GTK_LABEL(label_naissance_profile_employee),naissance);
			}
		}
	fclose(f);

	treeview_client_employee=lookup_widget(espace_employee,"treeview_client_employee");
	afficher_treeview_client_admin(treeview_client_employee);
}

//mizel
void
on_button_annuler_modifier_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{

}

//mizel
void
on_button_valider_modifier_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

//mizel
void
on_button_confirmation_modifier_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_supprimer_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *supprimer_client_employee;;
	GtkWidget *espace_employee;

	supprimer_client_employee=lookup_widget(object,"supprimer_client_employee");
	gtk_widget_destroy(supprimer_client_employee);
	
	//code mriguel
	GtkWidget *entry_identifiant_profile_employee;
	GtkWidget *entry_nom_profile_employee;
	GtkWidget *entry_prenom_profile_employee;
	GtkWidget *entry_cin_profile_employee;
	GtkWidget *entry_pass_profile_employee;
	GtkWidget *label_naissance_profile_employee;
	GtkWidget *treeview_client_employee;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	espace_employee=lookup_widget(object,"espace_employee");

	espace_employee = create_espace_employee ();
  	gtk_widget_show (espace_employee);

	entry_identifiant_profile_employee=lookup_widget(espace_employee,"entry_identifiant_profile_employee");
	entry_nom_profile_employee=lookup_widget(espace_employee,"entry_nom_profile_employee");
	entry_prenom_profile_employee=lookup_widget(espace_employee,"entry_prenom_profile_employee");
	entry_cin_profile_employee=lookup_widget(espace_employee,"entry_cin_profile_employee");
	entry_pass_profile_employee=lookup_widget(espace_employee,"entry_pass_profile_employee");
	label_naissance_profile_employee=lookup_widget(espace_employee,"label_naissance_profile_employee");
	treeview_client_employee=lookup_widget(espace_employee,"treeview_client_employee");

	f=fopen("actual_user.txt","r");
	if(f!=NULL)
		while(!feof(f))
			fscanf(f,"%s",id);
	fclose(f);
	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_profile_employee),id);

	f=fopen("utilisateurs.txt","r");
	if(f!=NULL)
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if(strcmp(id,u.identifiant)==0)
			{
				gtk_entry_set_text(GTK_ENTRY(entry_nom_profile_employee),u.nom);
				gtk_entry_set_text(GTK_ENTRY(entry_prenom_profile_employee),u.prenom);
				gtk_entry_set_text(GTK_ENTRY(entry_cin_profile_employee),u.cin);
				gtk_entry_set_text(GTK_ENTRY(entry_pass_profile_employee),u.mot_de_passe);
				sprintf(naissance,"%d/%d/%d",u.naissance.jour,u.naissance.mois,u.naissance.annee);
				gtk_label_set_text(GTK_LABEL(label_naissance_profile_employee),naissance);
			}
		}
	fclose(f);

	treeview_client_employee=lookup_widget(espace_employee,"treeview_client_employee");
	afficher_treeview_client_admin(treeview_client_employee);
}

//mizel
void
on_button_valider_supprimer_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

//mizel
void
on_button_confirmation_supprimer_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_identifiant_modifier_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *choisir_identifiant_modifier_employee;
	GtkWidget *espace_admin;

	choisir_identifiant_modifier_employee=lookup_widget(object,"choisir_identifiant_modifier_employee");
	gtk_widget_destroy(choisir_identifiant_modifier_employee);

	//code espace client mriguel
	GtkWidget *entry_identifiant;
	GtkWidget *entry_nom_profile_admin;
  	GtkWidget *entry_prenom_profile_admin;
	GtkWidget *entry_cin_profile_admin;
	GtkWidget *entry_pass_profile_admin;
	GtkWidget *label_naissance_profile_admin;
	GtkWidget *entry_identifiant_profile_admin;
	GtkWidget *treeview_emp;
	GtkWidget *treeview_client;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	//destroy and show windows
	espace_admin=lookup_widget(object,"espace_admin");
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

	//remplir gestion client admin
	treeview_client=lookup_widget(espace_admin,"treeview_client_admin");
	afficher_treeview_client_admin(treeview_client);

	//remplir gestion employee admin
	treeview_emp=lookup_widget(espace_admin,"treeview_employee_admin");
	afficher_treeview_employee_admin(treeview_emp);

}

//mizel
void
on_button_valider_identifiant_modifier_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_identifiant_modifier_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *choisir_identifiant_modifier_client_employee;
	GtkWidget *espace_employee;
	choisir_identifiant_modifier_client_employee=lookup_widget(object,"choisir_identifiant_modifier_client_employee");
	gtk_widget_destroy(choisir_identifiant_modifier_client_employee);

	//code mriguel
	GtkWidget *entry_identifiant_profile_employee;
	GtkWidget *entry_nom_profile_employee;
	GtkWidget *entry_prenom_profile_employee;
	GtkWidget *entry_cin_profile_employee;
	GtkWidget *entry_pass_profile_employee;
	GtkWidget *label_naissance_profile_employee;
	GtkWidget *treeview_client_employee;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	espace_employee=lookup_widget(object,"espace_employee");

	espace_employee = create_espace_employee ();
  	gtk_widget_show (espace_employee);

	entry_identifiant_profile_employee=lookup_widget(espace_employee,"entry_identifiant_profile_employee");
	entry_nom_profile_employee=lookup_widget(espace_employee,"entry_nom_profile_employee");
	entry_prenom_profile_employee=lookup_widget(espace_employee,"entry_prenom_profile_employee");
	entry_cin_profile_employee=lookup_widget(espace_employee,"entry_cin_profile_employee");
	entry_pass_profile_employee=lookup_widget(espace_employee,"entry_pass_profile_employee");
	label_naissance_profile_employee=lookup_widget(espace_employee,"label_naissance_profile_employee");
	treeview_client_employee=lookup_widget(espace_employee,"treeview_client_employee");

	f=fopen("actual_user.txt","r");
	if(f!=NULL)
		while(!feof(f))
			fscanf(f,"%s",id);
	fclose(f);
	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_profile_employee),id);

	f=fopen("utilisateurs.txt","r");
	if(f!=NULL)
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if(strcmp(id,u.identifiant)==0)
			{
				gtk_entry_set_text(GTK_ENTRY(entry_nom_profile_employee),u.nom);
				gtk_entry_set_text(GTK_ENTRY(entry_prenom_profile_employee),u.prenom);
				gtk_entry_set_text(GTK_ENTRY(entry_cin_profile_employee),u.cin);
				gtk_entry_set_text(GTK_ENTRY(entry_pass_profile_employee),u.mot_de_passe);
				sprintf(naissance,"%d/%d/%d",u.naissance.jour,u.naissance.mois,u.naissance.annee);
				gtk_label_set_text(GTK_LABEL(label_naissance_profile_employee),naissance);
			}
		}
	fclose(f);

	treeview_client_employee=lookup_widget(espace_employee,"treeview_client_employee");
	afficher_treeview_client_admin(treeview_client_employee);
}

//mizel
void
on_button_valider_identifiant_modifier_client_employee_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}

//mizel
void
on_button_valider_identifiant_modifier_client_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_annuler_identifiant_modifier_client_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *choisir_identifiant_modifier_client_admin;
	GtkWidget *espace_admin;

	choisir_identifiant_modifier_client_admin=lookup_widget(object,"choisir_identifiant_modifier_client_admin");
	gtk_widget_destroy(choisir_identifiant_modifier_client_admin);

	//code espace client mriguel
	GtkWidget *entry_identifiant;
	GtkWidget *entry_nom_profile_admin;
  	GtkWidget *entry_prenom_profile_admin;
	GtkWidget *entry_cin_profile_admin;
	GtkWidget *entry_pass_profile_admin;
	GtkWidget *label_naissance_profile_admin;
	GtkWidget *entry_identifiant_profile_admin;
	GtkWidget *treeview_emp;
	GtkWidget *treeview_client;

	FILE* f=NULL;
	char id[100];
	char naissance[100];
	utilisateur u;

	//destroy and show windows
	espace_admin=lookup_widget(object,"espace_admin");
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

	//remplir gestion client admin
	treeview_client=lookup_widget(espace_admin,"treeview_client_admin");
	afficher_treeview_client_admin(treeview_client);

	//remplir gestion employee admin
	treeview_emp=lookup_widget(espace_admin,"treeview_employee_admin");
	afficher_treeview_employee_admin(treeview_emp);

}

