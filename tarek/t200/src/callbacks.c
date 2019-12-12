#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"


void
on_retourrecclient_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewrecclient;
	GtkWidget *reclamationclient,*tabrecclient;
	reclamationclient=lookup_widget(objet,"reclamationclient");
	gtk_widget_destroy(reclamationclient);
	tabrecclient=create_tabrecclient();
	gtk_widget_show(tabrecclient);
	treeviewrecclient=lookup_widget(tabrecclient,"treeviewrecclient");
  	afficher_reclamation_client(treeviewrecclient);
}


void
on_sauvegarderrecclient_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *msgconfimationrec;
	GtkWidget *reclamationclient;
	GtkWidget *rechtypederecclient;
	GtkWidget *saisierecclient;

	reclamation r;
	char a[20];
	FILE* f=NULL;

	r.id_rec=calculer_reclamation();
	f=fopen("actual_user.txt","a+");
	if(f!=NULL)
	{	
		while(!feof(f))
		{
			fscanf(f,"%s \n",a);
		}
	}
	fclose(f);
	strcpy(r.id_client,a);
	rechtypederecclient=lookup_widget(objet,"rechtypederecclient");
	strcpy(r.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(rechtypederecclient)));
	r.date.jour=12;
	r.date.mois=12;
	r.date.annee=2019;
	strcpy(r.etat,"non_lu");
	sprintf(r.text,"t%d.txt",r.id_rec);
	sprintf(r.reponse,"r%d.txt",r.id_rec);

	saisierecclient=lookup_widget(objet,"saisierecclient");
	set_text_file(r.text,gtk_entry_get_text(GTK_ENTRY(saisierecclient)));

	ajouter_reclamation(r);

	reclamationclient=lookup_widget(objet,"reclamationclient");
	msgconfimationrec=lookup_widget(objet,"msgconfimationrec");

	msgconfimationrec=create_msgconfimationrec();
	gtk_widget_show(msgconfimationrec);
	gtk_widget_destroy(reclamationclient);
}


void
on_archiverrecclient_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_okmsgrec_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeviewrecclient;
	GtkWidget *msgconfimationrec,*tabrecclient;
	msgconfimationrec=lookup_widget(objet,"msgconfimationrec");
	gtk_widget_destroy(msgconfimationrec);
	tabrecclient=create_tabrecclient();
	gtk_widget_show(tabrecclient);
	
	treeviewrecclient=lookup_widget(tabrecclient,"treeviewrecclient");
  	afficher_reclamation_client(treeviewrecclient);


}


void
on_repondreadmin_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *numrec;
	GtkWidget *saisiereponsereclamation;

	char text[1000];
	char a[20];
	char b[20];

	numrec=lookup_widget(objet,"numrec");
	saisiereponsereclamation=lookup_widget(objet,"saisiereponsereclamation");

	strcpy(a,"r");
	strcat(a,gtk_label_get_text(GTK_LABEL(numrec)));
	strcat(a,".txt");

	set_text_file(a,gtk_entry_get_text(GTK_ENTRY(saisiereponsereclamation)));
	

	GtkWidget *reponsereclamation,*msgreponserec;
	reponsereclamation=lookup_widget(objet,"reponsereclamation");
	gtk_widget_destroy(reponsereclamation);
	msgreponserec=create_msgreponserec();
	gtk_widget_show(msgreponserec);
}


void
on_retouradmin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview2recadmin;
	GtkWidget *reponsereclamation,*tabrecadmin;
	reponsereclamation=lookup_widget(objet,"reponsereclamation");
	gtk_widget_destroy(reponsereclamation);
	tabrecadmin=create_tabrecadmin();
	gtk_widget_show(tabrecadmin);
	
	treeview2recadmin=lookup_widget(tabrecadmin,"treeview2recadmin");
  	afficher_reclamation_admin(treeview2recadmin);
}


void
on_ajouterrecclient_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{	int n,i;
	GtkWidget *tabrecclient,*reclamationclient;
	tabrecclient=lookup_widget(objet,"tabrecclient");
	gtk_widget_destroy(tabrecclient);
	reclamationclient=create_reclamationclient();
	gtk_widget_show(reclamationclient);

	GtkWidget *rechtypederecclient;
	
	//char tab[50][50];


	//rechtypederecclient=lookup_widget(reclamationclient,"rechtypederecclient");
	//n=remplir_combo_type_reclamation(tab);
	//for(i=0;i<n;i++)
	//{
		//gtk_combo_box_append_text (GTK_COMBO_BOX (rechtypederecclient),tab[i]);
	//}


}


void
on_supprimerrecclient_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{	int n,i;
	GtkWidget *tabrecclient,*suppressionderecclient;
	tabrecclient=lookup_widget(objet,"tabrecclient");
	gtk_widget_destroy(tabrecclient);
	suppressionderecclient=create_suppressionderecclient();
	gtk_widget_show(suppressionderecclient);

GtkWidget *idsupprecclient;
	
	char tab[50][50];


	idsupprecclient=lookup_widget(suppressionderecclient,"idsupprecclient");
	n=remplir_combo_reclamation(tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (idsupprecclient),_(tab[i]));
	}

}


void
on_retourtabrecclient_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *tabrecclient,*test_rec;
	tabrecclient=lookup_widget(objet,"tabrecclient");
	gtk_widget_destroy(tabrecclient);
	test_rec=create_test_rec();
	gtk_widget_show(test_rec);
}


void
on_modiferrecclient_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{	int n,i;
	GtkWidget *tabrecclient,*selectmodfierreclamation;
	tabrecclient=lookup_widget(objet,"tabrecclient");
	gtk_widget_destroy(tabrecclient);
	selectmodfierreclamation=create_selectmodfierreclamation();
	gtk_widget_show(selectmodfierreclamation);

	GtkWidget *modifiercomborec;
	
	char tab[50][50];


	modifiercomborec=lookup_widget(selectmodfierreclamation,"modifiercomborec");
	n=remplir_combo_reclamation(tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (modifiercomborec),_(tab[i]));
	}


}


void
on_afficherrecadmin_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{	int n,i;
	GtkWidget *tabrecadmin,*selctionnerafficherreclamation;
	tabrecadmin=lookup_widget(objet,"tabrecadmin");
	gtk_widget_destroy(tabrecadmin);
	selctionnerafficherreclamation=create_selctionnerafficherreclamation();
	gtk_widget_show(selctionnerafficherreclamation);

	
	GtkWidget *affichercomboreclamation;

char tab[50][50];


	affichercomboreclamation=lookup_widget(selctionnerafficherreclamation,"affichercomboreclamation");
	n=remplir_combo_reclamation(tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (affichercomboreclamation),_(tab[i]));
	}

}



void
on_retourtabadmin_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *tabrecadmin,*test_rec;
	tabrecadmin=lookup_widget(objet,"tabrecadmin");
	gtk_widget_destroy(tabrecadmin);
	test_rec=create_test_rec();
	gtk_widget_show(test_rec);
}


void
on_supprimerrecadmin_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{	int i,n;
	GtkWidget *tabrecadmin,*suppressionderecadmin;
	tabrecadmin=lookup_widget(objet,"tabrecadmin");
	gtk_widget_destroy(tabrecadmin);
	suppressionderecadmin=create_suppressionderecadmin();
	gtk_widget_show(suppressionderecadmin);



	GtkWidget *idsupprecadmin;

char tab[50][50];


	idsupprecadmin=lookup_widget(suppressionderecadmin,"idsupprecadmin");
	n=remplir_combo_reclamation(tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text (GTK_COMBO_BOX (idsupprecadmin),_(tab[i]));
	}
}


void
on_supprimeridrecadmin_clicked         (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *idsupprecadmin;
GtkWidget *suppressionderecadmin;
GtkWidget *confirmationsupprimerrec;

suppressionderecadmin=lookup_widget(objet,"suppressionderecadmin");
char identif[20];
int i;
idsupprecadmin=lookup_widget(objet,"idsupprecadmin");

strcpy(identif,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idsupprecadmin)));
i=atoi(identif);
supprimer_reclamation(i);
	gtk_widget_destroy(suppressionderecadmin);
	confirmationsupprimerrec=create_confirmationsupprimerrec();
	gtk_widget_show(confirmationsupprimerrec);


}


void
on_retoursupprecadmin_clicked          (GtkWidget      *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview2recadmin;
	GtkWidget *suppressionderecadmin,*tabrecadmin;
	suppressionderecadmin=lookup_widget(objet,"suppressionderecadmin");
	gtk_widget_destroy(suppressionderecadmin);
	tabrecadmin=create_tabrecadmin();
	gtk_widget_show(tabrecadmin);
	treeview2recadmin=lookup_widget(tabrecadmin,"treeview2recadmin");
  	afficher_reclamation_admin(treeview2recadmin);
}


void
on_retoursupprecclient_clicked         (GtkWidget     *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewrecclient;
	GtkWidget *suppressionderecclient,*tabrecclient;
	suppressionderecclient=lookup_widget(objet,"suppressionderecclient");
	gtk_widget_destroy(suppressionderecclient);
	tabrecclient=create_tabrecclient();
	gtk_widget_show(tabrecclient);
	treeviewrecclient=lookup_widget(tabrecclient,"treeviewrecclient");
  	afficher_reclamation_client(treeviewrecclient);
}


void
on_supprimeridrecclient_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *suppressionderecclient;
GtkWidget *idsupprecclient;
GtkWidget *messageconfirmationsupp;

suppressionderecclient=lookup_widget(objet,"suppressionderecclient");
char identif[20];
int i;
idsupprecclient=lookup_widget(objet,"idsupprecclient");

strcpy(identif,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idsupprecclient)));
i=atoi(identif);
supprimer_reclamation(i);
	gtk_widget_destroy(suppressionderecclient);
	messageconfirmationsupp=create_messageconfirmationsupp();
	gtk_widget_show(messageconfirmationsupp);


}


void
on_okmsgrecsupp_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewrecclient;
	GtkWidget *messageconfirmationsupp,*tabrecclient;
	messageconfirmationsupp=lookup_widget(objet,"messageconfirmationsupp");
	gtk_widget_destroy(messageconfirmationsupp);
	tabrecclient=create_tabrecclient();
	gtk_widget_show(tabrecclient);
	
	treeviewrecclient=lookup_widget(tabrecclient,"treeviewrecclient");
  	afficher_reclamation_client(treeviewrecclient);
}


void
on_retourmodifierrec_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewrecclient;
	GtkWidget *modifierreclamationclient,*tabrecclient;
			 	modifierreclamationclient=lookup_widget(objet,"modifierreclamationclient");
	gtk_widget_destroy(modifierreclamationclient);
	tabrecclient=create_tabrecclient();
	gtk_widget_show(tabrecclient);
	treeviewrecclient=lookup_widget(tabrecclient,"treeviewrecclient");
  	afficher_reclamation_client(treeviewrecclient);
}


void
on_sauvegardermodifierrec_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget sauvegardermodifierrec;
	GtkWidget *dejasaisierec;
	GtkWidget *dejatypederecherche;
	FtkWidget *labelidrecmodifier;

	reclamation r;
	char a[20];
	FILE* f=NULL;
	char idreclamation[20];

	labelidrecmodifier=lookup_widget(modifierreclamationclient,"labelidrecmodifier");
	strcpy(idreclamation,gtk_label_get_text(GTK_LABEL(labelidrecmodifier)));

	f=fopen("reclamation.txt","a+");
	if(f!=NULL)
	{	
		while(fscanf(f,"%s",a)
		{
			if(stcmp(a,idreclamation)==0)
				fscanf(f,"%d %s %s %d %d %d %s %s %s \n",&r.id_rec,r.id_client,r.type,&r.date.jour,&r.date.mois,&r.date.annee,r.etat,r.text,r.reponse);
		}
	}
	fclose(f);


}


void
on_archivermodifierrec_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_afficherrecaffichage_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *selctionnerafficherreclamation;
	GtkWidget *reponsereclamation;
	GtkWidget *affichercomboreclamation;
	GtkWidget *typerecadmin;
	GtkWidget *reclamationpradmin;
  	GtkWidget *numrec;
  	GtkWidget *jj_mm_aa;
  	GtkWidget *idclient;
	GtkWidget *saisiereponsereclamation;

	char idreclamation[20];
	char test[50];
	int idrec;
	char date[20];
	char text[1000];
	char a[20];
	FILE* f1=NULL;
	FILE *f=NULL;
	reclamation r;

	affichercomboreclamation=lookup_widget(objet,"affichercomboreclamation");
	strcpy(idreclamation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(affichercomboreclamation)));



	reponsereclamation=lookup_widget(objet,"reponsereclamation");
	reponsereclamation=create_reponsereclamation();
	gtk_widget_show(reponsereclamation);
	selctionnerafficherreclamation=lookup_widget(objet,"selctionnerafficherreclamation");
	gtk_widget_destroy(selctionnerafficherreclamation);

	typerecadmin=lookup_widget(reponsereclamation,"typerecadmin");
	reclamationpradmin=lookup_widget(reponsereclamation,"reclamationpradmin");
	numrec=lookup_widget(reponsereclamation,"numrec");
	jj_mm_aa=lookup_widget(reponsereclamation,"jj_mm_aa");
	idclient=lookup_widget(reponsereclamation,"idclient");

	gtk_label_set_text(GTK_LABEL(numrec),idreclamation);
	sscanf(idreclamation,"%d",&idrec);
	
	f=fopen("reclamation.txt","r");
	if(f!=NULL)
		while(fscanf(f,"%d %s %s %d %d %d %s %s %s \n",&r.id_rec,r.id_client,r.type,&r.date.jour,&r.date.mois,&r.date.annee,r.etat,r.text,r.reponse)!=EOF)
			if(r.id_rec==idrec)
			{
				gtk_label_set_text(GTK_LABEL(idclient),r.id_client);
				sprintf(date,"%d/%d/%d",r.date.jour,r.date.mois,r.date.annee);
				gtk_label_set_text(GTK_LABEL(jj_mm_aa),date);
				gtk_entry_set_text(GTK_ENTRY(typerecadmin),r.type);

				strcpy(text,"\0");

				f1=fopen(r.text,"r");
				while(!feof(f1))
				{
					fscanf(f1,"%s ",a);
					strcat(text,a);
					strcat(text," ");
				}
				fclose(f1);

				gtk_entry_set_text(GTK_ENTRY(reclamationpradmin),text);

				strcpy(text,"\0");
				strcpy(a,"\0");

				f1=fopen(r.reponse,"a+");
				while(!feof(f1))
				{
					fscanf(f1,"%s ",a);
					strcat(text,a);
					strcat(text," ");
				}
				fclose(f1);
				saisiereponsereclamation=lookup_widget(reponsereclamation,"saisiereponsereclamation");
				gtk_entry_set_text(GTK_ENTRY(saisiereponsereclamation),text);
			}	
	fclose(f);
}


void
on_modfierreclamationchoisi_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{

	char text[1000];
	char a[20];
	FILE* f1=NULL;
	FILE *f=NULL;
	reclamation r;
	char idreclamation[20];
	int idrec;


	GtkWidget *modifierreclamationclient,*selectmodfierreclamation,*modifiercomborec,*dejasaisierec;
	GtkWidget *labelidrecmodifier;

	selectmodfierreclamation=lookup_widget(objet,"selectmodfierreclamation");

	modifiercomborec=lookup_widget(objet,"modifiercomborec");
	strcpy(idreclamation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(modifiercomborec)));


	gtk_widget_destroy(selectmodfierreclamation);
	modifierreclamationclient=create_modifierreclamationclient();
	gtk_widget_show(modifierreclamationclient);

	labelidrecmodifier=lookup_widget(modifierreclamationclient,"labelidrecmodifier");
	gtk_label_set_text(GTK_LABEL(labelidrecmodifier),idreclamation);

	dejasaisierec=lookup_widget(modifierreclamationclient,"dejasaisierec");
	sscanf(idreclamation,"%d",&idrec);
	f=fopen("reclamation.txt","r");
	if(f!=NULL)
		while(fscanf(f,"%d %s %s %d %d %d %s %s %s \n",&r.id_rec,r.id_client,r.type,&r.date.jour,&r.date.mois,&r.date.annee,r.etat,r.text,r.reponse)!=EOF)

			if(r.id_rec==idrec)
			{
				strcpy(text,"\0");
				strcpy(a,"\0");
			
				f1=fopen(r.text,"r");
				while(!feof(f1))
				{
					fscanf(f1,"%s",a);
					strcat(text,a);
					strcat(text," ");
				}
				fclose(f1);

				gtk_entry_set_text(GTK_ENTRY(dejasaisierec),text);

			}
}


void
on_retourmodfierreclamation_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewrecclient;
	GtkWidget *selectmodfierreclamation,*tabrecclient;
			 	selectmodfierreclamation=lookup_widget(objet,"selectmodfierreclamation");
	gtk_widget_destroy(selectmodfierreclamation);
	tabrecclient=create_tabrecclient();
	gtk_widget_show(tabrecclient);
	treeviewrecclient=lookup_widget(tabrecclient,"treeviewrecclient");
  	afficher_reclamation_client(treeviewrecclient);
}


void
on_button_test_rec_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *treeviewrecclient;
	GtkWidget *tabrecclient;
	GtkWidget *test_rec;
	
	test_rec=lookup_widget(objet,"test_rec");
	gtk_widget_destroy(test_rec);
	tabrecclient=lookup_widget(objet,"tabrecclient");
  	tabrecclient = create_tabrecclient ();
  	gtk_widget_show (tabrecclient);
  	treeviewrecclient=lookup_widget(tabrecclient,"treeviewrecclient");
  	afficher_reclamation_client(treeviewrecclient);
	
	GtkWidget *treeview2recadmin;
	GtkWidget *tabrecadmin;
	
test_rec=lookup_widget(objet,"test_rec");
	gtk_widget_destroy(test_rec);
	tabrecadmin=lookup_widget(objet,"tabrecadmin");
  	tabrecadmin=create_tabrecadmin ();
  	gtk_widget_show (tabrecadmin);
  	treeview2recadmin=lookup_widget(tabrecadmin,"treeview2recadmin");
  	afficher_reclamation_admin(treeview2recadmin);



}

void
on_retouridaffichagerecadmin_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview2recadmin;
	GtkWidget *selctionnerafficherreclamation,*tabrecadmin;
	selctionnerafficherreclamation=lookup_widget(objet,"selctionnerafficherreclamation");
	gtk_widget_destroy(selctionnerafficherreclamation);
	tabrecadmin=create_tabrecadmin();
	gtk_widget_show(tabrecadmin);
	treeview2recadmin=lookup_widget(tabrecadmin,"treeview2recadmin");
  	afficher_reclamation_admin(treeview2recadmin);
}


void
on_okreponseenvoyee_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview2recadmin;
	GtkWidget *msgreponserec,*tabrecadmin;
	msgreponserec=lookup_widget(objet,"msgreponserec");
	gtk_widget_destroy(msgreponserec);
	tabrecadmin=create_tabrecadmin();
	gtk_widget_show(tabrecadmin);
	
	treeview2recadmin=lookup_widget(tabrecadmin,"treeview2recadmin");
  	afficher_reclamation_admin(treeview2recadmin);
}


void
on_buttonoksupprimerrec_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview2recadmin;
	GtkWidget *confirmationsupprimerrec,*tabrecadmin;
	confirmationsupprimerrec=lookup_widget(objet,"confirmationsupprimerrec");
	gtk_widget_destroy(confirmationsupprimerrec);
	tabrecadmin=create_tabrecadmin();
	gtk_widget_show(tabrecadmin);
	
	treeview2recadmin=lookup_widget(tabrecadmin,"treeview2recadmin");
  	afficher_reclamation_admin(treeview2recadmin);
}


void
on_okarchiverrec_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}

