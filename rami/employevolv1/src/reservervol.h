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
}Volr;




int ajouter_reservation(Volr r);
void afficher_reservation();
void supprimer_reservation();
void modifier_reservation();
int chercher_reservoldisp(Volr r);
int remplir_combovolres(Volr tab[10]);
