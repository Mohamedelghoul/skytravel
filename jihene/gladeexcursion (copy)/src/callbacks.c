#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "excursion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>




void
on_ajouterexcursione_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouterexcursione, *gestionexcursionce;
		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");

		gtk_widget_destroy(gestionexcursionce);
		ajouterexcursione=create_ajouterexcursione();
		gtk_widget_show(ajouterexcursione);


}


void
on_modifierexcursione_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestionexcursionce, *ok;
		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");
		ok=lookup_widget(objet,"excursionamodifierw");
		

		gtk_widget_destroy(gestionexcursionce);
		ok=create_excursionamodifierw();
		gtk_widget_show(ok); 

		char tab[50][50];int n,i;
		GtkWidget *excursionamodifier;

		excursionamodifier=lookup_widget(ok,"excursionamodifier");
		n=remplir_combo_id(tab);
		for (i=0;i<n;i++)

		{gtk_combo_box_append_text (GTK_COMBO_BOX(excursionamodifier),_(tab[i]));
}
}

void
on_supprimerexcursione_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerexcursione, *gestionexcursionce;
		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");

		gtk_widget_destroy(gestionexcursionce);
		supprimerexcursione=create_supprimerexcursione();
		gtk_widget_show(supprimerexcursione);

char tab[50][50];int n,i;
GtkWidget *idsupprimerexcursion;

		idsupprimerexcursion=lookup_widget(supprimerexcursione,"idsupprimerexcursion");
		n=remplir_combo_id(tab);
		for (i=0;i<n;i++)
		{gtk_combo_box_append_text (GTK_COMBO_BOX(idsupprimerexcursion),_(tab[i]));


}

}


void
on_boutonrechercherexcursione_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{



}


void
on_reserverexcursione_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *reserverexcursione, *gestionexcursionce;
		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");

		gtk_widget_destroy(gestionexcursionce);
		reserverexcursione=create_reserverexcursione();
		gtk_widget_show(reserverexcursione);
char tab[50][50];int n,i;
GtkWidget *excursionareservere;

		excursionareservere=lookup_widget(reserverexcursione,"excursionareservere");
		n=remplir_combo_id(tab);
		for (i=0;i<n;i++)
		{gtk_combo_box_append_text (GTK_COMBO_BOX(excursionareservere),_(tab[i]));
		
}
}


void
on_annulergestionexcursione_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *espaceexcursion, *gestionexcursionce;
		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");

		gtk_widget_destroy(gestionexcursionce);
		espaceexcursion=create_espaceexcursion();
		gtk_widget_show(espaceexcursion);


}


void
on_confirmersuppressione_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *supprimerexcursione,*idsupprimerexcursion,*confirmersupprimerexcursione;
		char id_ex[30];
		
		supprimerexcursione=lookup_widget(objet,"supprimerexcursione");
		idsupprimerexcursion=lookup_widget(objet,"idsupprimerexcursion");
		strcpy(id_ex,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idsupprimerexcursion)));
		supprimer_excursion(id_ex);
		gtk_widget_destroy(supprimerexcursione);
		confirmersupprimerexcursione=create_confirmersupprimerexcursione();
		gtk_widget_show(confirmersupprimerexcursione);


}


void
on_annulersuppressione_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerexcursione, *gestionexcursionce;
		supprimerexcursione=lookup_widget(objet,"supprimerexcursione");

		gtk_widget_destroy(supprimerexcursione);
		


		GtkWidget *treeviewexcursione;


		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");
		gestionexcursionce=create_gestionexcursionce();

		gtk_widget_show(gestionexcursionce);

		treeviewexcursione=lookup_widget(gestionexcursionce,"treeviewexcursione");
		afficher_excursion(treeviewexcursione);
}

void
on_confirmerajoutexcursione_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
char g[20],h[20],j[20];
int a,b,c;
	Date d;int k;
		Excursion e,e1;
		GtkWidget *departexcursione,*arriveeexcursione,*dureeexcursione,*transportexcursione,*repasexcursione,*jour,*mois,*annee,*nb,*id1,*P,*H;



		departexcursione=lookup_widget(objet,"departexcursione");
		strcpy(e.depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(departexcursione)));
		arriveeexcursione=lookup_widget(objet,"arriveeexcursione");
		strcpy(e.arrivee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(arriveeexcursione)));
		dureeexcursione=lookup_widget(objet,"dureeexcursione");
		strcpy(e.duree,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dureeexcursione)));
		transportexcursione=lookup_widget(objet,"transportexcursione");
		strcpy(e.transport,gtk_combo_box_get_active_text(GTK_COMBO_BOX(transportexcursione)));
		repasexcursione=lookup_widget(objet,"repasexcursione");
		strcpy(e.nourriture,gtk_combo_box_get_active_text(GTK_COMBO_BOX(repasexcursione)));
		jour=lookup_widget(objet, "jourexcursione");
		mois=lookup_widget(objet, "moisexcursione");
		annee=lookup_widget(objet, "anneeexcursione");
		nb=lookup_widget(objet, "nombreplacestotalexcursione");
		 e.nbplacestotal=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (nb));
		e.nbplacesrestantes=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (nb));
		 a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
			sprintf(g,"%d",a);
			strcpy(e.d.jour,g);
			
		 b=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
			sprintf(h,"%d",b);
			strcpy(e.d.mois,h);
			
		 c=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
			sprintf(j,"%d",c);
			strcpy(e.d.annee,j);
		char prix[20];
			
		id1=lookup_widget(objet, "idexcursiongeneree");
		strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(id1)));
		H=lookup_widget(objet, "hebergementexcursione");
		strcpy(e.hebergement,gtk_entry_get_text(GTK_ENTRY(H)));
		P=lookup_widget(objet, "prixexcursione");
		strcpy(prix,gtk_entry_get_text(GTK_ENTRY(P)));
		e.prix=atoi(prix);
		//strcpy(e1.id,"E500");strcpy(e1.depart,"zimbaboue");strcpy(e1.arrivee,"lambadouza");strcpy(e1.duree,"journée");
		//strcpy(e1.transport,"fusée");strcpy(e1.nourriture,"djej");strcpy(e1.d.jour,"12");strcpy(e1.d.mois,"12");strcpy(e1.d.annee,"2012");
		//e1.prix=200;e1.nbplacestotal=50;e1.nbplacesrestantes=20;strcpy(e1.hebergement,"houtil");
		//ajouter_excursion(e1);
		
//strcpy(e.d.jour,"12");strcpy(e.d.mois,"12");strcpy(e.d.annee,"2012");		
ajouter_excursion(e);
		
		

}


void
on_annulerajoutexcursione_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *ajouterexcursione, *gestionexcursionce;
		ajouterexcursione=lookup_widget(objet,"ajouterexcursione");

		gtk_widget_destroy(ajouterexcursione);
		
	

		GtkWidget *treeviewexcursione;


		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");
		gestionexcursionce=create_gestionexcursionce();

		gtk_widget_show(gestionexcursionce);

		treeviewexcursione=lookup_widget(gestionexcursionce,"treeviewexcursione");
		afficher_excursion(treeviewexcursione);


}


void
on_genereridexcursione_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
	
	GtkWidget *idexcursiongeneree;
	char code[20];
	int A;
	
	do
	{
		A=code_excursion();
		sprintf(code,"E%d",A);
	}
	while(verifier_code(code)==1);
	idexcursiongeneree=lookup_widget(objet,"idexcursiongeneree");
	gtk_entry_set_text(GTK_ENTRY(idexcursiongeneree),code);
	
	

}


void
on_villesexcursione_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *departexcursione, *arriveeexcursione, *paysexcursione;//,*idexcursiongeneree;
char pays[50];
 int n,i,p;
 char tab[50][20];
char code[50];

	paysexcursione=lookup_widget(objet,"paysexcursione");
	strcpy(pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(paysexcursione)));
	p=nombre_ville(pays);
	n=choix_villes(p,tab);
	departexcursione=lookup_widget(objet,"departexcursione");
	arriveeexcursione=lookup_widget(objet,"arriveeexcursione");
	for (i=0; i<n;i++)
		{gtk_combo_box_append_text (GTK_COMBO_BOX (departexcursione),_(tab[i]));
		gtk_combo_box_append_text (GTK_COMBO_BOX (arriveeexcursione),_(tab[i]));}
	

		
		//idexcursiongeneree=lookup_widget(objet,"idexcursiongeneree");
		//sprintf(code,"E%d",p);
		//gtk_entry_set_text(GTK_ENTRY(idexcursiongeneree),tab[i]);
		

}


void
on_annulerexcursionm_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifierexcursione, *gestionexcursionce;
		modifierexcursione=lookup_widget(objet,"modifierexcursione");

		gtk_widget_destroy(modifierexcursione);
		
	

		GtkWidget *treeviewexcursione;


		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");
		gestionexcursionce=create_gestionexcursionce();

		gtk_widget_show(gestionexcursionce);

		treeviewexcursione=lookup_widget(gestionexcursionce,"treeviewexcursione");
		afficher_excursion(treeviewexcursione);

}


void
on_confirmerexcursionm_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{


char g[20],h[20],j[20];
int a,b,c;
	Date d;
		Excursion e,e1;
		GtkWidget *departexcursionm,*arriveeexcursionm,*dureeexcursionm,*transportexcursionm,*repasexcursionm,*jour,*mois,*annee,*nb,*id1,*P,*H;

		id1=lookup_widget(objet, "idexcursionm");
		strcpy(e.id,gtk_label_get_text(GTK_LABEL(id1)));
                
		supprimer_excursion(e.id);

		departexcursionm=lookup_widget(objet,"departexcursionm");
		strcpy(e.depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(departexcursionm)));
		arriveeexcursionm=lookup_widget(objet,"arriveeexcursionm");
		strcpy(e.arrivee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(arriveeexcursionm)));
		dureeexcursionm=lookup_widget(objet,"dureeexcursionm");
		strcpy(e.duree,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dureeexcursionm)));
		transportexcursionm=lookup_widget(objet,"transportexcursionm");
		strcpy(e.transport,gtk_combo_box_get_active_text(GTK_COMBO_BOX(transportexcursionm)));
		repasexcursionm=lookup_widget(objet,"repasexcursionm");
		strcpy(e.nourriture,gtk_combo_box_get_active_text(GTK_COMBO_BOX(repasexcursionm)));
		jour=lookup_widget(objet, "jourexcursionm");
		mois=lookup_widget(objet, "moisexcursionm");
		annee=lookup_widget(objet, "anneeexcursionm");
		nb=lookup_widget(objet, "nbplacesexcursionm");
		 e.nbplacestotal=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (nb));
		e.nbplacesrestantes=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (nb));
		 a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
			sprintf(g,"%d",a);
			strcpy(e.d.jour,g);
			
		 b=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
			sprintf(h,"%d",b);
			strcpy(e.d.mois,h);
			
		 c=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
			sprintf(j,"%d",c);
			strcpy(e.d.annee,j);
			
		
		H=lookup_widget(objet, "hebergementexcursionm");
		strcpy(e.hebergement,gtk_entry_get_text(GTK_ENTRY(H)));
		P=lookup_widget(objet, "prixexcursionm");
		char prix[20];
		strcpy(prix,gtk_entry_get_text(GTK_ENTRY(P)));
		e.prix=atoi(prix);
		ajouter_excursion(e);
		GtkWidget *modifierexcursione;
		modifierexcursione=lookup_widget(objet,"modifierexcursione");

		gtk_widget_destroy(modifierexcursione);
		GtkWidget *confirmermodifierexcursion;
		confirmermodifierexcursion=lookup_widget(objet,"confirmermodifierexcursion");
		confirmermodifierexcursion=create_confirmermodifierexcursion();
		gtk_widget_show(confirmermodifierexcursion);

		
		

}


void
on_villesexcursionm_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *departexcursionm, *arriveeexcursionm, *paysexcursionm;//,*idexcursiongeneree;
char pays[50];
 int n,i,p;
 char tab[50][20];
char code[50];

	paysexcursionm=lookup_widget(objet,"paysexcursionm");
	strcpy(pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(paysexcursionm)));
	p=nombre_ville(pays);
	n=choix_villes(p,tab);
	departexcursionm=lookup_widget(objet,"departexcursionm");
	arriveeexcursionm=lookup_widget(objet,"arriveeexcursionm");
	for (i=0; i<n;i++)
		{gtk_combo_box_append_text (GTK_COMBO_BOX (departexcursionm),_(tab[i]));
		gtk_combo_box_append_text (GTK_COMBO_BOX (arriveeexcursionm),_(tab[i]));}

}


void
on_confirmerreservationexcursione_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{		
	char id_client[30];int n,nbr;Excursionr er;
	GtkWidget *jiji,*bibi,*nini,*spinbutton,*combo;
	char k1[20] ;char k2[20] ;char k3[20] ;char k4[20] ;char k5[20] ;char k6[20] ;char k7[20] ;char k8[20] ;char k9[20] ;char k10[20] ;char k11[20] ;char k12[20] ;
char id_ex[20],code[20];int l,m,p,A;
Date1 d;
	jiji=lookup_widget(objet,"reserverexcursione");
	bibi=lookup_widget(objet,"idclientreservationexcursione");
	combo=lookup_widget(objet,"excursionareservere");
	spinbutton=lookup_widget(objet,"nombreplacesexcursione");
	nini=lookup_widget(objet,"msgreservationexcursione");
	strcpy(id_client,gtk_entry_get_text(GTK_ENTRY(bibi)));
	n=verifier_code1(id_client);

	nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton));
	strcpy(id_ex,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));



	
	if (n==0) 
	gtk_label_set_text(GTK_LABEL(nini),"client non inscrit");
	else
	{
	 cherExcursion(id_ex,k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12);
	 l=atoi(k10);
	 m=atoi(k11);
	p=atoi(k12);
	if (m<nbr)
	gtk_label_set_text(GTK_LABEL(nini),"Nombre de places non disponible");
	else
	{
	strcpy(er.identifiant,id_client);
	strcpy(er.id_excursion,id_ex);
		A=code_excursionr();
		sprintf(code,"RE%d",A);
	strcpy(er.id_reservation,code);
	strcpy(er.depart,k1);
	strcpy(er.arrivee,k2);
	strcpy(er.d.jour,k3);
	strcpy(er.d.mois,k4);
	strcpy(er.d.annee,k5);
	er.personne=nbr;
	er.montant=(p*nbr);
	gtk_label_set_text(GTK_LABEL(nini),"Reservation reussite");
	ajouter_excursionr(er);
	}
	

	

	
	


	
	}

		
	
		
		
}


void
on_annulerreservationexcursione_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *reserverexcursione, *gestionexcursionce;
		reserverexcursione=lookup_widget(objet,"reserverexcursione");
		gtk_widget_destroy(reserverexcursione);
		GtkWidget *treeviewexcursione;
		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");
		gestionexcursionce=create_gestionexcursionce();
		gtk_widget_show(gestionexcursionce);
		treeviewexcursione=lookup_widget(gestionexcursionce,"treeviewexcursione");
		afficher_excursion(treeviewexcursione);
}


void
on_annulerreservationexcursionc_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *reserverexcursionc, *gestionexcursionce;
		reserverexcursionc=lookup_widget(objet,"reserverexcursionc");
		gtk_widget_destroy(reserverexcursionc);
		GtkWidget *treeviewexcursione;
		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");
		gestionexcursionce=create_gestionexcursionce();
		gtk_widget_show(gestionexcursionce);
		treeviewexcursione=lookup_widget(gestionexcursionce,"treeviewexcursione");
		afficher_excursion(treeviewexcursione);
}


void
on_confirmerreservationexcursionc_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{char identifiant[20];
FILE *f;
	f=fopen("actual_user.txt","r");
	fscanf(f,"%s",identifiant);
	fclose(f);

char id_client[30];int n,nbr;Excursionr er;
	GtkWidget *jiji,*bibi,*nini,*spinbutton,*combo;
	char k1[20] ;char k2[20] ;char k3[20] ;char k4[20] ;char k5[20] ;char k6[20] ;char k7[20] ;char k8[20] ;char k9[20] ;char k10[20] ;char k11[20] ;char k12[20] ;
char id_ex[20],code[20];int l,m,p,A;
Date1 d;
	jiji=lookup_widget(objet,"reserverexcursionc");
	bibi=lookup_widget(objet,"idclientexcursionc");
	combo=lookup_widget(objet,"excursionareserverc");
	spinbutton=lookup_widget(objet,"nombreplacesrexcursionc");
	nini=lookup_widget(objet,"msgreservationexcursionc");
	strcpy(id_client,identifiant);

	nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton));
	strcpy(id_ex,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
	gtk_label_set_text(GTK_LABEL(bibi),id_client);
	
	cherExcursion(id_ex,k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12);
	 l=atoi(k10);
	 m=atoi(k11);
	p=atoi(k12);
	if (m<nbr)
	gtk_label_set_text(GTK_LABEL(nini),"Nombre de places non disponible");
	else
	{
	strcpy(er.identifiant,id_client);
	strcpy(er.id_excursion,id_ex);
		A=code_excursionr();
		sprintf(code,"RE%d",A);
	strcpy(er.id_reservation,code);
	strcpy(er.depart,k1);
	strcpy(er.arrivee,k2);
	strcpy(er.d.jour,k3);
	strcpy(er.d.mois,k4);
	strcpy(er.d.annee,k5);
	er.personne=nbr;
	er.montant=(p*nbr);
	gtk_label_set_text(GTK_LABEL(nini),"Reservation reussite");
	ajouter_excursionr(er);
	
	
	}

}


void
on_rechercherexcursionc_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_reserverexurcionc_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *reserverexcursionc, *afficherexcursionc;
		afficherexcursionc=lookup_widget(objet,"afficherexcursionc");

		gtk_widget_destroy(afficherexcursionc);
		reserverexcursionc=create_reserverexcursionc();
		gtk_widget_show(reserverexcursionc);
char tab[50][50];int n,i;
GtkWidget *excursionareserverc;

		excursionareserverc=lookup_widget(reserverexcursionc,"excursionareserverc");
		n=remplir_combo_id(tab);
		for (i=0;i<n;i++)
		{gtk_combo_box_append_text (GTK_COMBO_BOX(excursionareserverc),_(tab[i]));}
		


}


void
on_retourexcurionc_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *espaceexcursion, *afficherexcursionc;
		afficherexcursionc=lookup_widget(objet,"afficherexcursionc");

		gtk_widget_destroy(afficherexcursionc);
		espaceexcursion=create_espaceexcursion();
		gtk_widget_show(espaceexcursion);


}


void
on_rechercherexcursioncnc_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_retourexcursioncnc_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *espaceexcursion, *afficherexcursionclientnonconnecte;
		afficherexcursionclientnonconnecte=lookup_widget(objet,"afficherexcursionclientnonconnecte");

		gtk_widget_destroy(afficherexcursionclientnonconnecte);
		espaceexcursion=create_espaceexcursion();
		gtk_widget_show(espaceexcursion);


}


void
on_oksuppressionexcusrione_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *gestionexcursionce,*confirmersupprimerexcursione;
	confirmersupprimerexcursione=lookup_widget(objet,"confirmersupprimerexcursione");
		gtk_widget_destroy(confirmersupprimerexcursione);
		GtkWidget *treeviewexcursione;
		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");
		gestionexcursionce=create_gestionexcursionce();
		gtk_widget_show(gestionexcursionce);
		treeviewexcursione=lookup_widget(gestionexcursionce,"treeviewexcursione");
		afficher_excursion(treeviewexcursione);	
		

}


void
on_retourajouterexcursion_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *confirmerajouterexcursion, *gestionexcursionce;
		confirmerajouterexcursion=lookup_widget(objet,"confirmerajouterexcursion");
		gtk_widget_destroy(confirmerajouterexcursion);
		GtkWidget *treeviewexcursione;
		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");
		gestionexcursionce=create_gestionexcursionce();
		gtk_widget_show(gestionexcursionce);
		treeviewexcursione=lookup_widget(gestionexcursionce,"treeviewexcursione");
		afficher_excursion(treeviewexcursione);
}


void
on_okconfirmermodifier_clicked         (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *ok, *gestionexcursionce;
		ok=lookup_widget(objet,"confirmermodifierexcursion");
		gtk_widget_destroy(ok);
		GtkWidget *ok2;
		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");
		gestionexcursionce=create_gestionexcursionce();
		gtk_widget_show(gestionexcursionce);
		ok2=lookup_widget(gestionexcursionce,"treeviewexcursione");
		afficher_excursion(ok2);


}


void
on_espaceexcurione_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *espaceexcursion;
GtkWidget *gestionexcursionce;
GtkWidget *treeviewexcursione;

espaceexcursion=lookup_widget(objet,"espaceexcursion");

gtk_widget_destroy(espaceexcursion);
gestionexcursionce=lookup_widget(objet,"gestionexcursionce");
gestionexcursionce=create_gestionexcursionce();

gtk_widget_show(gestionexcursionce);

treeviewexcursione=lookup_widget(gestionexcursionce,"treeviewexcursione");
afficher_excursion(treeviewexcursione);


}


void
on_espaceexcursionc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espaceexcursion;
GtkWidget *afficherexcursionc;
GtkWidget *affichageexcurionc;

espaceexcursion=lookup_widget(objet,"espaceexcursion");

gtk_widget_destroy(espaceexcursion);
afficherexcursionc=lookup_widget(objet,"afficherexcursionc");
afficherexcursionc=create_afficherexcursionc();

gtk_widget_show(afficherexcursionc);

affichageexcurionc=lookup_widget(afficherexcursionc,"affichageexcurionc");
afficher_excursion(affichageexcurionc);
}


void
on_espaceexcursioncnc_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espaceexcursion;
GtkWidget *afficherexcursionclientnonconnecte;
GtkWidget *affichageexcursioncnc;

espaceexcursion=lookup_widget(objet,"espaceexcursion");

gtk_widget_destroy(espaceexcursion);
afficherexcursionclientnonconnecte=lookup_widget(objet,"afficherexcursionclientnonconnecte");
afficherexcursionclientnonconnecte=create_afficherexcursionclientnonconnecte();

gtk_widget_show(afficherexcursionclientnonconnecte);

affichageexcursioncnc=lookup_widget(afficherexcursionclientnonconnecte,"affichageexcursioncnc");
afficher_excursion(affichageexcursioncnc);
}


void
on_confirmerexcursionamodifier_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ok,*modifierexcursione,*id,*w;
		char id_ex[30];
		
		ok=lookup_widget(objet,"excursionamodifier");
		w=lookup_widget(objet,"excursionamodifierw");
		modifierexcursione=lookup_widget(objet,"modifierexcursione");
		strcpy(id_ex,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ok)));
		
		gtk_widget_destroy(w);
		modifierexcursione=create_modifierexcursione();
		
		gtk_widget_show(modifierexcursione);
		id=lookup_widget(modifierexcursione,"idexcursionm");
		gtk_label_set_text(GTK_LABEL(id),id_ex);
		

}


void
on_annulerexcursionamodifier_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ok, *gestionexcursionce;
		ok=lookup_widget(objet,"excursionamodifierw");
		gtk_widget_destroy(ok);
		GtkWidget *treeviewexcursione;
		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");
		gestionexcursionce=create_gestionexcursionce();
		gtk_widget_show(gestionexcursionce);
		treeviewexcursione=lookup_widget(gestionexcursionce,"treeviewexcursione");
		afficher_excursion(treeviewexcursione);
}

