#ifndef RECLAMATION_H_
#define RECLAMATION_H_


#include <gtk/gtk.h>


typedef struct date
{
int jour;
int mois;
int annee;
}date;

typedef struct reclamation
{
int id_rec;
char id_client[50];
char type[20];
date date;
char etat[20];
char text[1000];
char reponse[1000];
}reclamation;

void ajouter_reclamation(reclamation r);
void supprimer_reclamation(int reclamation);
int calculer_reclamation();
char get_text_file(char txt[]);
void set_text_file(char fichiertxt[], char text[]);
int remplir_combo_reclamation(char tab[50][50]);
int remplir_combo_type_reclamation(char tab[50][50]);
void afficher_reclamation_client(GtkWidget *liste);
void afficher_reclamation_admin(GtkWidget *liste);

#endif
