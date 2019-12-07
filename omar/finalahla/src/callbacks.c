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

window101=lookup_widget(objet,"window101");
window104=create_window104();
gtk_widget_destroy(window101);
gtk_widget_show(window104);


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


GtkWidget *window101;
GtkWidget *window105;


window101=lookup_widget(objet,"window101");
window105=create_window105();
gtk_widget_destroy(window101);
gtk_widget_show(window105);



}


void
on_button117_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}

