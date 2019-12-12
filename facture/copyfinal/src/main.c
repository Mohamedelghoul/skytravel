/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *menufacdevis;
  GtkWidget *Window_codeCDH;
  GtkWidget *window_codeCDE;
  GtkWidget *window_codeCDV;
  GtkWidget *WAnnuler_CDH;
  GtkWidget *WAnnuler_CDE;
  GtkWidget *WAnnuler_CDV;
  GtkWidget *WContinuer_CDH;
  GtkWidget *WContinuer_CDE;
  GtkWidget *WContinuer_CDV;
  GtkWidget *WModifier_CDH;
  GtkWidget *WModifier_CDE;
  GtkWidget *WModifier_CDV;
  GtkWidget *Reservation_annulerH;
  GtkWidget *Reduction_validerH;
  GtkWidget *Reservation_annulerE;
  GtkWidget *Reservation_annulerV;
  GtkWidget *Reduction_validerE;
  GtkWidget *Reduction_validerV;
  GtkWidget *Window;
  GtkWidget *Facpayee;
  GtkWidget *bienvenueespece;
  GtkWidget *mode_payement;
  GtkWidget *Payement;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */

  Window = create_Window ();
  gtk_widget_show (Window);
 
  gtk_main ();
  return 0;
}

