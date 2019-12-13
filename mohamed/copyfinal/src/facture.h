#include <gtk/gtk.h>

typedef struct
{
	int id;
	int type;
	char id_reservation[30];
	int typeprestation;
}Devis;

typedef struct date
{
	char jour[10];
	char mois[10];
	char annee[10];
}Date;

typedef struct
{
	char id_devis[30];	
	char identifiant[30];
	char id_reservation[30];
	char id_hebergement[30];
	char depart[30];
	char arrivee[30];
	char destination[30];
	char nom_hotel[30];
	char personne[30]; 
	char enfants[30];
	char chambres[30];
	char pension[30];
	char montant[30];
}Dhebergement;


typedef struct
{
	char id_devis[30];	
	char identifiant[30];
	char id_reservation[30];
	char id_vol[30];
	Date depart;
	Date arrivee;
	char vdepart[30];
	char vdestination[30]; 
	char personne[30];
	char montant[30];
}Dvol;

typedef struct
{	
	char reduction[30];
	char Codesecret[30];
	char id_reservation[30];
	int idpayement;
	char Modepayement[30];
	int idcarte;
	char Dateexpiration[30];

}Payement;

typedef struct excursionr
{
	char id_devis[30];
	char identifiant[10];
	char id_excursion[10];
	char id_reservation[10];
	char depart[20];
	char arrivee[20];
	Date d; 
	char personne[30];
	char montant[30];
}Dexcursion;

int calculer(Devis D);

void modifier(int identifiant ,Devis devis);
void supprimer_devis(char id[],int typeprestation);
void afficher_ADH(GtkWidget *liste);
void afficher_ADE(GtkWidget *liste);
void afficher_AFH(GtkWidget *liste);	
void afficher_AFE(GtkWidget *liste);
void afficher_ADV(GtkWidget *liste);
void afficher_AFV(GtkWidget *liste);
void afficher_CDH(GtkWidget *liste,char idC[]);
void afficher_CFH(GtkWidget *liste,char idC[]);
void afficher_CDE(GtkWidget *liste,char idC[]);
void afficher_CFE(GtkWidget *liste,char idC[]);
void afficher_CDV(GtkWidget *liste,char idC[]);
void afficher_CFV(GtkWidget *liste,char idC[]);
int remplir_combo_hebergement(Dhebergement tab[]);
int remplir_combo_excursion(Dexcursion tab[]);
int remplir_combo_vol(Dvol tab[]);
int remplir_combo_hebergement_client(char idC[],char T[50][50]);
int remplir_combo_excursion_client(char idC[],char T[50][50]);
int remplir_combo_vol_client(char idC[],char T[50][50]);
int code_devis(int typeprestation);
int verifier_code(char C[],int typeprestation,int type);
void ajouter_facture(Dhebergement H);

//OKReduction_validerH
//OKReservation_annulerH
//Reservation_annulerH
//Reduction_validerH


//Window_codeCDH
//introuvablecodeCDH
//entrycodeCDH


//mode_payement //combo :comboboxmodepayement //comboboxCCDV(ta5eth menou id)  //entry iddevis: iddevisMP
//Payement
	
//on_ValidermodepayementE_clicked
//on_ValiderR_CDH_clicked

//Valider mode payement(na9es id)


//on_R_validermodepayementV(MAFAMECH)







