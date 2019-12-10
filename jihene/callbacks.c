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
GtkWidget *modifierexcursione, *gestionexcursionce;
		gestionexcursionce=lookup_widget(objet,"gestionexcursionce");

		gtk_widget_destroy(gestionexcursionce);
		modifierexcursione=create_modifierexcursione();
		gtk_widget_show(modifierexcursione);
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
on_confirmersuppressione_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

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
on_confirmerajoutexcursione_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{



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
on_villesexcursione_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

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
on_confirmerexcursionm_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_villesexcursionm_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_confirmerreservationexcursione_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

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
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_rechercherexcursionc_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_reserverexurcionc_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

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
on_oksuppressionexcusrione_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

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
on_okconfirmermodifier_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

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

