#include <gtk/gtk.h> 
typedef struct Date Date;
struct Date{
int jour;
int mois;
int annee;
};

typedef struct
{
char identifiant[30];
char id_reservation[30];
char id_vol[30];
Date depart;
Date arrivee;
char vdepart[30];
char vdestination[30];
int personne;
int montant;
}Volr;




int ajouter_reservationvol(Volr r);
void afficher_reservationvol();
void supprimer_volres(char identif[]);
void modifier_reservation();
int chercher_reservoldisp(Volr r);
int remplir_combovolres(Volr tab[10]);
int tableau_resvol_disponible(char tab[50][10]);
