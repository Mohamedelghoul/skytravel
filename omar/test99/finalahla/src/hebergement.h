#include <gtk/gtk.h>


#include <gtk/gtk.h>
typedef struct
{
	char ID[10];
	char nom[20];
	char prix[10];
	char adresse[20];
}hotel;


typedef struct
{
	hotel h;
	char ID_client[10];
	char ID_res[10];
	char date_depart[20];
	char date_arrive[20];
	char personne[3];
	char enfants[3];
	char chambres[3];
	char pension[30];
	char montant[20];
}reshotel;



void afficher_hotel(GtkWidget *liste);
int supprimer_hotel(char id1[10]);
int remplir_combo(hotel tab[]);
void ajouter_hotel10(hotel h);
void modifier_hotel(char n[],char nom[],char prix[],char adresse[]);
int remplir_combo2(hotel tab[],hotel tab2[],char bo[]);
void occu(hotel tab[],int size);
void cherID(char s4[],char w[]);
void cherPrix(char kas[],char krout[]);
void cherDesination(char mak[],char rouna[]);
int getmontant(int prixn,int ndn,int ndp,float coef,int nde,int ndc);
void ajouter_hotreservation(reshotel r);
int verifier_code_hotel(char C[]);
