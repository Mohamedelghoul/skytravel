#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "facture.h"

void
on_Modifier_ADH_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *WModifier_CDH;	
	GtkWidget *menufacdevis;
	Dhebergement tab[50];
	GtkWidget *comboboxidMADH; 
	int i,n;

	menufacdevis=lookup_widget(objet,"menufacdevis");
	gtk_widget_destroy(menufacdevis);
	WModifier_CDH=create_WModifier_CDH();
	gtk_widget_show(WModifier_CDH);

	comboboxidMADH=lookup_widget(WModifier_CDH,"comboboxidMADH");
	n=remplir_combo_hebergement(tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX (comboboxidMADH),_(tab[i].id_devis));
	}
}


void
on_Modifier_ADE_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *WModifier_CDE;	
	GtkWidget *menufacdevis;
	Dexcursion tab[50];
	GtkWidget *comboboxidMADE;
	int i,n;

	menufacdevis=lookup_widget(objet,"menufacdevis");
	gtk_widget_destroy(menufacdevis);
	WModifier_CDE=create_WModifier_CDE();
	gtk_widget_show(WModifier_CDE);

	comboboxidMADE=lookup_widget(WModifier_CDE,"comboboxidMADE");
	n=remplir_combo_excursion(tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX (comboboxidMADE),_(tab[i].id_devis));
	}
}


void
on_Modifier_ADV_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *WModifier_CDV;	
	GtkWidget *menufacdevis;
	Dvol tab[50];
	GtkWidget *comboboxidMADV;
	int i,n;

	menufacdevis=lookup_widget(objet,"menufacdevis");
	gtk_widget_destroy(menufacdevis);
	WModifier_CDV=create_WModifier_CDV();
	gtk_widget_show(WModifier_CDV);

	comboboxidMADV=lookup_widget(WModifier_CDV,"comboboxidMADV");
	n=remplir_combo_vol(tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX (comboboxidMADV),_(tab[i].id_devis));
	}
}


void
on_ValiderCDH_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Window_codeCDH;
	GtkWidget *menufacdevis;
	GtkWidget *input1;
	GtkWidget *msg;

	char identifiant[30];
	char idC[30];
	FILE *f3;
	f3=fopen("actual_user.txt","r");
	fscanf(f3,"%s",identifiant);
	strcpy(idC,identifiant); 
	
	float montantf,M,P;
	char code[30];
	char code1[30];
	char promos[30];
	Dhebergement H;
	
	input1=lookup_widget(objet,"entrycodeCDH");
	strcpy(code,gtk_entry_get_text(GTK_ENTRY(input1)));
	char Montant[30];
	FILE* f=NULL;
	FILE* f1=NULL;
	FILE* f2=NULL;
	f1=fopen("devishebergement.txt","a+");
	f=fopen("codepromos.txt","a+");
	f2=fopen("devishebergement_copie.txt","a+");

	Window_codeCDH=lookup_widget(objet,"Window_codeCDH");
	Window_codeCDH=create_Window_codeCDH();
	gtk_widget_show(Window_codeCDH);
	menufacdevis=lookup_widget(objet,"menufacdevis");
	gtk_widget_destroy(menufacdevis);

	msg=lookup_widget(Window_codeCDH,"introuvablecodeCDH");

	if(f!=NULL)
	{
		while(fscanf(f,"%s %s \n",code1,promos)!=EOF)
		{
			if((strcmp(code,code1)==0))
			{
				gtk_label_set_text(GTK_LABEL(msg),"Code promos bien valider !");
				while(fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",H.id_devis,H.identifiant,H.id_reservation,H.id_hebergement,H.depart,H.arrivee,H.destination,H.nom_hotel,H.personne,H.enfants,H.chambres,H.pension,H.montant)!=EOF)
				{
					if ((strcmp(idC,H.identifiant)==0))
					{
						sscanf(H.montant,"%f",&M);
						sscanf(promos,"%f",&P);
						montantf=M*P;
						sprintf(H.montant,"%f",montantf);
					}
				fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",H.id_devis,H.identifiant,H.id_reservation,H.id_hebergement,H.depart,H.arrivee,H.destination,H.nom_hotel,H.personne,H.enfants,H.chambres,H.pension,H.montant);
								
				}
				remove("devishebergement.txt");
				rename("devishebergement_copie.txt","devishebergement.txt");
			}

		}
	}

	fclose(f);
	fclose(f1);
	fclose(f2);
	fclose(f3);
}


void
on_ContinuerCDH_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *WContinuer_CDH;	
	GtkWidget *menufacdevis;
	char tab[50][50];
	char idC[30]="\0";
	char identifiant[30];
	GtkWidget *comboboxCCDH;
	int i,n;
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 

	menufacdevis=lookup_widget(objet,"menufacdevis");
	gtk_widget_destroy(menufacdevis);
	WContinuer_CDH=create_WContinuer_CDH();
	gtk_widget_show(WContinuer_CDH);

	comboboxCCDH=lookup_widget(WContinuer_CDH,"comboboxCCDH");
	n=remplir_combo_hebergement_client(idC,tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX (comboboxCCDH),_(tab[i]));
	}
}


void
on_AnnulerCDH_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *WAnnuler_CDH;	
	GtkWidget *menufacdevis;
	char tab[50][50];
	char idC[30];
	char identifiant[30];
	GtkWidget *comboboxACDH;
	int i,n;
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 

	menufacdevis=lookup_widget(objet,"menufacdevis");
	gtk_widget_destroy(menufacdevis);
	WAnnuler_CDH=lookup_widget(objet,"WAnnuler_CDH");
	WAnnuler_CDH=create_WAnnuler_CDH();
	gtk_widget_show(WAnnuler_CDH);

	comboboxACDH=lookup_widget(WAnnuler_CDH,"comboboxACDH");
	n=remplir_combo_hebergement_client(idC,tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX (comboboxACDH),_(tab[i]));
	}
}


void
on_AnnulerCDE_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *WAnnuler_CDE;	
	GtkWidget *menufacdevis;
	char tab[50][50];
	char idC[30]="\0";
	char identifiant[30];
	GtkWidget *comboboxACDE;
	int i,n;
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 

	menufacdevis=lookup_widget(objet,"menufacdevis");
	gtk_widget_destroy(menufacdevis);
	WAnnuler_CDE=create_WAnnuler_CDE();
	gtk_widget_show(WAnnuler_CDE);

	comboboxACDE=lookup_widget(WAnnuler_CDE,"comboboxACDE");
	n=remplir_combo_excursion_client(idC,tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX (comboboxACDE),_(tab[i]));
	}
}


void
on_ContinuerCDE_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *WContinuer_CDE;	
	GtkWidget *menufacdevis;
	char tab[50][50];
	char idC[30]="\0";
	char identifiant[30];
	GtkWidget *comboboxCCDE;
	int i,n;
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 

	menufacdevis=lookup_widget(objet,"menufacdevis");
	gtk_widget_destroy(menufacdevis);
	WContinuer_CDE=create_WContinuer_CDE();
	gtk_widget_show(WContinuer_CDE);

	comboboxCCDE=lookup_widget(WContinuer_CDE,"comboboxCCDE");
	n=remplir_combo_excursion_client(idC,tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX (comboboxCCDE),_(tab[i]));
	}
}


void
on_ValiderCDE_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window_codeCDE;
	GtkWidget *menufacdevis;
	GtkWidget *input1;
	GtkWidget *msg;

	char identifiant[30];
	char idC[30];
	FILE *f3;
	f3=fopen("actual_user.txt","r");
	fscanf(f3,"%s",identifiant);
	strcpy(idC,identifiant); 
	
	float montantf,M,P;
	char code[30];
	char code1[30];
	char promos[30];
	Dexcursion E;
	
	input1=lookup_widget(objet,"entrycodeCDE");
	strcpy(code,gtk_entry_get_text(GTK_ENTRY(input1)));
	char Montant[30];
	FILE* f=NULL;
	FILE* f1=NULL;
	FILE* f2=NULL;
	f1=fopen("devisexcursion.txt","a+");
	f=fopen("codepromos.txt","a+");
	f2=fopen("devisexcursion_copie.txt","a+");

	window_codeCDE=lookup_widget(objet,"window_codeCDE");
	window_codeCDE=create_window_codeCDE();
	gtk_widget_show(window_codeCDE);
	menufacdevis=lookup_widget(objet,"menufacdevis");
	gtk_widget_destroy(menufacdevis);

	msg=lookup_widget(window_codeCDE,"introuvablecodeCDE");

	if(f!=NULL)
	{
		while(fscanf(f,"%s %s \n",code1,promos)!=EOF)
		{
			if((strcmp(code,code1)==0))
			{
				gtk_label_set_text(GTK_LABEL(msg),"Code promos bien valider !");
				while(fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s \n",E.id_devis,E.identifiant,E.id_reservation,E.id_excursion,E.depart,E.arrivee,E.d.jour,E.d.mois,E.d.annee,E.personne,E.montant)!=EOF)
				{
					if ((strcmp(idC,E.identifiant)==0))
					{
						sscanf(E.montant,"%f",&M);
						sscanf(promos,"%f",&P);
						montantf=M*P;
						sprintf(E.montant,"%f",montantf);
					}
				fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s \n",E.id_devis,E.identifiant,E.id_reservation,E.id_excursion,E.depart,E.arrivee,E.d.jour,E.d.mois,E.d.annee,E.personne,E.montant);
								
				}
				remove("devisexcursion.txt");
				rename("devisexcursion_copie.txt","devisexcursion.txt");
			}

		}
	}

	fclose(f);
	fclose(f1);
	fclose(f2);
	fclose(f3);
}


void
on_ValiderCDV_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window_codeCDV;
	GtkWidget *menufacdevis;
	GtkWidget *input1;
	GtkWidget *msg;

	char identifiant[30];
	char idC[30];
	FILE *f3;
	f3=fopen("actual_user.txt","r");
	fscanf(f3,"%s",identifiant);
	strcpy(idC,identifiant); 
	
	float montantf,M,P;
	char code[30];
	char code1[30];
	char promos[30];
	Dvol V;
	
	input1=lookup_widget(objet,"entrycodeCDV");
	strcpy(code,gtk_entry_get_text(GTK_ENTRY(input1)));
	char Montant[30];
	FILE* f=NULL;
	FILE* f1=NULL;
	FILE* f2=NULL;
	f1=fopen("devisvol.txt","a+");
	f=fopen("codepromos.txt","a+");
	f2=fopen("devisvol_copie.txt","a+");

	window_codeCDV=lookup_widget(objet,"window_codeCDV");
	window_codeCDV=create_window_codeCDV();
	gtk_widget_show(window_codeCDV);
	menufacdevis=lookup_widget(objet,"menufacdevis");
	gtk_widget_destroy(menufacdevis);

	msg=lookup_widget(window_codeCDV,"introuvablecodeCDV");

	if(f!=NULL)
	{
		while(fscanf(f,"%s %s \n",code1,promos)!=EOF)
		{
			if((strcmp(code,code1)==0))
			{
				gtk_label_set_text(GTK_LABEL(msg),"Code promos bien valider !");
				while(fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",V.id_devis,V.identifiant,V.id_reservation,V.id_vol,V.depart.jour,V.depart.mois,V.depart.annee,V.arrivee.jour,V.arrivee.mois,V.arrivee.annee,V.vdepart,V.vdestination,V.personne,V.montant)!=EOF)
				{
					if ((strcmp(idC,V.identifiant)==0))
					{
						sscanf(V.montant,"%f",&M);
						sscanf(promos,"%f",&P);
						montantf=M*P;
						sprintf(V.montant,"%f",montantf);
					}
				fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",V.id_devis,V.identifiant,V.id_reservation,V.id_vol,V.depart.jour,V.depart.mois,V.depart.annee,V.arrivee.jour,V.arrivee.mois,V.arrivee.annee,V.vdepart,V.vdestination,V.personne,V.montant);
								
				}
				remove("devisvol.txt");
				rename("devisvol_copie.txt","devisvol.txt");
			}

		}
	}

	fclose(f);
	fclose(f1);
	fclose(f2);
	fclose(f3);
}


void
on_ContinuerCDV_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *WContinuer_CDV;	
	GtkWidget *menufacdevis;
	char tab[50][50];
	char idC[30]="\0";
	char identifiant[30];
	GtkWidget *comboboxCCDV;
	int i,n;
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 

	menufacdevis=lookup_widget(objet,"menufacdevis");
	gtk_widget_destroy(menufacdevis);
	WContinuer_CDV=create_WContinuer_CDV();
	gtk_widget_show(WContinuer_CDV);

	comboboxCCDV=lookup_widget(WContinuer_CDV,"comboboxCCDV");
	n=remplir_combo_vol_client(idC,tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX (comboboxCCDV),_(tab[i]));
	}
}


void
on_AnnulerCDV_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *WAnnuler_CDV;	
	GtkWidget *menufacdevis;
	char tab[50][50];
	char idC[30]="\0";
	char identifiant[30];
	GtkWidget *comboboxACDV;
	int i,n;
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 

	menufacdevis=lookup_widget(objet,"menufacdevis");
	gtk_widget_destroy(menufacdevis);
	WAnnuler_CDV=create_WAnnuler_CDV();
	gtk_widget_show(WAnnuler_CDV);

	comboboxACDV=lookup_widget(WAnnuler_CDV,"comboboxACDV");
	n=remplir_combo_vol_client(idC,tab);
	for(i=0;i<n;i++)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX (comboboxACDV),_(tab[i]));
	}
}


void
on_OKcodeCDH_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Window_codeCDH;
	GtkWidget *menufacdevis;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30];
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 
	fclose(f);


	Window_codeCDH=lookup_widget(objet,"Window_codeCDH");
	gtk_widget_destroy(Window_codeCDH);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);

	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
	
}


void
on_OKcodeCDE_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Window_codeCDE;
	GtkWidget *menufacdevis;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30];
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 
	fclose(f);


	Window_codeCDE=lookup_widget(objet,"Window_codeCDE");
	gtk_widget_destroy(Window_codeCDE);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);

	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_OKcodeCDV_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Window_codeCDV;
	GtkWidget *menufacdevis;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30];
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 
	fclose(f);

	Window_codeCDV=lookup_widget(objet,"Window_codeCDV");
	gtk_widget_destroy(Window_codeCDV);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);

	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}

void
on_R_AnnulerF_CDH_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *WAnnuler_CDH;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30];
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 
	fclose(f);
	WAnnuler_CDH=lookup_widget(objet,"WAnnuler_CDH");

	gtk_widget_destroy(WAnnuler_CDH);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);
	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_AnnulerF_CDH_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *comboboxACDH;
	GtkWidget *WAnnuler_CDH ;
	GtkWidget *Reservation_annulerH;
	char id[30];
	
	comboboxACDH=lookup_widget(objet,"comboboxACDH");
	strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxACDH)));
	supprimer_devis(id,0);

	WAnnuler_CDH=lookup_widget(objet,"WAnnuler_CDH");
	gtk_widget_destroy(WAnnuler_CDH);
	Reservation_annulerH=lookup_widget(objet,"Reservation_annulerH");
	Reservation_annulerH=create_Reservation_annulerH();
	gtk_widget_show(Reservation_annulerH);
}


void
on_AnnulerF_CDE_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *comboboxACDE;
	GtkWidget *WAnnuler_CDE;
	GtkWidget *Reservation_annulerE;
	char id[30];
	
	comboboxACDE=lookup_widget(objet,"comboboxACDE");
	strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxACDE)));
	supprimer_devis(id,1);

	WAnnuler_CDE=lookup_widget(objet,"WAnnuler_CDE");
	gtk_widget_destroy(WAnnuler_CDE);
	Reservation_annulerE=lookup_widget(objet,"Reservation_annulerE");
	Reservation_annulerE=create_Reservation_annulerE();
	gtk_widget_show(Reservation_annulerE);
}


void
on_R_AnnulerF_CDE_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *WAnnuler_CDE;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30];
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 
	fclose(f);
	WAnnuler_CDE=lookup_widget(objet,"WAnnuler_CDE");

	gtk_widget_destroy(WAnnuler_CDE);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);
	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_R_AnnulerF_CDV_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *WAnnuler_CDV;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30];
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 
	fclose(f);
	WAnnuler_CDV=lookup_widget(objet,"WAnnuler_CDV");

	gtk_widget_destroy(WAnnuler_CDV);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);
	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_AnnulerF_CDV_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *comboboxACDV;
	GtkWidget *WAnnuler_CDV ;
	GtkWidget *Reservation_annulerV;
	char id[30];
	
	comboboxACDV=lookup_widget(objet,"comboboxACDV");
	strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxACDV)));
	supprimer_devis(id,2);

	WAnnuler_CDV=lookup_widget(objet,"WAnnuler_CDV");
	gtk_widget_destroy(WAnnuler_CDV);
	Reservation_annulerV=lookup_widget(objet,"Reservation_annulerV");
	Reservation_annulerV=create_Reservation_annulerV();
	gtk_widget_show(Reservation_annulerV);
}


void
on_ContinuerF_CDH_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *mode_payement, *WContinuer_CDH;
	GtkWidget *comboboxCCDH;
	GtkWidget *iddevisMP;
	char id[30];
	char mode[30];
	
	comboboxCCDH=lookup_widget(objet,"comboboxCCDH");
	strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxCCDH)));

	mode_payement=lookup_widget(objet,"mode_payement");
	mode_payement=create_mode_payement();
	gtk_widget_show(mode_payement);	
	WContinuer_CDH=lookup_widget(objet,"WContinuer_CDH");
	gtk_widget_destroy(WContinuer_CDH);

	iddevisMP=lookup_widget(mode_payement,"iddevisMP");
	gtk_entry_set_text(GTK_ENTRY(iddevisMP),id);

}


void
on_R_ContinuerF_CDH_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *WContinuer_CDH;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 
	fclose(f);

	WContinuer_CDH=lookup_widget(objet,"WContinuer_CDH");

	gtk_widget_destroy(WContinuer_CDH);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);
	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_ContinuerF_CDE_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *mode_payement_E, *WContinuer_CDE;
	GtkWidget *comboboxCCDE;
	GtkWidget *iddevisMPE;
	char id[30];
	char mode[30];
	
	comboboxCCDE=lookup_widget(objet,"comboboxCCDE");
	strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxCCDE)));

	mode_payement_E=lookup_widget(objet,"mode_payement_E");
	mode_payement_E=create_mode_payement_E();
	gtk_widget_show(mode_payement_E);	
	WContinuer_CDE=lookup_widget(objet,"WContinuer_CDE");
	gtk_widget_destroy(WContinuer_CDE);

	iddevisMPE=lookup_widget(mode_payement_E,"iddevisMPE");
	gtk_entry_set_text(GTK_ENTRY(iddevisMPE),id);
}


void
on_R_ContinuerF_CDE_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *WContinuer_CDE;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 
	fclose(f);

	WContinuer_CDE=lookup_widget(objet,"WContinuer_CDE");

	gtk_widget_destroy(WContinuer_CDE);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);
	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_ContinuerF_CDV_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *mode_payement_V, *WContinuer_CDV;
	GtkWidget *comboboxCCDV;
	GtkWidget *iddevisMPV;
	char id[30];
	char mode[30];
	
	comboboxCCDV=lookup_widget(objet,"comboboxCCDV");
	strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxCCDV)));

	mode_payement_V=lookup_widget(objet,"mode_payement_V");
	mode_payement_V=create_mode_payement_V();
	gtk_widget_show(mode_payement_V);	
	WContinuer_CDV=lookup_widget(objet,"WContinuer_CDV");
	gtk_widget_destroy(WContinuer_CDV);

	iddevisMPV=lookup_widget(mode_payement_V,"iddevisMPV");
	gtk_entry_set_text(GTK_ENTRY(iddevisMPV),id);
}


void
on_R_ContinuerF_CDV_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *WContinuer_CDV;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 
	fclose(f);

	WContinuer_CDV=lookup_widget(objet,"WContinuer_CDV");

	gtk_widget_destroy(WContinuer_CDV);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);
	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_ValiderR_CDH_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	char reduction[30];
	char id[30];	
	char identifiant[30];
	char idC[30];
	GtkWidget *input1;
	GtkWidget *comboboxidMADH;
	GtkWidget *WModifier_CDH;
	GtkWidget *Reduction_validerH;
	Dhebergement H;
	Dhebergement H1;
	char montantF[30];
	float R,R1,montant,montantf;



	input1=lookup_widget(objet,"entryreductionCDH");
	strcpy(reduction,gtk_entry_get_text(GTK_ENTRY(input1)));
	sscanf(reduction,"%f",&R);
	R1=((100-R)/100);

	comboboxidMADH=lookup_widget(objet,"comboboxidMADH");
	strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxidMADH)));
	FILE* f=NULL;
	FILE* f1=NULL;
	f=fopen("devishebergement.txt","a+");
	f1=fopen("devishebergement_copie.txt","w");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",H.id_devis,H.identifiant,H.id_reservation,H.id_hebergement,H.depart,H.arrivee,H.destination,H.nom_hotel,H.personne,H.enfants,H.chambres,H.pension,H.montant)!=EOF)
		{
			if((strcmp(id,H.id_devis)==0))
			{
				
				sscanf(H.montant,"%f",&montant);
				montantf=montant*R1;
				sprintf(H.montant,"%f",montantf);
				
			}
			fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",H.id_devis,H.identifiant,H.id_reservation,H.id_hebergement,H.depart,H.arrivee,H.destination,H.nom_hotel,H.personne,H.enfants,H.chambres,H.pension,H.montant);
				
		}
		fclose(f);
		fclose(f1);
		remove("devishebergement.txt");
		rename("devishebergement_copie.txt","devishebergement.txt");

	}

	
	WModifier_CDH=lookup_widget(objet,"WModifier_CDH");
	gtk_widget_destroy(WModifier_CDH);
	Reduction_validerH=lookup_widget(objet,"Reduction_validerH");
	Reduction_validerH=create_Reduction_validerH();
	gtk_widget_show(Reduction_validerH);
	
	
	
}

void
on_R_ValiderR_CDH_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *WModifier_CDH;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	fclose(f);
	strcpy(idC,identifiant); 


	WModifier_CDH=lookup_widget(objet,"WModifier_CDH");
	gtk_widget_destroy(WModifier_CDH);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);


	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_R_ValiderR_CDE_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *WModifier_CDE;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	fclose(f);
	strcpy(idC,identifiant); 


	WModifier_CDE=lookup_widget(objet,"WModifier_CDE");
	gtk_widget_destroy(WModifier_CDE);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);


	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_ValiderR_CDE_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	char reduction[30];
	char id[30];	
	char identifiant[30];
	char idC[30];
	GtkWidget *input1;
	GtkWidget *comboboxidMADE;
	GtkWidget *WModifier_CDE;
	GtkWidget *Reduction_validerE;
	Dexcursion E;
	Dexcursion E1;
	char montantF[30];
	float R,R1,montant,montantf;



	input1=lookup_widget(objet,"entryreductionCDE");
	strcpy(reduction,gtk_entry_get_text(GTK_ENTRY(input1)));
	sscanf(reduction,"%f",&R);
	R1=((100-R)/100);

	comboboxidMADE=lookup_widget(objet,"comboboxidMADE");
	strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxidMADE)));
	FILE* f=NULL;
	FILE* f1=NULL;
	f=fopen("devisexcursion.txt","a+");
	f1=fopen("devisexcursion_copie.txt","w");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",E.id_devis,E.identifiant,E.id_reservation,E.id_excursion,E.depart,E.arrivee,E.d.jour,E.d.mois,E.d.annee,E.personne,E.montant)!=EOF)
		{
			if((strcmp(id,E.id_devis)==0))
			{
				
				sscanf(E.montant,"%f",&montant);
				montantf=montant*R1;
				sprintf(E.montant,"%f",montantf);
				
			}
			fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s \n",E.id_devis,E.identifiant,E.id_reservation,E.id_excursion,E.depart,E.arrivee,E.d.jour,E.d.mois,E.d.annee,E.personne,E.montant);
				
		}
		fclose(f);
		fclose(f1);
		remove("devisexcursion.txt");
		rename("devisexcursion_copie.txt","devisexcursion.txt");

	}

	
	WModifier_CDE=lookup_widget(objet,"WModifier_CDE");
	gtk_widget_destroy(WModifier_CDE);
	Reduction_validerE=lookup_widget(objet,"Reduction_validerE");
	Reduction_validerE=create_Reduction_validerE();
	gtk_widget_show(Reduction_validerE);
}


void
on_R_ValiderR_CDV_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *WModifier_CDV;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	fclose(f);
	strcpy(idC,identifiant); 


	WModifier_CDV=lookup_widget(objet,"WModifier_CDV");
	gtk_widget_destroy(WModifier_CDV);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);


	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_ValiderR_CDV_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	char reduction[30];
	char id[30];	
	char identifiant[30];
	char idC[30];
	GtkWidget *input1;
	GtkWidget *comboboxidMADV;
	GtkWidget *WModifier_CDV;
	GtkWidget *Reduction_validerV;
	Dvol V;
	Dvol V1;
	char montantF[30];
	float R,R1,montant,montantf;



	input1=lookup_widget(objet,"entryreductionCDV");
	strcpy(reduction,gtk_entry_get_text(GTK_ENTRY(input1)));
	sscanf(reduction,"%f",&R);
	R1=((100-R)/100);

	comboboxidMADV=lookup_widget(objet,"comboboxidMADV");
	strcpy(id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxidMADV)));
	FILE* f=NULL;
	FILE* f1=NULL;
	f=fopen("devisvol.txt","a+");
	f1=fopen("devisvol_copie.txt","w");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",V.id_devis,V.identifiant,V.id_reservation,V.id_vol,V.depart.jour,V.depart.mois,V.depart.annee,V.arrivee.jour,V.arrivee.mois,V.arrivee.annee,V.vdepart,V.vdestination,V.personne,V.montant)!=EOF)
		{
			if((strcmp(id,V.id_devis)==0))
			{
				
				sscanf(V.montant,"%f",&montant);
				montantf=montant*R1;
				sprintf(V.montant,"%f",montantf);
				
			}
			fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",V.id_devis,V.identifiant,V.id_reservation,V.id_vol,V.depart.jour,V.depart.mois,V.depart.annee,V.arrivee.jour,V.arrivee.mois,V.arrivee.annee,V.vdepart,V.vdestination,V.personne,V.montant);
				
		}
		fclose(f);
		fclose(f1);
		remove("devisvol.txt");
		rename("devisvol_copie.txt","devisvol.txt");

	}

	
	WModifier_CDV=lookup_widget(objet,"WModifier_CDV");
	gtk_widget_destroy(WModifier_CDV);
	Reduction_validerV=lookup_widget(objet,"Reduction_validerV");
	Reduction_validerV=create_Reduction_validerV();
	gtk_widget_show(Reduction_validerV);
}


void
on_OKReservation_annulerH_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *Reservation_annulerH;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 


	Reservation_annulerH=lookup_widget(objet,"Reservation_annulerH");
	gtk_widget_destroy(Reservation_annulerH);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);


	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_OKReduction_validerH_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *Reduction_validerH;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 


	Reduction_validerH=lookup_widget(objet,"Reduction_validerH");
	gtk_widget_destroy(Reduction_validerH);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);


	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_OKReservation_annulerE_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *Reservation_annulerE;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 


	Reservation_annulerE=lookup_widget(objet,"Reservation_annulerE");
	gtk_widget_destroy(Reservation_annulerE);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);


	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_OKReservation_annulerV_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *Reservation_annulerV;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 


	Reservation_annulerV=lookup_widget(objet,"Reservation_annulerV");
	gtk_widget_destroy(Reservation_annulerV);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);


	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_OKReduction_validerE_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *Reduction_validerE;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 


	Reduction_validerE=lookup_widget(objet,"Reduction_validerE");
	gtk_widget_destroy(Reduction_validerE);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);


	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_OKReduction_validerV_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menufacdevis, *Reduction_validerV;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 


	Reduction_validerV=lookup_widget(objet,"Reduction_validerV");
	gtk_widget_destroy(Reduction_validerV);
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);


	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_button_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Window;
	GtkWidget *menufacdevis;
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	char identifiant[30];
	char idC[30]="\0";
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 


	Window=lookup_widget(objet,"Window");	

	gtk_widget_destroy(Window);
	menufacdevis=lookup_widget(objet,"menufacdevis");
	menufacdevis=create_menufacdevis();

	gtk_widget_show(menufacdevis);

	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);
	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
	
}


void
on_R_validermodepayement_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *WContinuer_CDH;
	GtkWidget *mode_payement;
	GtkWidget *comboboxCCDH;
	mode_payement=lookup_widget(objet,"mode_payement");
	gtk_widget_destroy(mode_payement);
	WContinuer_CDH=lookup_widget(objet,"WContinuer_CDH");
	WContinuer_CDH=create_WContinuer_CDH();
	gtk_widget_show(WContinuer_CDH);
}


void
on_Validermodepayement_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *mode_payement;
	GtkWidget *input1 ;
	GtkWidget *Payement;
	GtkWidget *bienvenueespece;
	GtkWidget *comboboxmodepayement;
	GtkWidget *comboboxCCDH;
	GtkWidget *iddevisMP;
	GtkWidget *iddevispayement;
	GtkWidget *entrymontantpayementF;
	char code[30];
	char id[30];
	char mode[30];
	GtkWidget *WContinuer_CDH;

	comboboxmodepayement=lookup_widget(objet,"comboboxmodepayement");
	strcpy(mode,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodepayement)));

	if((strcmp(mode,"Espece")==0))
	{
		mode_payement=lookup_widget(objet,"mode_payement");
		gtk_widget_destroy(mode_payement);

		
		bienvenueespece=lookup_widget(objet,"bienvenueespece");
		bienvenueespece=create_bienvenueespece();
		gtk_widget_show(bienvenueespece);	
	}
	else
	{

	mode_payement=lookup_widget(objet,"mode_payement");
	

	char A[50];
	char id1[30];
	FILE *f=NULL;
	Dhebergement H;
	f=fopen("devishebergement.txt","a+");
	Payement=lookup_widget(objet,"Payement");
	Payement=create_Payement();
	gtk_widget_show(Payement);
	iddevisMP=lookup_widget(mode_payement,"iddevisMP");
	strcpy(id1,gtk_entry_get_text(GTK_ENTRY(iddevisMP)));
	gtk_widget_destroy(mode_payement);

	if(f!=NULL)
	{

		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",H.id_devis,H.identifiant,H.id_reservation,H.id_hebergement,H.depart,H.arrivee,H.destination,H.nom_hotel,H.personne,H.enfants,H.chambres,H.pension,H.montant)!=EOF)			
			if(strcmp(H.id_devis,id1)==0)
			{
				entrymontantpayementF=lookup_widget(Payement,"entrymontantpayementF");
				gtk_entry_set_text(GTK_ENTRY(entrymontantpayementF),H.montant);


			}
	fclose(f);
	}

	iddevispayement=lookup_widget(Payement,"iddevispayement");
	gtk_entry_set_text(GTK_ENTRY(iddevispayement),id1); 
	}
	
}


void
on_PayerF_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Payement;
	GtkWidget *Facpayee;
	GtkWidget *WContinuer_CDH;
	GtkWidget *iddevispayement;
	GtkWidget *input1;
	GtkWidget *input2;
	Dhebergement H;
	char idC[30];
	char idP[30];
	char identifiant[30];
	FILE *f;
	FILE *f1;
	FILE *f2;
	f1=fopen("devishebergement.txt","a+");
	f2=fopen("facturehebergement.txt","a+");
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 
	Payement=lookup_widget(objet,"Payement");

	input1=lookup_widget(Payement,"iddevispayement");
	strcpy(idP,gtk_entry_get_text(GTK_ENTRY(input1)));

	gtk_widget_destroy(Payement);

	if(f1!=NULL)
	{
		while(fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",H.id_devis,H.identifiant,H.id_reservation,H.id_hebergement,H.depart,H.arrivee,H.destination,H.nom_hotel,H.personne,H.enfants,H.chambres,H.pension,H.montant)!=EOF)
		{
			if(strcmp(idP,H.id_devis)==0)
			{

				fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",H.id_devis,H.identifiant,H.id_reservation,H.id_hebergement,H.depart,H.arrivee,H.destination,H.nom_hotel,H.personne,H.enfants,H.chambres,H.pension,H.montant);
			}
		}
	}


	fclose(f);
	fclose(f1);
	fclose(f2);
	supprimer_devis(idP,0);

	Facpayee=lookup_widget(objet,"Facpayee");
	Facpayee=create_Facpayee();
	gtk_widget_show(Facpayee);
}


void
on_R_payerF_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Payement;
	GtkWidget *mode_payement;
	Payement=lookup_widget(objet,"Payement");
	gtk_widget_destroy(Payement);
	mode_payement=lookup_widget(objet,"mode_payement");
	mode_payement=create_mode_payement();
	gtk_widget_show(mode_payement);
}


void
on_R_validermodepayementE_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *WContinuer_CDE;
	GtkWidget *mode_payement_E;
	mode_payement_E=lookup_widget(objet,"mode_payement_E");
	gtk_widget_destroy(mode_payement_E);
	WContinuer_CDE=lookup_widget(objet,"WContinuer_CDE");
	WContinuer_CDE=create_WContinuer_CDE();
	gtk_widget_show(WContinuer_CDE);
	
}

void
on_R_validermodepayementV_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *WContinuer_CDV;
	GtkWidget *mode_payement_V;
	mode_payement_V=lookup_widget(objet,"mode_payement_V");
	gtk_widget_destroy(mode_payement_V);
	WContinuer_CDV=lookup_widget(objet,"WContinuer_CDV");
	WContinuer_CDV=create_WContinuer_CDV();
	gtk_widget_show(WContinuer_CDV);
}


void
on_ValidermodepayementE_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *mode_payement_E;
	GtkWidget *input1 ;
	GtkWidget *PayementE;
	GtkWidget *bienvenueespece;
	GtkWidget *comboboxmodepayementE;
	GtkWidget *comboboxCCDE;
	GtkWidget *iddevisMPE;
	GtkWidget *iddevispayementE;
	GtkWidget *entrymontantpayementFE;
	char code[30];
	char id[30];
	char mode[30];
	GtkWidget *WContinuer_CDE;

	comboboxmodepayementE=lookup_widget(objet,"comboboxmodepayementE");
	strcpy(mode,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodepayementE)));

	if((strcmp(mode,"Espece")==0))
	{
		mode_payement_E=lookup_widget(objet,"mode_payement_E");
		gtk_widget_destroy(mode_payement_E);

		
		bienvenueespece=lookup_widget(objet,"bienvenueespece");
		bienvenueespece=create_bienvenueespece();
		gtk_widget_show(bienvenueespece);	
	}
	else
	{

	mode_payement_E=lookup_widget(objet,"mode_payement_E");
	

	char A[50];
	char id1[30];
	FILE *f=NULL;
	Dexcursion E;
	f=fopen("devishebergement.txt","a+");
	PayementE=lookup_widget(objet,"PayementE");
	PayementE=create_PayementE();
	gtk_widget_show(PayementE);
	iddevisMPE=lookup_widget(mode_payement_E,"iddevisMPE");
	strcpy(id1,gtk_entry_get_text(GTK_ENTRY(iddevisMPE)));
	gtk_widget_destroy(mode_payement_E);

	if(f!=NULL)
	{

		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",E.id_devis,E.identifiant,E.id_reservation,E.id_excursion,E.depart,E.arrivee,E.d.jour,E.d.mois,E.d.annee,E.personne,E.montant)!=EOF)			
			if(strcmp(E.id_devis,id1)==0)
			{
				entrymontantpayementFE=lookup_widget(PayementE,"entrymontantpayementFE");
				gtk_entry_set_text(GTK_ENTRY(entrymontantpayementFE),E.montant);


			}
	fclose(f);
	}

	iddevispayementE=lookup_widget(PayementE,"iddevispayementE");
	gtk_entry_set_text(GTK_ENTRY(iddevispayementE),id1); 
	}
}


void
on_ValidermodepayementV_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *mode_payement_V;
	GtkWidget *input1 ;
	GtkWidget *PayementV;
	GtkWidget *bienvenueespece;
	GtkWidget *comboboxmodepayementV;
	GtkWidget *comboboxCCDV;
	GtkWidget *iddevisMPV;
	GtkWidget *iddevispayementV;
	GtkWidget *entrymontantpayementFV;
	char code[30];
	char id[30];
	char mode[30];
	GtkWidget *WContinuer_CDV;

	comboboxmodepayementV=lookup_widget(objet,"comboboxmodepayementV");
	strcpy(mode,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodepayementV)));

	if((strcmp(mode,"Espece")==0))
	{
		mode_payement_V=lookup_widget(objet,"mode_payement_V");
		gtk_widget_destroy(mode_payement_V);

		
		bienvenueespece=lookup_widget(objet,"bienvenueespece");
		bienvenueespece=create_bienvenueespece();
		gtk_widget_show(bienvenueespece);	
	}
	else
	{

	mode_payement_V=lookup_widget(objet,"mode_payement_V");
	

	char A[50];
	char id1[30];
	FILE *f=NULL;
	Dvol V;
	f=fopen("devishebergement.txt","a+");
	PayementV=lookup_widget(objet,"PayementV");
	PayementV=create_PayementV();
	gtk_widget_show(PayementV);
	iddevisMPV=lookup_widget(mode_payement_V,"iddevisMPV");
	strcpy(id1,gtk_entry_get_text(GTK_ENTRY(iddevisMPV)));
	gtk_widget_destroy(mode_payement_V);

	if(f!=NULL)
	{

		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",V.identifiant,V.id_reservation,V.id_vol,V.depart.jour,V.depart.mois,V.depart.annee,V.arrivee.jour,V.arrivee.mois,V.arrivee.annee,V.vdepart,V.vdestination,V.personne,V.montant)!=EOF)			
			if(strcmp(V.id_devis,id1)==0)
			{
				entrymontantpayementFV=lookup_widget(PayementV,"entrymontantpayementFV");
				gtk_entry_set_text(GTK_ENTRY(entrymontantpayementFV),V.montant);


			}
	fclose(f);
	}

	iddevispayementV=lookup_widget(PayementV,"iddevispayementV");
	gtk_entry_set_text(GTK_ENTRY(iddevispayementV),id1); 
	}
}


void
on_R_payerFV_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *PayementV;
	GtkWidget *mode_payement;
	PayementV=lookup_widget(objet,"PayementV");
	gtk_widget_destroy(PayementV);
	mode_payement=lookup_widget(objet,"mode_payement");
	mode_payement=create_mode_payement();
	gtk_widget_show(mode_payement);
	
}


void
on_PayerFV_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *PayementV;
	GtkWidget *Facpayee;
	GtkWidget *WContinuer_CDV;
	GtkWidget *iddevispayementV;
	GtkWidget *input1;
	GtkWidget *input2;
	Dvol V;
	char idC[30];
	char idP[30];
	char identifiant[30];
	FILE *f;
	FILE *f1;
	FILE *f2;
	f1=fopen("devisvol.txt","a+");
	f2=fopen("facturevol.txt","a+");
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 
	PayementV=lookup_widget(objet,"PayementV");

	input1=lookup_widget(PayementV,"iddevispayementV");
	strcpy(idP,gtk_entry_get_text(GTK_ENTRY(input1)));

	gtk_widget_destroy(PayementV);

	if(f1!=NULL)
	{
		while(fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",V.id_devis,V.identifiant,V.id_reservation,V.id_vol,V.depart.jour,V.depart.mois,V.depart.annee,V.arrivee.jour,V.arrivee.mois,V.arrivee.annee,V.vdepart,V.vdestination,V.personne,V.montant)!=EOF)
		{
			if(strcmp(idP,V.id_devis)==0)
			{

				fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",V.id_devis,V.identifiant,V.id_reservation,V.id_vol,V.depart.jour,V.depart.mois,V.depart.annee,V.arrivee.jour,V.arrivee.mois,V.arrivee.annee,V.vdepart,V.vdestination,V.personne,V.montant);
			}
		}
	}


	fclose(f);
	fclose(f1);
	fclose(f2);
	supprimer_devis(idP,2);

	Facpayee=lookup_widget(objet,"Facpayee");
	Facpayee=create_Facpayee();
	gtk_widget_show(Facpayee);
}


void
on_OKcodeespece_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeviewADH;
	GtkWidget *treeviewADE;
	GtkWidget *treeviewADV;
	GtkWidget *treeviewAFH;
	GtkWidget *treeviewAFE;
	GtkWidget *treeviewAFV;
	GtkWidget *treeviewCDH;
	GtkWidget *treeviewCDE;
	GtkWidget *treeviewCDV;
	GtkWidget *treeviewCFH;
	GtkWidget *treeviewCFE;
	GtkWidget *treeviewCFV;
	GtkWidget *menufacdevis;
	GtkWidget *bienvenueespece;
	char identifiant[30];
	char idC[30]="\0";
	Dhebergement H;
	FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 

	
	bienvenueespece=lookup_widget(objet,"bienvenueespece");
	gtk_widget_destroy(bienvenueespece);
	menufacdevis=lookup_widget(objet,"menufacdevis");
	menufacdevis=create_menufacdevis();
	gtk_widget_show(menufacdevis);
	treeviewADE=lookup_widget(menufacdevis,"treeviewADE");
	afficher_ADE(treeviewADE);

	treeviewADH=lookup_widget(menufacdevis,"treeviewADH");
	afficher_ADH(treeviewADH);

	treeviewAFH=lookup_widget(menufacdevis,"treeviewAFH");
	afficher_AFH(treeviewAFH);	

	treeviewAFE=lookup_widget(menufacdevis,"treeviewAFE");
	afficher_AFE(treeviewAFE);

	treeviewADV=lookup_widget(menufacdevis,"treeviewADV");
	afficher_ADV(treeviewADV);

	treeviewAFV=lookup_widget(menufacdevis,"treeviewAFV");
	afficher_AFV(treeviewAFV);

	treeviewCDE=lookup_widget(menufacdevis,"treeviewCDE");
	afficher_CDE(treeviewCDE,idC);

	treeviewCFE=lookup_widget(menufacdevis,"treeviewCFE");
	afficher_CFE(treeviewCFE,idC);

	treeviewCDH=lookup_widget(menufacdevis,"treeviewCDH");
	afficher_CDH(treeviewCDH,idC);

	treeviewCFH=lookup_widget(menufacdevis,"treeviewCFH");
	afficher_CFH(treeviewCFH,idC);

	treeviewCDV=lookup_widget(menufacdevis,"treeviewCDV");
	afficher_CDV(treeviewCDV,idC);

	treeviewCFV=lookup_widget(menufacdevis,"treeviewCFV");
	afficher_CFV(treeviewCFV,idC);
}


void
on_PayerFE_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *PayementE;
	GtkWidget *Facpayee;
	GtkWidget *WContinuer_CDE;
	GtkWidget *iddevispayementE;
	GtkWidget *input1;
	GtkWidget *input2;
	Dexcursion E;
	char idC[30];
	char idP[30];
	char identifiant[30];
	FILE *f;
	FILE *f1;
	FILE *f2;
	f1=fopen("devisexcursion.txt","a+");
	f2=fopen("factureexcursion.txt","a+");
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	strcpy(idC,identifiant); 
	PayementE=lookup_widget(objet,"PayementE");

	input1=lookup_widget(PayementE,"iddevispayementE");
	strcpy(idP,gtk_entry_get_text(GTK_ENTRY(input1)));

	gtk_widget_destroy(PayementE);

	if(f1!=NULL)
	{
		while(fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s \n",E.id_devis,E.identifiant,E.id_reservation,E.id_excursion,E.depart,E.arrivee,E.d.jour,E.d.mois,E.d.annee,E.personne,E.montant)!=EOF)
		{
			if(strcmp(idP,E.id_devis)==0)
			{

				fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s \n",E.id_devis,E.identifiant,E.id_reservation,E.id_excursion,E.depart,E.arrivee,E.d.jour,E.d.mois,E.d.annee,E.personne,E.montant);
			}
		}
	}


	fclose(f);
	fclose(f1);
	fclose(f2);
	supprimer_devis(idP,1);

	Facpayee=lookup_widget(objet,"Facpayee");
	Facpayee=create_Facpayee();
	gtk_widget_show(Facpayee);
}


void
on_R_payerFE_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *PayementE;
	GtkWidget *mode_payement;
	PayementE=lookup_widget(objet,"PayementE");
	gtk_widget_destroy(PayementE);
	mode_payement=lookup_widget(objet,"mode_payement");
	mode_payement=create_mode_payement();
	gtk_widget_show(mode_payement);
}

