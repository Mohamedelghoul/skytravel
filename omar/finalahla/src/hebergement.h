#include <gtk/gtk.h>


#include <gtk/gtk.h>
typedef struct
{
	char ID[10];
	char nom[20];
	char prix[10];
	char adresse[20];
}hotel;


void afficher_hotel(GtkWidget *liste);
int supprimer_hotel(char s1[],char s2[],char s3[],char s4[]);
void cherhotel(char s1[],char idk[],char ide[],char idb[]);

