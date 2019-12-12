#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include"hebergement.h"
#include "support.h"


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

GtkWidget *window102;
GtkWidget *window100;



window102=lookup_widget(objet,"window102");
window100=create_window100();
gtk_widget_destroy(window102);
gtk_widget_show(window100);

}


void
on_button110_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *window102;
GtkWidget *window100;



window102=lookup_widget(objet,"window102");
window100=create_window100();
gtk_widget_destroy(window102);
gtk_widget_show(window100);


}


void
on_button112_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window103;
GtkWidget *window100;



window103=lookup_widget(objet,"window103");
window100=create_window100();
gtk_widget_destroy(window103);
gtk_widget_show(window100);


}


void
on_button113_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window103;
GtkWidget *window100;



window103=lookup_widget(objet,"window103");
window100=create_window100();
gtk_widget_destroy(window103);
gtk_widget_show(window100);

}


void
on_button116_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{


GtkWidget *window104;
GtkWidget *window100;



window104=lookup_widget(objet,"window104");
window100=create_window100();
gtk_widget_destroy(window104);
gtk_widget_show(window100);


}


void
on_button119_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *window105;
GtkWidget *window100;



window105=lookup_widget(objet,"window105");
window100=create_window100();
gtk_widget_destroy(window105);
gtk_widget_show(window100);

}


void
on_button118_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window105;
GtkWidget *window100;



window105=lookup_widget(objet,"window105");
window100=create_window100();
gtk_widget_destroy(window105);
gtk_widget_show(window100);




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
GtkWidget *window100;
GtkWidget *window106;



window106=lookup_widget(objet,"window106");
window100=create_window100();
gtk_widget_destroy(window106);
gtk_widget_show(window100);

}


void
on_button124_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window107;
GtkWidget *window100;



window107=lookup_widget(objet,"window107");
window100=create_window100();
gtk_widget_destroy(window107);
gtk_widget_show(window100);

}


void
on_button127_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window108;
GtkWidget *window100;



window108=lookup_widget(objet,"window108");
window100=create_window100();
gtk_widget_destroy(window108);
gtk_widget_show(window100);


}

