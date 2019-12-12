#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include"hebergement.h"
#include "support.h"
#include "espaces_utilisateurs.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void
on_button105_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *window101;
GtkWidget *window104;
GtkWidget *Combobox100;
int n,i;
hotel  tab[50];

window101=lookup_widget(objet,"window101");
window104=create_window104();
gtk_widget_destroy(window101);
gtk_widget_show(window104);



Combobox100=lookup_widget(window104, "combobox100");

n=remplir_combo(tab);

	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox100),_(tab[i].ID));
	}



}


void
on_button100_activate                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button100_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window100;
 GtkWidget *window101;
 GtkWidget *treeview100;

 window100=lookup_widget(objet,"window100");
 window101=create_window101();
 treeview100=lookup_widget(window101,"treeview100");

 gtk_widget_destroy(window100);
 gtk_widget_show(window101);
 afficher_hotel(treeview100);





}


void
on_button106_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

hotel tab[50];

GtkWidget *window101;
GtkWidget *window105;
GtkWidget *Combobox10;
int n,i;


window101=lookup_widget(objet,"window101");
window105=create_window105();
gtk_widget_destroy(window101);
gtk_widget_show(window105);
Combobox10=lookup_widget(window105, "combobox101");

n=remplir_combo(tab);

	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox10),_(tab[i].ID));
	}


}


void
on_button117_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *Combobox101;
	GtkWidget *msg;
	char per[20];
	int i;
	


Combobox101=lookup_widget(objet,"combobox101");
msg=lookup_widget(objet,"label701");


strcpy(per,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox101)));
i=supprimer_hotel(per);





	if (i==0)
		gtk_label_set_text(GTK_LABEL(msg),"Suppression Réussie !");
	else
		gtk_label_set_text(GTK_LABEL(msg),"Hotel Deja supprime! !");



}


void
on_button104_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window101;
GtkWidget *window103;



window101=lookup_widget(objet,"window101");
window103=create_window103();
gtk_widget_destroy(window101);
gtk_widget_show(window103);

}


void
on_button111_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{

hotel h;
GtkWidget *input1,*input2,*input3,*input4;
GtkWidget *window1;
GtkWidget *kkk;
hotel tab[50];
int i,n;
int b;

window1=lookup_widget(objet,"window103");

input1=lookup_widget(objet,"entry4");
input2=lookup_widget(objet,"entry5");
input3=lookup_widget(objet,"entry6");
input4=lookup_widget(objet,"entry7");
kkk=lookup_widget(objet,"label702");


strcpy(h.ID,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(h.prix,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(h.adresse,gtk_entry_get_text(GTK_ENTRY(input4)));


n=verifier_code_hotel(h.ID);
if (n==0)
{
ajouter_hotel10(h);
gtk_label_set_text(GTK_LABEL(kkk),"Ajout avec succes");
}
else
gtk_label_set_text(GTK_LABEL(kkk),"ID deja existant!");

	


}


void
on_button115_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *Combobox50;
GtkWidget *window102;
GtkWidget *window104;
GtkWidget *msg;
char peri[20];


window104=lookup_widget(objet,"window104");
Combobox50=lookup_widget(objet,"combobox100");
strcpy(peri,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox50)));
window102 = create_window102 ();
gtk_widget_show (window102);
gtk_widget_destroy(window104);
msg=lookup_widget(window102,"label105");
gtk_label_set_text(GTK_LABEL(msg),peri);

}


void
on_button108_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *output;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *test;
	
	
	

	test=lookup_widget(objet,"label105");
	output=lookup_widget(objet,"label106");
	input1=lookup_widget(objet,"entry100");
	input2=lookup_widget(objet,"entry101");
	input3=lookup_widget(objet,"entry102");

	modifier_hotel(gtk_label_get_text(GTK_LABEL (test)),gtk_entry_get_text(GTK_ENTRY(input1)),
					   gtk_entry_get_text(GTK_ENTRY(input2)),
					   gtk_entry_get_text(GTK_ENTRY(input3)));


	gtk_label_set_text(GTK_LABEL(output),"Modification réussie ");
	

}


void
on_button107_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *window100;
GtkWidget *window101;



window101=lookup_widget(objet,"window101");
window100=create_window100();
gtk_widget_destroy(window101);
gtk_widget_show(window100);

}


void
on_button109_clicked                   (GtkWidget       *objet,
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

	espace_employee=lookup_widget(objet,"espace_employee");
	confirmation_authentification_employee=lookup_widget(objet,"confirmation_authentification_employee");
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

	//upload khedmet omar 

	GtkWidget *treeview101;
	treeview101=lookup_widget(espace_employee,"treeview101");


	afficher_hotel(treeview101);

	GtkWidget *window102;
	window102=lookup_widget(objet,"window102");
	gtk_widget_destroy(window102);

}


void
on_button110_clicked                   (GtkWidget       *objet,
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

	espace_employee=lookup_widget(objet,"espace_employee");
	confirmation_authentification_employee=lookup_widget(objet,"confirmation_authentification_employee");
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

	//upload khedmet omar 

	GtkWidget *treeview101;
	treeview101=lookup_widget(espace_employee,"treeview101");


	afficher_hotel(treeview101);

	GtkWidget *window102;
	window102=lookup_widget(objet,"window102");
	gtk_widget_destroy(window102);



}


void
on_button112_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window103;

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

	espace_employee=lookup_widget(objet,"espace_employee");
	confirmation_authentification_employee=lookup_widget(objet,"confirmation_authentification_employee");
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

	//upload khedmet omar 

	GtkWidget *treeview101;
	treeview101=lookup_widget(espace_employee,"treeview101");


	afficher_hotel(treeview101);



	window103=lookup_widget(objet,"window103");
	gtk_widget_destroy(window103);



}


void
on_button113_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window103;

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

	espace_employee=lookup_widget(objet,"espace_employee");
	confirmation_authentification_employee=lookup_widget(objet,"confirmation_authentification_employee");
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

	//upload khedmet omar 

	GtkWidget *treeview101;
	treeview101=lookup_widget(espace_employee,"treeview101");


	afficher_hotel(treeview101);



	window103=lookup_widget(objet,"window103");

	gtk_widget_destroy(window103);


}


void
on_button116_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{


	GtkWidget *window104;

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

	espace_employee=lookup_widget(objet,"espace_employee");
	confirmation_authentification_employee=lookup_widget(objet,"confirmation_authentification_employee");
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

	//upload khedmet omar 

	GtkWidget *treeview101;
	treeview101=lookup_widget(espace_employee,"treeview101");


	afficher_hotel(treeview101);


	window104=lookup_widget(objet,"window104");

	gtk_widget_destroy(window104);



}


void
on_button119_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{


	GtkWidget *window105;

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

	espace_employee=lookup_widget(objet,"espace_employee");
	confirmation_authentification_employee=lookup_widget(objet,"confirmation_authentification_employee");
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

	//upload khedmet omar 

	GtkWidget *treeview101;
	treeview101=lookup_widget(espace_employee,"treeview101");


	afficher_hotel(treeview101);


	window105=lookup_widget(objet,"window105");

	gtk_widget_destroy(window105);


}


void
on_button118_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window105;

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

	espace_employee=lookup_widget(objet,"espace_employee");
	confirmation_authentification_employee=lookup_widget(objet,"confirmation_authentification_employee");
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

	//upload khedmet omar 

	GtkWidget *treeview101;
	treeview101=lookup_widget(espace_employee,"treeview101");


	afficher_hotel(treeview101);


	window105=lookup_widget(objet,"window105");

	gtk_widget_destroy(window105);





}


void
on_button120_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{

GtkWidget *window101;
GtkWidget *window106;
GtkWidget *Combobox15;
hotel tab[50];
int n,i;




window101=lookup_widget(objet,"window101");
window106=create_window106();
gtk_widget_destroy(window101);
gtk_widget_show(window106);
Combobox15=lookup_widget(window106, "combobox102");
n=remplir_combo(tab);
occu(tab,n);

for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox15),_(tab[i].adresse));
	}






}


void
on_button121_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window107;
GtkWidget *window106;
GtkWidget *Combobox71;
GtkWidget *Combobox79;
char peris[20];


int n,i;
hotel tab[50];
hotel tab2[50];

window106=lookup_widget(objet,"window106");
Combobox79=lookup_widget(objet,"combobox102");
strcpy(peris,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox79)));
window107=create_window107();
gtk_widget_destroy(window106);
gtk_widget_show(window107);
Combobox71=lookup_widget(window107, "combobox103");
n=remplir_combo2(tab,tab2,peris);

for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox71),_(tab2[i].nom));
	}



}



void
on_button123_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window107;
GtkWidget *window108;
GtkWidget *Combobox69;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output8;
char perisa[20];
char testing[20];
char kool[20];
char cv[20];




window107=lookup_widget(objet,"window107");
Combobox69=lookup_widget(objet,"combobox103");
strcpy(perisa,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox69)));
window108=create_window108();
gtk_widget_destroy(window107);
gtk_widget_show(window108);
output5=lookup_widget(window108,"label713");
output6=lookup_widget(window108,"label715");
output7=lookup_widget(window108,"label717");
output8=lookup_widget(window108,"label719");
cherID(perisa,testing);
cherPrix(perisa,kool);
cherDesination(perisa,cv);

gtk_label_set_text(GTK_LABEL(output5),testing);
gtk_label_set_text(GTK_LABEL(output6),kool);
gtk_label_set_text(GTK_LABEL(output7),perisa);
gtk_label_set_text(GTK_LABEL(output8),cv);









}


void
on_button125_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window108;
GtkWidget *yala1;
GtkWidget *Combo1;
GtkWidget *per;
GtkWidget *yala2;
GtkWidget *yala3;
GtkWidget *yala4;
GtkWidget *enfant;
GtkWidget *byout;
int k;
float cofa;
int lll;
char emshi[20];
char emty[20];
int nbk;
int final;
char nombre[20];
int enf;
int cham;

window108=lookup_widget(objet,"window108");
yala1=lookup_widget(objet,"label715");
Combo1=lookup_widget(objet,"combobox106");
per=lookup_widget(objet,"spinbutton100");
yala2=lookup_widget(objet,"entry105");
yala3=lookup_widget(window108,"label729");
yala4=lookup_widget(window108,"label730");
enfant=lookup_widget(objet,"spinbutton3");
byout=lookup_widget(objet,"spinbutton101");

k=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (per));
enf=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (enfant));
cham=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (byout));
strcpy(emshi,gtk_label_get_text(GTK_LABEL (yala1)));

lll=atol(emshi);


if(strcmp("Complete",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combo1)))==0)
		cofa=1;
	else
		cofa=0.7;


strcpy(nombre,gtk_entry_get_text(GTK_ENTRY(yala2)));
nbk=atol(nombre);

final=getmontant(lll,nbk,k,cofa,enf,cham);
sprintf(emty,"%d",final);

gtk_label_set_text(GTK_LABEL(yala3),"Prix total de la reservation est");
gtk_label_set_text(GTK_LABEL(yala4),emty);



}


void
on_button126_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
reshotel r;
GtkWidget *input10,*input20,*input30,*input40,*input50,*enfant,*byout,*per,*Comboz,*Comboz2,*Comboz3,*input60;
GtkWidget *window177,*output;
GtkWidget *kkk;
hotel tab[50];
int k,enf,cham;
char emty1[20];
char emty2[20];
char emty3[20];

window177=lookup_widget(objet,"window108");

input10=lookup_widget(objet,"entry104");
input20=lookup_widget(objet,"entry103");
input30=lookup_widget(objet,"label713");
Comboz=lookup_widget(objet,"combobox104");
Comboz2=lookup_widget(objet,"combobox105");
input40=lookup_widget(objet,"label719");
input50=lookup_widget(objet,"label717");
enfant=lookup_widget(objet,"spinbutton3");
byout=lookup_widget(objet,"spinbutton101");
per=lookup_widget(objet,"spinbutton100");
Comboz3=lookup_widget(objet,"combobox106");
input60=lookup_widget(objet,"label730");
output=lookup_widget(objet,"label735");



k=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (per));
enf=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (enfant));
cham=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (byout));
sprintf(emty1,"%d",k);
sprintf(emty2,"%d",enf);
sprintf(emty3,"%d",cham);



strcpy(r.ID_client,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(r.ID_res,gtk_entry_get_text(GTK_ENTRY(input20)));
strcpy(r.h.ID,gtk_label_get_text(GTK_LABEL (input30)));
strcpy(r.date_depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboz)));
strcpy(r.date_arrive,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboz2)));
strcpy(r.h.adresse,gtk_label_get_text(GTK_LABEL (input40)));
strcpy(r.h.nom,gtk_label_get_text(GTK_LABEL (input50)));
strcpy(r.personne,emty1);
strcpy(r.enfants,emty2);
strcpy(r.chambres,emty3);
strcpy(r.pension,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboz3)));
strcpy(r.montant,gtk_label_get_text(GTK_LABEL (input60)));
ajouter_hotreservation(r);


gtk_label_set_text(GTK_LABEL(output),"Ajout avec succes ");






}


void
on_button122_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window106;


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

	espace_employee=lookup_widget(objet,"espace_employee");
	confirmation_authentification_employee=lookup_widget(objet,"confirmation_authentification_employee");
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

	//upload khedmet omar 

	GtkWidget *treeview101;
	treeview101=lookup_widget(espace_employee,"treeview101");


	afficher_hotel(treeview101);

	window106=lookup_widget(objet,"window106");

	gtk_widget_destroy(window106);


}


void
on_button124_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window107;

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

	espace_employee=lookup_widget(objet,"espace_employee");
	confirmation_authentification_employee=lookup_widget(objet,"confirmation_authentification_employee");
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

	//upload khedmet omar 

	GtkWidget *treeview101;
	treeview101=lookup_widget(espace_employee,"treeview101");


	afficher_hotel(treeview101);


	window107=lookup_widget(objet,"window107");

	gtk_widget_destroy(window107);

}


void
on_button127_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window108;

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

	espace_employee=lookup_widget(objet,"espace_employee");
	confirmation_authentification_employee=lookup_widget(objet,"confirmation_authentification_employee");
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

	//upload khedmet omar 

	GtkWidget *treeview101;
	treeview101=lookup_widget(espace_employee,"treeview101");


	afficher_hotel(treeview101);


	window108=lookup_widget(objet,"window108");

	gtk_widget_destroy(window108);



}


void
on_button135_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window109;
GtkWidget *window110;
GtkWidget *Combobox15;
hotel tab[50];
int n,i;




window109=lookup_widget(objet,"espace_client");
window110=create_window110();
gtk_widget_destroy(window109);
gtk_widget_show(window110);
Combobox15=lookup_widget(window110, "combobox107");
n=remplir_combo(tab);
occu(tab,n);

for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox15),_(tab[i].adresse));
	}



}


void
on_button136_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window110;
GtkWidget *window111;
GtkWidget *Combobox71;
GtkWidget *Combobox79;
char peris[20];


int n,i;
hotel tab[50];
hotel tab2[50];

window110=lookup_widget(objet,"window110");
Combobox79=lookup_widget(objet,"combobox107");
strcpy(peris,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox79)));
window111=create_window111();
gtk_widget_destroy(window110);
gtk_widget_show(window111);
Combobox71=lookup_widget(window111, "combobox108");
n=remplir_combo2(tab,tab2,peris);

for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox71),_(tab2[i].nom));
	}



}


void
on_button137_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window109;
GtkWidget *window110;



window110=lookup_widget(objet,"window110");
window109=create_espace_client();
gtk_widget_destroy(window110);
gtk_widget_show(window109);


}


void
on_button139_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *window109;
GtkWidget *window111;



window111=lookup_widget(objet,"window111");
window109=create_espace_client();
gtk_widget_destroy(window111);
gtk_widget_show(window109);


}


void
on_button138_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window111;

GtkWidget *window112;
GtkWidget *Combobox69;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output8;
GtkWidget *output9;

char perisa[20];
char testing[20];
char kool[20];
char cv[20];
char ahla2[20];
char id[20];
FILE* f=NULL;




window111=lookup_widget(objet,"window111");
Combobox69=lookup_widget(objet,"combobox108");
strcpy(perisa,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox69)));
window112=create_window112();
gtk_widget_destroy(window111);
gtk_widget_show(window112);
output5=lookup_widget(window112,"label801");
output6=lookup_widget(window112,"label805");
output7=lookup_widget(window112,"label803");
output8=lookup_widget(window112,"label807");
output9=lookup_widget(window112,"label809");
cherID(perisa,testing);
cherPrix(perisa,kool);
cherDesination(perisa,cv);

gtk_label_set_text(GTK_LABEL(output5),testing);
gtk_label_set_text(GTK_LABEL(output6),kool);
gtk_label_set_text(GTK_LABEL(output7),perisa);
gtk_label_set_text(GTK_LABEL(output8),cv);

f=fopen("actual_user.txt","r");
if(f!=NULL)
	while(!feof(f))
		fscanf(f,"%s",id);
fclose(f);

gtk_label_set_text(GTK_LABEL(output9),id);





}


void
on_button140_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *hey;
	char code[20];
	int A;
	
	do
	{
		A=code_hotel();
		sprintf(code,"H%d",A);
	}
	while(verifier_code_hotel(code)==1);
	hey=lookup_widget(objet,"entry106");
	gtk_entry_set_text(GTK_ENTRY(hey),code);
	

}


void
on_button141_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window112;
GtkWidget *yala1;
GtkWidget *Combo1;
GtkWidget *per;
GtkWidget *yala2;
GtkWidget *yala3;
GtkWidget *yala4;
GtkWidget *enfant;
GtkWidget *byout;
int k;
float cofa;
int lll;
char emshi[20];
char emty[20];
int nbk;
int final;
char nombre[20];
int enf;
int cham;

window112=lookup_widget(objet,"window112");
yala1=lookup_widget(objet,"label805");
Combo1=lookup_widget(objet,"combobox111");
per=lookup_widget(objet,"spinbutton102");
yala2=lookup_widget(objet,"entry107");
yala3=lookup_widget(window112,"label820");
yala4=lookup_widget(window112,"label821");
enfant=lookup_widget(objet,"spinbutton104");
byout=lookup_widget(objet,"spinbutton103");

k=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (per));
enf=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (enfant));
cham=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (byout));
strcpy(emshi,gtk_label_get_text(GTK_LABEL (yala1)));

lll=atol(emshi);


if(strcmp("Complete",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combo1)))==0)
		cofa=1;
	else
		cofa=0.7;


strcpy(nombre,gtk_entry_get_text(GTK_ENTRY(yala2)));
nbk=atol(nombre);

final=getmontant(lll,nbk,k,cofa,enf,cham);
sprintf(emty,"%d",final);

gtk_label_set_text(GTK_LABEL(yala3),"Prix total de la reservation est");
gtk_label_set_text(GTK_LABEL(yala4),emty);


}


void
on_button142_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
reshotel r;
GtkWidget *input10,*input20,*input30,*input40,*input50,*enfant,*byout,*per,*Comboz,*Comboz2,*Comboz3,*input60;
GtkWidget *window177,*output;
GtkWidget *kkk;
hotel tab[50];
int k,enf,cham;
char emty1[20];
char emty2[20];
char emty3[20];

window177=lookup_widget(objet,"window112");

input10=lookup_widget(objet,"label809");
input20=lookup_widget(objet,"entry106");
input30=lookup_widget(objet,"label801");
Comboz=lookup_widget(objet,"combobox109");
Comboz2=lookup_widget(objet,"combobox110");
input40=lookup_widget(objet,"label807");
input50=lookup_widget(objet,"label803");
enfant=lookup_widget(objet,"spinbutton104");
byout=lookup_widget(objet,"spinbutton103");
per=lookup_widget(objet,"spinbutton102");
Comboz3=lookup_widget(objet,"combobox111");
input60=lookup_widget(objet,"label821");
output=lookup_widget(objet,"label824");



k=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (per));
enf=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (enfant));
cham=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (byout));
sprintf(emty1,"%d",k);
sprintf(emty2,"%d",enf);
sprintf(emty3,"%d",cham);



strcpy(r.ID_client,gtk_label_get_text(GTK_LABEL (input10)));
strcpy(r.ID_res,gtk_entry_get_text(GTK_ENTRY(input20)));
strcpy(r.h.ID,gtk_label_get_text(GTK_LABEL (input30)));
strcpy(r.date_depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboz)));
strcpy(r.date_arrive,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboz2)));
strcpy(r.h.adresse,gtk_label_get_text(GTK_LABEL (input40)));
strcpy(r.h.nom,gtk_label_get_text(GTK_LABEL (input50)));
strcpy(r.personne,emty1);
strcpy(r.enfants,emty2);
strcpy(r.chambres,emty3);
strcpy(r.pension,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboz3)));
strcpy(r.montant,gtk_label_get_text(GTK_LABEL (input60)));
ajouter_hotreservation(r);


gtk_label_set_text(GTK_LABEL(output),"Ajout avec succes ");


}


void
on_button143_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window109;
GtkWidget *window112;



window112=lookup_widget(objet,"window112");
window109=create_espace_client();
gtk_widget_destroy(window112);
gtk_widget_show(window109);

}


void
on_button145_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window101;
GtkWidget *window104;
GtkWidget *Combobox100;
int n,i;
hotel  tab[50];

window101=lookup_widget(objet,"espace_employee");
window104=create_window104();
gtk_widget_destroy(window101);
gtk_widget_show(window104);



Combobox100=lookup_widget(window104, "combobox100");

n=remplir_combo(tab);

	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox100),_(tab[i].ID));
	}

}


void
on_button146_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
hotel tab[50];

GtkWidget *window101;
GtkWidget *window105;
GtkWidget *Combobox10;
int n,i;


window101=lookup_widget(objet,"espace_employee");
window105=create_window105();
gtk_widget_destroy(window101);
gtk_widget_show(window105);
Combobox10=lookup_widget(window105, "combobox101");

n=remplir_combo(tab);

	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox10),_(tab[i].ID));
	}



}


void
on_button147_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window101;
GtkWidget *window106;
GtkWidget *Combobox15;
hotel tab[50];
int n,i;




window101=lookup_widget(objet,"espace_employee");
window106=create_window106();
gtk_widget_destroy(window101);
gtk_widget_show(window106);
Combobox15=lookup_widget(window106, "combobox102");
n=remplir_combo(tab);
occu(tab,n);

for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox15),_(tab[i].adresse));
	}




}


void
on_button144_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window101;
GtkWidget *window103;



window101=lookup_widget(objet,"espace_employee");
window103=create_window103();
gtk_widget_destroy(window101);
gtk_widget_show(window103);


}
/*
void
on_button_confirmation_authentification_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{

}
*/

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
                                        (GtkWidget       *objet,
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
	espace_admin=lookup_widget(objet,"espace_admin");
	confirmation_authentification_admin=lookup_widget(objet,"confirmation_authentification_admin");
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
                                        (GtkWidget       *object,
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
	char identifiant[50][20];

	espace_admin=lookup_widget(object,"espace_admin");
	supprimer_employee=lookup_widget(object,"supprimer_employee");

	supprimer_employee = create_supprimer_employee ();
  	gtk_widget_show (supprimer_employee);
	gtk_widget_destroy(espace_admin);

	combobox_supprimer_employer=lookup_widget(supprimer_employee,"combobox_supprimer_employer");
	n=remplir_combobox_numero(identifiant);
	for(i=0;i<n;i++)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combobox_supprimer_employer),identifiant[i]);
	
}

void
on_button_modifier_employee_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	int n,i;
	char identifiant[50][20];
	
	GtkWidget *choisir_identifiant_modifier_employee;
	GtkWidget *espace_admin;
	GtkWidget *combobox_modifier_employee;

	espace_admin=lookup_widget(object,"espace_admin");
	gtk_widget_destroy(espace_admin);

	choisir_identifiant_modifier_employee=lookup_widget(object,"choisir_identifiant_modifier_employee");
	choisir_identifiant_modifier_employee = create_choisir_identifiant_modifier_employee ();
  	gtk_widget_show (choisir_identifiant_modifier_employee);

	combobox_modifier_employee=lookup_widget(choisir_identifiant_modifier_employee,"combobox_modifier_employee");
	n=remplir_combobox_numero(identifiant);
	for(i=0;i<n;i++)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combobox_modifier_employee),identifiant[i]);

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
	GtkWidget *combobox_supprimer_client_admin;

	int n,i;
	char identifiant[50][20];

	espace_admin=lookup_widget(object,"espace_admin");
	supprimer_client_admin=lookup_widget(object,"supprimer_client_admin");

	supprimer_client_admin = create_supprimer_client_admin ();
  	gtk_widget_show (supprimer_client_admin);
	gtk_widget_destroy(espace_admin);


	combobox_supprimer_client_admin=lookup_widget(supprimer_client_admin,"combobox_supprimer_client_admin");
	n=remplir_combobox_numero_1(identifiant);
	for(i=0;i<n;i++)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combobox_supprimer_client_admin),identifiant[i]);
}


void
on_button_modifier_client_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{

	int n,i;
	char identifiant[50][20];

	GtkWidget *choisir_identifiant_modifier_client_admin;
	GtkWidget *espace_admin;
	GtkWidget *combobox_modifier_client_admin;

	espace_admin=lookup_widget(object,"espace_admin");
	gtk_widget_destroy(espace_admin);

	choisir_identifiant_modifier_client_admin=lookup_widget(object,"choisir_identifiant_modifier_client_admin");
	choisir_identifiant_modifier_client_admin = create_choisir_identifiant_modifier_client_admin();
  	gtk_widget_show (choisir_identifiant_modifier_client_admin);


	combobox_modifier_client_admin=lookup_widget(choisir_identifiant_modifier_client_admin,"combobox_modifier_client_admin");
	n=remplir_combobox_numero_1(identifiant);
	for(i=0;i<n;i++)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combobox_modifier_client_admin),identifiant[i]);

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

	GtkWidget *supprimer_client_employee;
	GtkWidget *espace_employee;
	GtkWidget *combobox_supprimer_client_employee;

	int n,i;
	char identifiant[50][20];

	espace_employee=lookup_widget(object,"espace_employee");
	supprimer_client_employee=lookup_widget(object,"supprimer_client_employee");

	supprimer_client_employee = create_supprimer_client_employee();
  	gtk_widget_show (supprimer_client_employee);
	gtk_widget_destroy(espace_employee);


	combobox_supprimer_client_employee=lookup_widget(supprimer_client_employee,"combobox_supprimer_client_employee");
	n=remplir_combobox_numero_1(identifiant);
	for(i=0;i<n;i++)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combobox_supprimer_client_employee),identifiant[i]);
}


void
on_button_modifier_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{

	int n,i;
	char identifiant[50][20];

	GtkWidget *choisir_identifiant_modifier_client_employee;
	GtkWidget *espace_employee;
	GtkWidget *combobox_modifier_client_employee;

	espace_employee=lookup_widget(object,"espace_employee");
	gtk_widget_destroy(espace_employee);

	choisir_identifiant_modifier_client_employee=lookup_widget(object,"choisir_identifiant_modifier_client_employee");
	choisir_identifiant_modifier_client_employee = create_choisir_identifiant_modifier_client_employee();
  	gtk_widget_show (choisir_identifiant_modifier_client_employee);


	combobox_modifier_client_employee=lookup_widget(choisir_identifiant_modifier_client_employee,"combobox_modifier_client_employee");
	n=remplir_combobox_numero_1(identifiant);
	for(i=0;i<n;i++)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combobox_modifier_client_employee),identifiant[i]);
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
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *supprimer_employee;
	GtkWidget *confirmation_supprimer_employee;

	GtkWidget *combobox_supprimer_employer;

	char identifiant[20];

	combobox_supprimer_employer=lookup_widget(object,"combobox_supprimer_employer");
	
	strcpy(identifiant,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_supprimer_employer)));
	supprimer_utilisateur(identifiant);


	supprimer_employee=lookup_widget(object,"supprimer_employee");
	gtk_widget_destroy(supprimer_employee);
	confirmation_supprimer_employee=lookup_widget(object,"confirmation_supprimer_employee");
	confirmation_supprimer_employee=create_confirmation_supprimer_employee();
	gtk_widget_show(confirmation_supprimer_employee);
	
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
                                        (GtkWidget       *objet,
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

	espace_employee=lookup_widget(objet,"espace_employee");
	confirmation_authentification_employee=lookup_widget(objet,"confirmation_authentification_employee");
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

	//upload khedmet omar 

	GtkWidget *treeview101;
	treeview101=lookup_widget(espace_employee,"treeview101");


	afficher_hotel(treeview101);

}


void
on_button_confirmation_authentification_client_clicked
                                        (GtkWidget      *objet,
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

	espace_client=lookup_widget(objet,"espace_client");
	confirmation_authentification_client=lookup_widget(objet,"confirmation_authentification_client");
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


void
on_button_confirmation_supprimer_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *confirmation_supprimer_employee;
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

	//destroy and show windows
	espace_admin=lookup_widget(object,"espace_admin");
	confirmation_supprimer_employee=lookup_widget(object,"confirmation_supprimer_employee");
	gtk_widget_destroy(confirmation_supprimer_employee);
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
on_button_valider_modifier_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	char id[20];
	char role[20];
	char naissance[100];
	FILE *f=NULL;
	utilisateur u;
	utilisateur user;

	GtkWidget *modifier_employee;
	GtkWidget *confirmation_modifier_employee;

	GtkWidget *entry_identifiant_modifier_employee;
	GtkWidget *entry_nom_modifier_employee;
	GtkWidget *entry_prenom_modifier_employee;
  	GtkWidget *entry_cin_modifier_employee;
	GtkWidget *combobox_role_modifier_employee;
	GtkWidget *label_naissance_modifier_employee;
	GtkWidget *combobox_modifier_employee;


	modifier_employee=lookup_widget(object,"modifier_employee");
	combobox_role_modifier_employee=lookup_widget(modifier_employee,"combobox_role_modifier_employee");
	entry_identifiant_modifier_employee=lookup_widget(object,"entry_identifiant_modifier_employee");
	entry_nom_modifier_employee=lookup_widget(object,"entry_nom_modifier_employee");
	entry_prenom_modifier_employee=lookup_widget(object,"entry_prenom_modifier_employee");
	entry_cin_modifier_employee=lookup_widget(object,"entry_cin_modifier_employee");
	combobox_role_modifier_employee=lookup_widget(object,"combobox_role_modifier_employee");
	label_naissance_modifier_employee=lookup_widget(object,"label_naissance_modifier_employee");

	strcpy(u.identifiant,gtk_entry_get_text(GTK_ENTRY(entry_identifiant_modifier_employee)));
	f=fopen("utilisateurs.txt","r");

	if(f!=NULL)
		while(fscanf(f,"%s %s %s %s %d %d %d %s %s \n",user.identifiant,user.mot_de_passe,user.nom,user.prenom,&user.naissance.jour,&user.naissance.mois,&user.naissance.annee,user.cin,user.role)!=EOF)
		{
			if(strcmp(user.identifiant,u.identifiant)==0)
				strcpy(u.mot_de_passe,user.mot_de_passe);
		}
	fclose(f);

	sscanf(gtk_label_get_text(GTK_LABEL(label_naissance_modifier_employee)),"%d/%d/%d",&u.naissance.jour,&u.naissance.mois,&u.naissance.annee);
	strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom_modifier_employee)));
	strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(entry_prenom_modifier_employee)));
	strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(entry_cin_modifier_employee)));
	strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_role_modifier_employee)));
	if(strcmp(role,"Employee")==0)
		strcpy(u.role,"employee");
	if(strcmp(role,"Administrateur")==0)
		strcpy(u.role,"admin");
	supprimer_utilisateur(u.identifiant);
	ajouter_utilisateur(u);

	confirmation_modifier_employee=lookup_widget(object,"confirmation_modifier_employee");

	gtk_widget_destroy(modifier_employee);
	confirmation_modifier_employee = create_confirmation_modifier_employee ();
  	gtk_widget_show (confirmation_modifier_employee);


	

	
}


void
on_button_annuler_modifier_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	int n,i;
	char identifiant[50][20];
	
	GtkWidget *choisir_identifiant_modifier_employee;
	GtkWidget *modifier_employee;
	GtkWidget *combobox_modifier_employee;

	modifier_employee=lookup_widget(object,"modifier_employee");
	gtk_widget_destroy(modifier_employee);

	choisir_identifiant_modifier_employee=lookup_widget(object,"choisir_identifiant_modifier_employee");
	choisir_identifiant_modifier_employee = create_choisir_identifiant_modifier_employee ();
  	gtk_widget_show (choisir_identifiant_modifier_employee);

	combobox_modifier_employee=lookup_widget(choisir_identifiant_modifier_employee,"combobox_modifier_employee");
	n=remplir_combobox_numero(identifiant);
	for(i=0;i<n;i++)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combobox_modifier_employee),identifiant[i]);
}

void
on_button_confirmation_modifier_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	char id[20];
	char role[20];
	char naissance[100];
	FILE *f=NULL;
	utilisateur u;
	utilisateur user;

	GtkWidget *confirmation_modifier_employee;
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



	espace_admin=lookup_widget(object,"espace_admin");
	confirmation_modifier_employee=lookup_widget(object,"confirmation_modifier_employee");
	gtk_widget_destroy(confirmation_modifier_employee);
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
on_button_confirmation_ajouter_client_admin_clicked
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


void
on_button_valider_supprimer_client_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *supprimer_client_admin;;
	GtkWidget *confirmation_supprimer_client_admin;

	GtkWidget *combobox_supprimer_client_admin;

	char identifiant[20];

	combobox_supprimer_client_admin=lookup_widget(object,"combobox_supprimer_client_admin");
	
	strcpy(identifiant,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_supprimer_client_admin)));
	supprimer_utilisateur(identifiant);

	confirmation_supprimer_client_admin=lookup_widget(object,"confirmation_supprimer_client_admin");
	supprimer_client_admin=lookup_widget(object,"supprimer_client_admin");
	gtk_widget_destroy(supprimer_client_admin);
	confirmation_supprimer_client_admin = create_confirmation_supprimer_client_admin();
  	gtk_widget_show (confirmation_supprimer_client_admin);

	
}


void
on_button_confirmation_supprimer_client_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *espace_admin;
	GtkWidget *confirmation_supprimer_client_admin;

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
	confirmation_supprimer_client_admin=lookup_widget(object,"confirmation_supprimer_client_admin");
	gtk_widget_destroy(confirmation_supprimer_client_admin);
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
on_button_annuler_modifier_client_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	int n,i;
	char identifiant[50][20];
	
	GtkWidget *choisir_identifiant_modifier_client_admin;
	GtkWidget *modifier_client_admin;
	GtkWidget *combobox_modifier_client_admin;

	modifier_client_admin=lookup_widget(object,"modifier_client_admin");
	gtk_widget_destroy(modifier_client_admin);

	choisir_identifiant_modifier_client_admin=lookup_widget(object,"choisir_identifiant_modifier_client_admin");
	choisir_identifiant_modifier_client_admin = create_choisir_identifiant_modifier_client_admin ();
  	gtk_widget_show (choisir_identifiant_modifier_client_admin);

	combobox_modifier_client_admin=lookup_widget(choisir_identifiant_modifier_client_admin,"combobox_modifier_client_admin");
	n=remplir_combobox_numero_1(identifiant);
	for(i=0;i<n;i++)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combobox_modifier_client_admin),identifiant[i]);
}


void
on_button_valider_modifier_client_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	char id[20];
	char pass[20];
	char password[20];
	char role[20];
	char naissance[100];
	FILE *f=NULL;
	utilisateur u;
	char a[20];
	char b[20];
	char c[20];
	char d[20];
	char e[20];
	char h[20];
	char g[20];

	GtkWidget *modifier_client_admin;
	GtkWidget *confirmation_modifier_client_admin;

	GtkWidget *entry_identifiant_modifier_client_admin;
	GtkWidget *entry_nom_modifier_client_admin;
	GtkWidget *entry_prenom_modifier_client_admin;
  	GtkWidget *entry_cin_modifier_client_admin;
	GtkWidget *label_naissance_modifier_client_admin;

	modifier_client_admin=lookup_widget(object,"modifier_client_admin");
	entry_identifiant_modifier_client_admin=lookup_widget(object,"entry_identifiant_modifier_client_admin");
	entry_nom_modifier_client_admin=lookup_widget(object,"entry_nom_modifier_client_admin");
	entry_prenom_modifier_client_admin=lookup_widget(object,"entry_prenom_modifier_client_admin");
	entry_cin_modifier_client_admin=lookup_widget(object,"entry_cin_modifier_client_admin");
	label_naissance_modifier_client_admin=lookup_widget(object,"label_naissance_modifier_client_admin");

	strcpy(u.identifiant,gtk_entry_get_text(GTK_ENTRY(entry_identifiant_modifier_client_admin)));
	f=fopen("utilisateurs.txt","r");
	if(f!=NULL)
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %s %s %s %s %s \n",id,pass,a,b,c,d,e,h,g);
			if(strcmp(id,u.identifiant)==0)
				strcpy(u.mot_de_passe,pass);
		}
	fclose(f);

	sscanf(gtk_label_get_text(GTK_LABEL(label_naissance_modifier_client_admin)),"%d/%d/%d",&u.naissance.jour,&u.naissance.mois,&u.naissance.annee);
	strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(entry_cin_modifier_client_admin)));
	strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom_modifier_client_admin)));
	strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(entry_prenom_modifier_client_admin)));
	strcpy(u.role,"client");

	supprimer_utilisateur(u.identifiant);
	ajouter_utilisateur(u);

	gtk_widget_destroy(modifier_client_admin);

	confirmation_modifier_client_admin=lookup_widget(object,"confirmation_modifier_client_admin");
	confirmation_modifier_client_admin=create_confirmation_modifier_client_admin();
	gtk_widget_show(confirmation_modifier_client_admin);

}


void
on_button_confirmation_modifier_client_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{

	char id[20];
	char pass[20];
	char password[20];
	char role[20];
	char naissance[100];
	FILE *f=NULL;
	utilisateur u;

	GtkWidget *confirmation_modifier_client_admin;
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

	confirmation_modifier_client_admin=lookup_widget(object,"confirmation_modifier_client_admin");
	espace_admin=lookup_widget(object,"espace_admin");

	gtk_widget_destroy(confirmation_modifier_client_admin);
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


void
on_button_annuler_modifier_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	int n,i;
	char identifiant[50][20];
	
	GtkWidget *choisir_identifiant_modifier_client_employee;
	GtkWidget *modifier_client_employee;
	GtkWidget *combobox_modifier_client_employee;

	modifier_client_employee=lookup_widget(object,"modifier_client_employee");
	gtk_widget_destroy(modifier_client_employee);

	choisir_identifiant_modifier_client_employee=lookup_widget(object,"choisir_identifiant_modifier_client_employee");
	choisir_identifiant_modifier_client_employee = create_choisir_identifiant_modifier_client_employee ();
  	gtk_widget_show (choisir_identifiant_modifier_client_employee);

	combobox_modifier_client_employee=lookup_widget(choisir_identifiant_modifier_client_employee,"combobox_modifier_client_employee");
	n=remplir_combobox_numero_1(identifiant);
	for(i=0;i<n;i++)
		gtk_combo_box_append_text (GTK_COMBO_BOX(combobox_modifier_client_employee),identifiant[i]);

}


void
on_button_valider_modifier_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	char a[20];
	char b[20];
	char c[20];
	char d[20];
	char e[20];
	char h[20];
	char g[20];
	char id[20];
	char pass[20];
	char password[20];
	char role[20];
	char naissance[100];
	FILE *f=NULL;
	utilisateur u;

	GtkWidget *confirmation_modifier_client_employee;
	GtkWidget *modifier_client_employee;
	GtkWidget *espace_employee;

	GtkWidget *entry_identifiant_modifier_client_employee;
	GtkWidget *entry_nom_modifier_client_employee;
	GtkWidget *entry_prenom_modifier_client_employee;
  	GtkWidget *entry_cin_modifier_client_employee;
	GtkWidget *label_naissance_modifier_client_employee;


	modifier_client_employee=lookup_widget(object,"modifier_client_employee");
	entry_identifiant_modifier_client_employee=lookup_widget(object,"entry_identifiant_modifier_client_employee");
	entry_nom_modifier_client_employee=lookup_widget(object,"entry_nom_modifier_client_employee");
	entry_prenom_modifier_client_employee=lookup_widget(object,"entry_prenom_modifier_client_employee");
	entry_cin_modifier_client_employee=lookup_widget(object,"entry_cin_modifier_client_employee");
	label_naissance_modifier_client_employee=lookup_widget(object,"label_naissance_modifier_client_employee");

	strcpy(u.identifiant,gtk_entry_get_text(GTK_ENTRY(entry_identifiant_modifier_client_employee)));
	f=fopen("utilisateurs.txt","r");
	if(f!=NULL)
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %s %s %s %s %s \n",id,pass,a,b,c,d,e,h,g);
			if(strcmp(id,u.identifiant)==0)
				strcpy(u.mot_de_passe,pass);
		}
	fclose(f);

	sscanf(gtk_label_get_text(GTK_LABEL(label_naissance_modifier_client_employee)),"%d/%d/%d",&u.naissance.jour,&u.naissance.mois,&u.naissance.annee);
	strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(entry_cin_modifier_client_employee)));
	strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom_modifier_client_employee)));
	strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(entry_prenom_modifier_client_employee)));
	strcpy(u.role,"client");

	supprimer_utilisateur(u.identifiant);
	ajouter_utilisateur(u);

	confirmation_modifier_client_employee=lookup_widget(object,"confirmation_modifier_client_employee");
	gtk_widget_destroy(modifier_client_employee);

	confirmation_modifier_client_employee=create_confirmation_modifier_client_employee();
	gtk_widget_show(confirmation_modifier_client_employee);
}

void
on_button_confirmation_modifier_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *confirmation_modifier_client_employee;
	GtkWidget *espace_employee;
	confirmation_modifier_client_employee=lookup_widget(object,"confirmation_modifier_client_employee");
	gtk_widget_destroy(confirmation_modifier_client_employee);

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


void
on_button_valider_supprimer_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *supprimer_client_employee;
	GtkWidget *confirmation_supprimer_client_employee;

	GtkWidget *combobox_supprimer_client_employee;

	char identifiant[20];

	combobox_supprimer_client_employee=lookup_widget(object,"combobox_supprimer_client_employee");
	
	strcpy(identifiant,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_supprimer_client_employee)));
	supprimer_utilisateur(identifiant);

	confirmation_supprimer_client_employee=lookup_widget(object,"confirmation_supprimer_client_employee");
	supprimer_client_employee=lookup_widget(object,"supprimer_client_employee");
	gtk_widget_destroy(supprimer_client_employee);
	confirmation_supprimer_client_employee = create_confirmation_supprimer_client_employee ();
  	gtk_widget_show (confirmation_supprimer_client_employee);

	
}

//mizel
void
on_button_confirmation_supprimer_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{	
	GtkWidget *espace_employee;
	GtkWidget *confirmation_supprimer_client_employee;

	confirmation_supprimer_client_employee=lookup_widget(object,"confirmation_supprimer_client_employee");
	gtk_widget_destroy(confirmation_supprimer_client_employee);
	
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


void
on_button_valider_identifiant_modifier_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	char idchoisie[20];
	char date[20];
	utilisateur u;
	FILE *f=NULL;

	GtkWidget *modifier_employee;
	GtkWidget *choisir_identifiant_modifier_employee;

	GtkWidget *entry_identifiant_modifier_employee;
	GtkWidget *entry_nom_modifier_employee;
	GtkWidget *entry_prenom_modifier_employee;
  	GtkWidget *entry_cin_modifier_employee;
	GtkWidget *combobox_role_modifier_employee;
	GtkWidget *label_naissance_modifier_employee;
	GtkWidget *combobox_modifier_employee;

	combobox_modifier_employee=lookup_widget(object,"combobox_modifier_employee");
	strcpy(idchoisie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifier_employee)));

	modifier_employee=lookup_widget(object,"modifier_employee");
	modifier_employee= create_modifier_employee ();
	gtk_widget_show (modifier_employee);
	choisir_identifiant_modifier_employee=lookup_widget(object,"choisir_identifiant_modifier_employee");
	gtk_widget_destroy(choisir_identifiant_modifier_employee);

	combobox_role_modifier_employee=lookup_widget(object,"combobox_role_modifier_employee");
	entry_identifiant_modifier_employee=lookup_widget(modifier_employee,"entry_identifiant_modifier_employee");
	entry_nom_modifier_employee=lookup_widget(modifier_employee,"entry_nom_modifier_employee");
	entry_prenom_modifier_employee=lookup_widget(modifier_employee,"entry_prenom_modifier_employee");
	entry_cin_modifier_employee=lookup_widget(modifier_employee,"entry_cin_modifier_employee");
	combobox_role_modifier_employee=lookup_widget(modifier_employee,"combobox_role_modifier_employee");
	label_naissance_modifier_employee=lookup_widget(modifier_employee,"label_naissance_modifier_employee");

	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_modifier_employee),idchoisie);

	f=fopen("utilisateurs.txt","r");
		if(f!=NULL)
			while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if(strcmp(idchoisie,u.identifiant)==0)
			{
				gtk_entry_set_text(GTK_ENTRY(entry_nom_modifier_employee),u.nom);
				gtk_entry_set_text(GTK_ENTRY(entry_prenom_modifier_employee),u.prenom);
				gtk_entry_set_text(GTK_ENTRY(entry_cin_modifier_employee),u.cin);
				sprintf(date,"%d/%d/%d",u.naissance.jour,u.naissance.mois,u.naissance.annee);
				gtk_label_set_text(GTK_LABEL(label_naissance_modifier_employee),date);
				if(strcmp(u.role,"admin")==0)
					gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_role_modifier_employee),0);
				if(strcmp(u.role,"employee")==0)
					gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_role_modifier_employee),1);
			}
		}
		fclose(f);
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


void
on_button_valider_identifiant_modifier_client_employee_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	char idchoisie[20];
	char date[20];
	utilisateur u;
	FILE *f=NULL;

	GtkWidget *modifier_client_employee;
	GtkWidget *choisir_identifiant_modifier_client_employee;

	GtkWidget *entry_identifiant_modifier_client_employee;
	GtkWidget *entry_nom_modifier_client_employee;
	GtkWidget *entry_prenom_modifier_client_employee;
  	GtkWidget *entry_cin_modifier_client_employee;
	GtkWidget *combobox_role_modifier_client_employee;
	GtkWidget *label_naissance_modifier_client_employee;
	GtkWidget *combobox_modifier_client_employee;

	combobox_modifier_client_employee=lookup_widget(object,"combobox_modifier_client_employee");
	strcpy(idchoisie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifier_client_employee)));

	modifier_client_employee=lookup_widget(object,"modifier_client_employee");
	modifier_client_employee= create_modifier_client_employee ();
	gtk_widget_show (modifier_client_employee);
	choisir_identifiant_modifier_client_employee=lookup_widget(object,"choisir_identifiant_modifier_client_employee");
	gtk_widget_destroy(choisir_identifiant_modifier_client_employee);

	entry_identifiant_modifier_client_employee=lookup_widget(modifier_client_employee,"entry_identifiant_modifier_client_employee");
	entry_nom_modifier_client_employee=lookup_widget(modifier_client_employee,"entry_nom_modifier_client_employee");
	entry_prenom_modifier_client_employee=lookup_widget(modifier_client_employee,"entry_prenom_modifier_client_employee");
	entry_cin_modifier_client_employee=lookup_widget(modifier_client_employee,"entry_cin_modifier_client_employee");
	combobox_role_modifier_client_employee=lookup_widget(modifier_client_employee,"combobox_role_modifier_client_employee");
	label_naissance_modifier_client_employee=lookup_widget(modifier_client_employee,"label_naissance_modifier_client_employee");

	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_modifier_client_employee),idchoisie);

	f=fopen("utilisateurs.txt","r");
		if(f!=NULL)
			while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if(strcmp(idchoisie,u.identifiant)==0)
			{
				gtk_entry_set_text(GTK_ENTRY(entry_nom_modifier_client_employee),u.nom);
				gtk_entry_set_text(GTK_ENTRY(entry_prenom_modifier_client_employee),u.prenom);
				gtk_entry_set_text(GTK_ENTRY(entry_cin_modifier_client_employee),u.cin);
				sprintf(date,"%d/%d/%d",u.naissance.jour,u.naissance.mois,u.naissance.annee);
				gtk_label_set_text(GTK_LABEL(label_naissance_modifier_client_employee),date);
			}
		}
		fclose(f);
}


void
on_button_valider_identifiant_modifier_client_admin_clicked
                                        (GtkWidget       *object,
                                        gpointer         user_data)
{
	char idchoisie[20];
	char date[20];
	utilisateur u;
	FILE *f=NULL;

	GtkWidget *modifier_client_admin;
	GtkWidget *choisir_identifiant_modifier_client_admin;

	GtkWidget *entry_identifiant_modifier_client_admin;
	GtkWidget *entry_nom_modifier_client_admin;
	GtkWidget *entry_prenom_modifier_client_admin;
  	GtkWidget *entry_cin_modifier_client_admin;
	GtkWidget *combobox_role_modifier_client_admin;
	GtkWidget *label_naissance_modifier_client_admin;
	GtkWidget *combobox_modifier_client_admin;

	combobox_modifier_client_admin=lookup_widget(object,"combobox_modifier_client_admin");
	strcpy(idchoisie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifier_client_admin)));

	modifier_client_admin=lookup_widget(object,"modifier_client_admin");
	modifier_client_admin= create_modifier_client_admin ();
	gtk_widget_show (modifier_client_admin);
	choisir_identifiant_modifier_client_admin=lookup_widget(object,"choisir_identifiant_modifier_client_admin");
	gtk_widget_destroy(choisir_identifiant_modifier_client_admin);

	entry_identifiant_modifier_client_admin=lookup_widget(modifier_client_admin,"entry_identifiant_modifier_client_admin");
	entry_nom_modifier_client_admin=lookup_widget(modifier_client_admin,"entry_nom_modifier_client_admin");
	entry_prenom_modifier_client_admin=lookup_widget(modifier_client_admin,"entry_prenom_modifier_client_admin");
	entry_cin_modifier_client_admin=lookup_widget(modifier_client_admin,"entry_cin_modifier_client_admin");
	combobox_role_modifier_client_admin=lookup_widget(modifier_client_admin,"combobox_role_modifier_client_admin");
	label_naissance_modifier_client_admin=lookup_widget(modifier_client_admin,"label_naissance_modifier_client_admin");

	gtk_entry_set_text(GTK_ENTRY(entry_identifiant_modifier_client_admin),idchoisie);

	f=fopen("utilisateurs.txt","r");
		if(f!=NULL)
			while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if(strcmp(idchoisie,u.identifiant)==0)
			{
				gtk_entry_set_text(GTK_ENTRY(entry_nom_modifier_client_admin),u.nom);
				gtk_entry_set_text(GTK_ENTRY(entry_prenom_modifier_client_admin),u.prenom);
				gtk_entry_set_text(GTK_ENTRY(entry_cin_modifier_client_admin),u.cin);
				sprintf(date,"%d/%d/%d",u.naissance.jour,u.naissance.mois,u.naissance.annee);
				gtk_label_set_text(GTK_LABEL(label_naissance_modifier_client_admin),date);
			}
		}
		fclose(f);

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

