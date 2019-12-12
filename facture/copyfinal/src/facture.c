//zid invivible code secret mta3 carte
//zid facture payée w ija ll agence w payement w mode payement -_-
// na5thou id client fel integration
// combobox modifier badlou

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "facture.h"
#include <gtk/gtk.h>
#include <time.h>

int code_devis(int typeprestation)
{
	if (typeprestation==0)
	{	
	int A;
	srand(time(NULL));
	A=rand()%900;
	A=A+100;
	return(A);
	}
	else if (typeprestation==1)
	{
	int A;
	srand(time(NULL));
	A=rand()%9000;
	A=A+1000;
	return(A);
	}
	else if(typeprestation==2)
	{
	int A;
	srand(time(NULL));
	A=rand()%90;
	A=A+10;
	return(A);
	}
}


int verifier_code(char C[],int typeprestation,int type)
{
   if(type==0)
   {
	if (typeprestation==0)
	{	
	Dhebergement H;
	FILE* f=NULL;
	f=fopen("devishebergement.txt","r");
	if(f !=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s",H.id_devis);
			if (strcmp(C,H.id_devis)==0)
				return (1);
		}
	}
	return (0);
	}
	else if (typeprestation==1)
	{
	Dexcursion E;
	FILE* f=NULL;
	f=fopen("devisexcursion.txt","r");
	if(f !=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s",E.id_devis);
			if (strcmp(C,E.id_devis)==0)
				return (1);
		}
	}
	return (0);	
	}
	if (typeprestation==2)
	{
	FILE* f=NULL;
	Dexcursion V;
	if(f!=NULL)
	
	f=fopen("devisvol.txt","r");
	{
		while(!feof(f))
		{
			fscanf(f,"%s",V.id_devis);
			if (strcmp(C,V.id_devis)==0)
				return (1);
		}
	}
	return (0);
	}
   }
   if(type==1)
   {
	if (typeprestation==0)
	{	
	Dhebergement H;
	FILE* f=NULL;
	f=fopen("facturehebergement.txt","r");
	if(f !=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s",H.id_devis);
			if (strcmp(C,H.id_devis)==0)
				return (1);
		}
	}
	return (0);
	}
	else if (typeprestation==1)
	{
	Dexcursion E;
	FILE* f=NULL;
	f=fopen("factureexcursion.txt","r");
	if(f !=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s",E.id_devis);
			if (strcmp(C,E.id_devis)==0)
				return (1);
		}
	}
	return (0);	
	}
	if (typeprestation==2)
	{
	Dexcursion V;
	FILE* f=NULL;
	if(f !=NULL)
	
	f=fopen("facturevol.txt","r");
	{
		while(!feof(f))
		{
			fscanf(f,"%s",V.id_devis);
			if (strcmp(C,V.id_devis)==0)
				return (1);
		}
	}
	return (0);
	}
   }
}
// admin
// afficher ADH
void afficher_ADH(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	

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
		store=NULL;
		char id[30];
		
	
		FILE *f;
	
		store=gtk_tree_view_get_model(liste);
		if (store==NULL)
		{
	  
	  
			  enum
			  {
				IDDEVIS,
				IDENTIFIANT,
				IDRESERVATION,
				IDHEBERGEMENT,
				DEPART,
				ARRIVEE,
				DESTINATION,
				NOMHOTEL,
				PERSONNE,
				ENFANTS,
				CHAMBRES,
				PENSION,
				MONTANT,
				COLUMNS
			  };

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_devis",renderer, "text",IDDEVIS, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",IDENTIFIANT, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes(" id_reservation",renderer, "text",IDRESERVATION, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_hebergement",renderer, "text",IDHEBERGEMENT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		
	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" depart",renderer, "text",DEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" arrivee",renderer, "text",ARRIVEE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" destination",renderer, "text",DESTINATION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" nom_hotel",renderer,"text",NOMHOTEL,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" personne",renderer, "text",PERSONNE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" enfants",renderer, "text",ENFANTS,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" chambres",renderer, "text",CHAMBRES,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" pension",renderer, "text",PENSION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	  		f= fopen("devishebergement.txt", "r");

	  		if(f!=NULL)
			{
	        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id_devis,identifiant,id_reservation,id_hebergement,depart,arrivee,destination,nom_hotel,personne,enfants,chambres,pension,montant)!=EOF)
	    		{

	  			gtk_list_store_append(store, &iter);
	  		gtk_list_store_set(store,&iter,IDDEVIS,id_devis,IDENTIFIANT,identifiant,IDRESERVATION,id_reservation,IDHEBERGEMENT,id_hebergement,DEPART,depart,ARRIVEE,arrivee,DESTINATION,destination,NOMHOTEL,nom_hotel,PERSONNE,personne,ENFANTS,enfants,CHAMBRES,chambres,PENSION,pension,MONTANT,montant, -1);
	    		}
	    		fclose(f);
	  		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	  		g_object_unref(store);
			
			}
		}
}

// aficher AFH
void afficher_AFH(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	

		char id_facture[30];
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
		store=NULL;
	
		FILE *f;
	
		store=gtk_tree_view_get_model(liste);
		if (store==NULL)
		{
	  
	  
			  enum
			  {
				IDFACTURE,
				IDENTIFIANT,
				IDRESERVATION,
				IDHEBERGEMENT,
				DEPART,
				ARRIVEE,
				DESTINATION,
				NOMHOTEL,
				PERSONNE,
				ENFANTS,
				CHAMBRES,
				PENSION,
				MONTANT,
				COLUMNS
			  };

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_facture",renderer, "text",IDFACTURE, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",IDENTIFIANT, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes(" id_reservation",renderer, "text",IDRESERVATION, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_hebergement",renderer, "text",IDHEBERGEMENT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		
	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" depart",renderer, "text",DEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" arrivee",renderer, "text",ARRIVEE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" destination",renderer, "text",DESTINATION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" nom_hotel",renderer,"text",NOMHOTEL,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" personne",renderer, "text",PERSONNE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" enfants",renderer, "text",ENFANTS,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" chambres",renderer, "text",CHAMBRES,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" pension",renderer, "text",PENSION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	  		f= fopen("facturehebergement.txt", "r");

	  		if(f!=NULL)
			{
	        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id_facture,identifiant,id_reservation,id_hebergement,depart,arrivee,destination,nom_hotel,personne,enfants,chambres,pension,montant)!=EOF)
	    		{

	  			gtk_list_store_append(store, &iter);
	  		gtk_list_store_set(store,&iter,IDFACTURE,id_facture,IDENTIFIANT,identifiant,IDRESERVATION,id_reservation,IDHEBERGEMENT,id_hebergement,DEPART,depart,ARRIVEE,arrivee,DESTINATION,destination,NOMHOTEL,nom_hotel,PERSONNE,personne,ENFANTS,enfants,CHAMBRES,chambres,PENSION,pension,MONTANT,montant, -1);
	    		}
	    		fclose(f);
	  		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	  		g_object_unref(store);
			
			}
		}
}




// afficher ADE
void afficher_ADE(GtkWidget *liste)
{
		GtkCellRenderer *renderer;
		GtkTreeViewColumn *column;
		GtkTreeIter iter;
		GtkListStore *store;
		
		char date[100]="\0";
		char id_devis[30];
		char identifiant[10];
		char id_excursion[10];
		char id_reservation[10];
		char depart[20];
		char arrivee[20];
		Date d; 
		char personne[30];
		char montant[30];
		store=NULL;
	
		FILE *f;
	
		store=gtk_tree_view_get_model(liste);
		if (store==NULL)
		{
	  
	  
			  enum
			  {
				IDDEVIS,
				IDENTIFIANT,
				IDEXCURSION,
				IDRESERVATION,
				DEPART,
				ARRIVEE,
				D,
				PERSONNE,
				MONTANT,
				COLUMNS1
			  };

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_devis",renderer, "text",IDDEVIS, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",IDENTIFIANT, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_excursion",renderer, "text",IDEXCURSION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes(" id_reservation",renderer, "text",IDRESERVATION, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" depart",renderer, "text",DEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" arrivee",renderer, "text",ARRIVEE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" d",renderer, "text",D,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" personne",renderer, "text",PERSONNE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	  		f= fopen("devisexcursion.txt", "r");

	  		if(f!=NULL)
	  		{
	        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",id_devis,identifiant,id_excursion,id_reservation,depart,arrivee,d.jour,d.mois,d.annee,personne,montant)!=EOF)
	    		{
				sprintf(date,"%s/%s/%s",d.jour,d.mois,d.annee);


	  			gtk_list_store_append(store, &iter);
	  		gtk_list_store_set(store,&iter,IDDEVIS,id_devis,IDENTIFIANT,identifiant,IDEXCURSION,id_excursion,IDRESERVATION,id_reservation,DEPART,depart,ARRIVEE,arrivee,D,date,PERSONNE,personne,MONTANT,montant, -1);
	    		}
	    		fclose(f);
	  		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	  		g_object_unref(store);
			}
		}
}


// afficher AFE
void afficher_AFE(GtkWidget *liste)
{
		GtkCellRenderer *renderer;
		GtkTreeViewColumn *column;
		GtkTreeIter iter;
		GtkListStore *store;
		
		char date[100]="\0";
		char id_facture[30];
		char identifiant[10];
		char id_excursion[10];
		char id_reservation[10];
		char depart[20];
		char arrivee[20];
		Date d; 
		char personne[30];
		char montant[30];
		store=NULL;
	
		FILE *f;
	
		store=gtk_tree_view_get_model(liste);
		if (store==NULL)
		{
	  
	  
			  enum
			  {
				IDFACTURE,
				IDENTIFIANT,
				IDEXCURSION,
				IDRESERVATION,
				DEPART,
				ARRIVEE,
				D,
				PERSONNE,
				MONTANT,
				COLUMNS1
			  };

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_facture",renderer, "text",IDFACTURE, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",IDENTIFIANT, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_excursion",renderer, "text",IDEXCURSION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes(" id_reservation",renderer, "text",IDRESERVATION, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" depart",renderer, "text",DEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" arrivee",renderer, "text",ARRIVEE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" d",renderer, "text",D,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" personne",renderer, "text",PERSONNE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	  		f= fopen("factureexcursion.txt", "r");

	  		if(f!=NULL)
	  		{
	        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",id_facture,identifiant,id_excursion,id_reservation,depart,arrivee,d.jour,d.mois,d.annee,personne,montant)!=EOF)
	    		{
				sprintf(date,"%s/%s/%s",d.jour,d.mois,d.annee);


	  			gtk_list_store_append(store, &iter);
	  		gtk_list_store_set(store,&iter,IDFACTURE,id_facture,IDENTIFIANT,identifiant,IDEXCURSION,id_excursion,IDRESERVATION,id_reservation,DEPART,depart,ARRIVEE,arrivee,D,date,PERSONNE,personne,MONTANT,montant, -1);
	    		}
	    		fclose(f);
	  		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	  		g_object_unref(store);
			}
		}
}

// afficher ADV

void afficher_ADV(GtkWidget *liste)
{
		GtkCellRenderer *renderer;
		GtkTreeViewColumn *column;
		GtkTreeIter iter;
		GtkListStore *store;
		
		char Ddepart[100]="\0";
		char Darrivee[100]="\0";
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
		store=NULL;
	
		FILE *f;
	
		store=gtk_tree_view_get_model(liste);
		if (store==NULL)
		{
	  
	  
			  enum
			  {
				IDDEVIS,
				IDENTIFIANT,
				IDRESERVATION,
				IDVOL,
				DEPART,
				ARRIVEE,
				VDEPART,
				VDESTINATION,
				PERSONNE,
				MONTANT,
				COLUMNS1
			  };

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_devis",renderer, "text",IDDEVIS, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",IDENTIFIANT, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes(" id_reservation",renderer, "text",IDRESERVATION, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		
			renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_vol",renderer, "text",IDVOL,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" depart",renderer, "text",DEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" arrivee",renderer, "text",ARRIVEE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" vdepart",renderer, "text",VDEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" vdestination",renderer, "text",VDESTINATION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" personne",renderer, "text",PERSONNE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	  		f= fopen("devisvol.txt", "r");

	  		if(f!=NULL)
	  		{
	        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",id_devis,identifiant,id_reservation,id_vol,depart.jour,depart.mois,depart.annee,arrivee.jour,arrivee.mois,arrivee.annee,vdepart,vdestination,personne,montant)!=EOF)
	    		{
				sprintf(Ddepart,"%s/%s/%s",depart.jour,depart.mois,depart.annee);

				sprintf(Darrivee,"%s/%s/%s",arrivee.jour,arrivee.mois,arrivee.annee);


	  			gtk_list_store_append(store, &iter);
	  		gtk_list_store_set(store,&iter,IDDEVIS,id_devis,IDENTIFIANT,identifiant,IDRESERVATION,id_reservation,IDVOL,id_vol,DEPART,Ddepart,ARRIVEE,Darrivee,VDEPART,vdepart,VDESTINATION,vdestination,PERSONNE,personne,MONTANT,montant, -1);
	    		}
	    		fclose(f);
	  		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	  		g_object_unref(store);
			}
		}
}



// afficher AFV

void afficher_AFV(GtkWidget *liste)
{
		GtkCellRenderer *renderer;
		GtkTreeViewColumn *column;
		GtkTreeIter iter;
		GtkListStore *store;
		
		char Ddepart[100]="\0";
		char Darrivee[100]="\0";
		char id_facture[30];
		char identifiant[30];
		char id_reservation[30];
		char id_vol[30];
		Date depart;
		Date arrivee;
		char vdepart[30];
		char vdestination[30]; 
		char personne[30];
		char montant[30];
		store=NULL;
	
		FILE *f;
	
		store=gtk_tree_view_get_model(liste);
		if (store==NULL)
		{
	  
	  
			  enum
			  {
				IDFACTURE,
				IDENTIFIANT,
				IDRESERVATION,
				IDVOL,
				DEPART,
				ARRIVEE,
				VDEPART,
				VDESTINATION,
				PERSONNE,
				MONTANT,
				COLUMNS1
			  };

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_facture",renderer, "text",IDFACTURE, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",IDENTIFIANT, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes(" id_reservation",renderer, "text",IDRESERVATION, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		
			renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_vol",renderer, "text",IDVOL,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" depart",renderer, "text",DEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" arrivee",renderer, "text",ARRIVEE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" vdepart",renderer, "text",VDEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" vdestination",renderer, "text",VDESTINATION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" personne",renderer, "text",PERSONNE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	  		f= fopen("facturevol.txt", "r");

	  		if(f!=NULL)
	  		{
	        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",id_facture,identifiant,id_reservation,id_vol,depart.jour,depart.mois,depart.annee,arrivee.jour,arrivee.mois,arrivee.annee,vdepart,vdestination,personne,montant)!=EOF)
	    		{
				sprintf(Ddepart,"%s/%s/%s",depart.jour,depart.mois,depart.annee);

				sprintf(Darrivee,"%s/%s/%s",arrivee.jour,arrivee.mois,arrivee.annee);

	  			gtk_list_store_append(store, &iter);
	  		gtk_list_store_set(store,&iter,IDFACTURE,id_facture,IDENTIFIANT,identifiant,IDRESERVATION,id_reservation,IDVOL,id_vol,DEPART,Ddepart,ARRIVEE,Darrivee,VDEPART,vdepart,VDESTINATION,vdestination,PERSONNE,personne,MONTANT,montant, -1);
	    		}
	    		fclose(f);
	  		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	  		g_object_unref(store);
			}
		}
}

// client
//CDH

void afficher_CDH(GtkWidget *liste,char idC[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	

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
		store=NULL;
	
		FILE *f;
	
		store=gtk_tree_view_get_model(liste);
		if (store==NULL)
		{
	  
	  
			  enum
			  {
				IDDEVIS,
				IDENTIFIANT,
				IDRESERVATION,
				IDHEBERGEMENT,
				DEPART,
				ARRIVEE,
				DESTINATION,
				NOMHOTEL,
				PERSONNE,
				ENFANTS,
				CHAMBRES,
				PENSION,
				MONTANT,
				COLUMNS
			  };

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_devis",renderer, "text",IDDEVIS, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",IDENTIFIANT, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes(" id_reservation",renderer, "text",IDRESERVATION, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_hebergement",renderer, "text",IDHEBERGEMENT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		
	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" depart",renderer, "text",DEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" arrivee",renderer, "text",ARRIVEE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" destination",renderer, "text",DESTINATION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" nom_hotel",renderer,"text",NOMHOTEL,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" personne",renderer, "text",PERSONNE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" enfants",renderer, "text",ENFANTS,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" chambres",renderer, "text",CHAMBRES,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" pension",renderer, "text",PENSION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	  		f= fopen("devishebergement.txt", "r");

	  		if(f!=NULL)
			{
	        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id_devis,identifiant,id_reservation,id_hebergement,depart,arrivee,destination,nom_hotel,personne,enfants,chambres,pension,montant)!=EOF)
	    		{
				if (strcmp(idC,identifiant)==0)
				{

	  			gtk_list_store_append(store, &iter);
	  		gtk_list_store_set(store,&iter,IDDEVIS,id_devis,IDENTIFIANT,identifiant,IDRESERVATION,id_reservation,IDHEBERGEMENT,id_hebergement,DEPART,depart,ARRIVEE,arrivee,DESTINATION,destination,NOMHOTEL,nom_hotel,PERSONNE,personne,ENFANTS,enfants,CHAMBRES,chambres,PENSION,pension,MONTANT,montant, -1);
	    		}   
			}
	    		fclose(f);
	  		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	  		g_object_unref(store);
			
			}
		}
}


//CFH
void afficher_CFH(GtkWidget *liste,char idC[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	

		char id_facture[30];
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
		store=NULL;
	
		FILE *f;
	
		store=gtk_tree_view_get_model(liste);
		if (store==NULL)
		{
	  
	  
			  enum
			  {
				IDFACTURE,
				IDENTIFIANT,
				IDRESERVATION,
				IDHEBERGEMENT,
				DEPART,
				ARRIVEE,
				DESTINATION,
				NOMHOTEL,
				PERSONNE,
				ENFANTS,
				CHAMBRES,
				PENSION,
				MONTANT,
				COLUMNS
			  };

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_facture",renderer, "text",IDFACTURE, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",IDENTIFIANT, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes(" id_reservation",renderer, "text",IDRESERVATION, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_hebergement",renderer, "text",IDHEBERGEMENT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		
	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" depart",renderer, "text",DEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" arrivee",renderer, "text",ARRIVEE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" destination",renderer, "text",DESTINATION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" nom_hotel",renderer,"text",NOMHOTEL,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" personne",renderer, "text",PERSONNE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" enfants",renderer, "text",ENFANTS,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" chambres",renderer, "text",CHAMBRES,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" pension",renderer, "text",PENSION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	  		f= fopen("facturehebergement.txt", "r");

	  		if(f!=NULL)
			{
	        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id_facture,identifiant,id_reservation,id_hebergement,depart,arrivee,destination,nom_hotel,personne,enfants,chambres,pension,montant)!=EOF)
	    		{
				if (strcmp(idC,identifiant)==0)
				{

	  			gtk_list_store_append(store, &iter);
	  		gtk_list_store_set(store,&iter,IDFACTURE,id_facture,IDENTIFIANT,identifiant,IDRESERVATION,id_reservation,IDHEBERGEMENT,id_hebergement,DEPART,depart,ARRIVEE,arrivee,DESTINATION,destination,NOMHOTEL,nom_hotel,PERSONNE,personne,ENFANTS,enfants,CHAMBRES,chambres,PENSION,pension,MONTANT,montant, -1);
	    		}   
			}
	    		fclose(f);
	  		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	  		g_object_unref(store);
			
			}
		}
}

// CDE
void afficher_CDE(GtkWidget *liste,char idC[])
{
		GtkCellRenderer *renderer;
		GtkTreeViewColumn *column;
		GtkTreeIter iter;
		GtkListStore *store;
		
		char date[100]="\0";
		char id_devis[30];
		char identifiant[10];
		char id_excursion[10];
		char id_reservation[10];
		char depart[20];
		char arrivee[20];
		Date d; 
		char personne[30];
		char montant[30];
		store=NULL;
	
		FILE *f;
	
		store=gtk_tree_view_get_model(liste);
		if (store==NULL)
		{
	  
	  
			  enum
			  {
				IDDEVIS,
				IDENTIFIANT,
				IDEXCURSION,
				IDRESERVATION,
				DEPART,
				ARRIVEE,
				D,
				PERSONNE,
				MONTANT,
				COLUMNS1
			  };

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_devis",renderer, "text",IDDEVIS, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",IDENTIFIANT, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_excursion",renderer, "text",IDEXCURSION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes(" id_reservation",renderer, "text",IDRESERVATION, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" depart",renderer, "text",DEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" arrivee",renderer, "text",ARRIVEE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" d",renderer, "text",D,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" personne",renderer, "text",PERSONNE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	  		f= fopen("devisexcursion.txt", "r");

	  		if(f!=NULL)
	  		{
	        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",id_devis,identifiant,id_excursion,id_reservation,depart,arrivee,d.jour,d.mois,d.annee,personne,montant)!=EOF)
	    		{
			   if (strcmp(idC,identifiant)==0)
			   {
				sprintf(date,"%s/%s/%s",d.jour,d.mois,d.annee);


	  			gtk_list_store_append(store, &iter);
	  		gtk_list_store_set(store,&iter,IDDEVIS,id_devis,IDENTIFIANT,identifiant,IDEXCURSION,id_excursion,IDRESERVATION,id_reservation,DEPART,depart,ARRIVEE,arrivee,D,date,PERSONNE,personne,MONTANT,montant, -1);
	    		}
			}
	    		fclose(f);
	  		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	  		g_object_unref(store);
			}
		}
}


// afficher CFE
void afficher_CFE(GtkWidget *liste,char idC[])
{
		GtkCellRenderer *renderer;
		GtkTreeViewColumn *column;
		GtkTreeIter iter;
		GtkListStore *store;
		
		char date[100]="\0";
		char id_facture[30];
		char identifiant[10];
		char id_excursion[10];
		char id_reservation[10];
		char depart[20];
		char arrivee[20];
		Date d; 
		char personne[30];
		char montant[30];
		store=NULL;
	
		FILE *f;
	
		store=gtk_tree_view_get_model(liste);
		if (store==NULL)
		{
	  
	  
			  enum
			  {
				IDFACTURE,
				IDENTIFIANT,
				IDEXCURSION,
				IDRESERVATION,
				DEPART,
				ARRIVEE,
				D,
				PERSONNE,
				MONTANT,
				COLUMNS1
			  };

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_facture",renderer, "text",IDFACTURE, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",IDENTIFIANT, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_excursion",renderer, "text",IDEXCURSION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes(" id_reservation",renderer, "text",IDRESERVATION, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" depart",renderer, "text",DEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" arrivee",renderer, "text",ARRIVEE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" d",renderer, "text",D,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" personne",renderer, "text",PERSONNE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	  		f= fopen("factureexcursion.txt", "r");

	  		if(f!=NULL)
	  		{
	        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",id_facture,identifiant,id_excursion,id_reservation,depart,arrivee,d.jour,d.mois,d.annee,personne,montant)!=EOF)
	    		{
			   if (strcmp(idC,identifiant)==0)
			   {
				sprintf(date,"%s/%s/%s",d.jour,d.mois,d.annee);


	  			gtk_list_store_append(store, &iter);
	  		gtk_list_store_set(store,&iter,IDFACTURE,id_facture,IDENTIFIANT,identifiant,IDEXCURSION,id_excursion,IDRESERVATION,id_reservation,DEPART,depart,ARRIVEE,arrivee,D,date,PERSONNE,personne,MONTANT,montant, -1);
	    		}
			}
	    		fclose(f);
	  		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	  		g_object_unref(store);
			}
		}
}

//CDV
void afficher_CDV(GtkWidget *liste,char idC[])
{
		GtkCellRenderer *renderer;
		GtkTreeViewColumn *column;
		GtkTreeIter iter;
		GtkListStore *store;
		
		char Ddepart[100]="\0";
		char Darrivee[100]="\0";
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
		store=NULL;
	
		FILE *f;
	
		store=gtk_tree_view_get_model(liste);
		if (store==NULL)
		{
	  
	  
			  enum
			  {
				IDDEVIS,
				IDENTIFIANT,
				IDRESERVATION,
				IDVOL,
				DEPART,
				ARRIVEE,
				VDEPART,
				VDESTINATION,
				PERSONNE,
				MONTANT,
				COLUMNS1
			  };

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_devis",renderer, "text",IDDEVIS, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",IDENTIFIANT, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes(" id_reservation",renderer, "text",IDRESERVATION, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		
			renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_vol",renderer, "text",IDVOL,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" depart",renderer, "text",DEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" arrivee",renderer, "text",ARRIVEE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" vdepart",renderer, "text",VDEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" vdestination",renderer, "text",VDESTINATION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" personne",renderer, "text",PERSONNE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	  		f= fopen("devisvol.txt", "r");

	  		if(f!=NULL)
	  		{
	        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",id_devis,identifiant,id_reservation,id_vol,depart.jour,depart.mois,depart.annee,arrivee.jour,arrivee.mois,arrivee.annee,vdepart,vdestination,personne,montant)!=EOF)
	    		{
			   if((strcmp(idC,identifiant)==0))
			   {
				sprintf(Ddepart,"%s/%s/%s",depart.jour,depart.mois,depart.annee);

				sprintf(Darrivee,"%s/%s/%s",arrivee.jour,arrivee.mois,arrivee.annee);


	  			gtk_list_store_append(store, &iter);
	  		gtk_list_store_set(store,&iter,IDDEVIS,id_devis,IDENTIFIANT,identifiant,IDRESERVATION,id_reservation,IDVOL,id_vol,DEPART,Ddepart,ARRIVEE,Darrivee,VDEPART,vdepart,VDESTINATION,vdestination,PERSONNE,personne,MONTANT,montant, -1);
	    		    }
			}
	    		fclose(f);
	  		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	  		g_object_unref(store);
			}
		}
}



// afficher CFV

void afficher_CFV(GtkWidget *liste,char idC[])
{
		GtkCellRenderer *renderer;
		GtkTreeViewColumn *column;
		GtkTreeIter iter;
		GtkListStore *store;
		
		char Ddepart[100]="\0";
		char Darrivee[100]="\0";
		char id_facture[30];
		char identifiant[30];
		char id_reservation[30];
		char id_vol[30];
		Date depart;
		Date arrivee;
		char vdepart[30];
		char vdestination[30]; 
		char personne[30];
		char montant[30];
		store=NULL;
	
		FILE *f;
	
		store=gtk_tree_view_get_model(liste);
		if (store==NULL)
		{
	  
	  
			  enum
			  {
				IDFACTURE,
				IDENTIFIANT,
				IDRESERVATION,
				IDVOL,
				DEPART,
				ARRIVEE,
				VDEPART,
				VDESTINATION,
				PERSONNE,
				MONTANT,
				COLUMNS1
			  };

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_facture",renderer, "text",IDFACTURE, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" identifiant",renderer, "text",IDENTIFIANT, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes(" id_reservation",renderer, "text",IDRESERVATION, NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		
			renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" id_vol",renderer, "text",IDVOL,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" depart",renderer, "text",DEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" arrivee",renderer, "text",ARRIVEE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" vdepart",renderer, "text",VDEPART,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" vdestination",renderer, "text",VDESTINATION,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" personne",renderer, "text",PERSONNE,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	  		renderer=gtk_cell_renderer_text_new();
	  		column=gtk_tree_view_column_new_with_attributes(" montant",renderer, "text",MONTANT,NULL);
	  		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



	  		store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	  		f= fopen("facturevol.txt", "r");

	  		if(f!=NULL)
	  		{
	        	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",id_facture,identifiant,id_reservation,id_vol,depart.jour,depart.mois,depart.annee,arrivee.jour,arrivee.mois,arrivee.annee,vdepart,vdestination,personne,montant)!=EOF)
	    		{
			   if((strcmp(idC,identifiant)==0))
			   {
				sprintf(Ddepart,"%s/%s/%s",depart.jour,depart.mois,depart.annee);

				sprintf(Darrivee,"%s/%s/%s",arrivee.jour,arrivee.mois,arrivee.annee);

	  			gtk_list_store_append(store, &iter);
	  		gtk_list_store_set(store,&iter,IDFACTURE,id_facture,IDENTIFIANT,identifiant,IDRESERVATION,id_reservation,IDVOL,id_vol,DEPART,Ddepart,ARRIVEE,Darrivee,VDEPART,vdepart,VDESTINATION,vdestination,PERSONNE,personne,MONTANT,montant, -1);
	    		   }
			}
	    		fclose(f);
	  		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	  		g_object_unref(store);
			}
		}
}
//remplir_combo_hebergement
int remplir_combo_hebergement(Dhebergement tab[])
{
	int n=0;
	FILE *f;
	f=fopen("/home/asma/Desktop/copyfinal/src/devishebergement.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",tab[n].id_devis,&tab[n].identifiant,&tab[n].id_reservation,&tab[n].id_hebergement,&tab[n].depart,&tab[n].arrivee,&tab[n].destination,&tab[n].nom_hotel,&tab[n].personne,&tab[n].enfants,&tab[n].chambres,&tab[n].pension,&tab[n].montant)!=EOF)
		{n++;}
		fclose(f);
	}
	return n;
}
//remplir_combo_excursion
int remplir_combo_excursion(Dexcursion tab[])
{
	int n=0;
	FILE *f; 
	f=fopen("/home/asma/Desktop/copyfinal/src/devisexcursion.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",tab[n].id_devis,&tab[n].identifiant,&tab[n].id_excursion,&tab[n].id_reservation,&tab[n].depart,&tab[n].arrivee,&tab[n].d.jour,&tab[n].d.mois,&tab[n].d.annee,&tab[n].personne,&tab[n].montant)!=EOF)
		{n++;}
		fclose(f);
	}
	return n;
}
//remplir_combo_vol
int remplir_combo_vol(Dvol tab[])
{
	int n=0;
	FILE *f; 
	f=fopen("/home/asma/Desktop/copyfinal/src/devisvol.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",tab[n].id_devis,&tab[n].identifiant,&tab[n].id_reservation,&tab[n].id_vol,&tab[n].depart.jour,&tab[n].depart.mois,&tab[n].depart.annee,&tab[n].arrivee.jour,&tab[n].arrivee.mois,&tab[n].arrivee.annee,&tab[n].vdepart,&tab[n].vdestination,&tab[n].personne,&tab[n].montant)!=EOF)
		{n++;}
		fclose(f);
	}
	return n;
}
//remplir combo heber client
int remplir_combo_hebergement_client(char idC[],char T[50][50])
{
	int n=0;
	Dhebergement H;
	FILE* f=NULL;
	f=fopen("devishebergement.txt","a+");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",H.id_devis,H.identifiant,H.id_reservation,H.id_hebergement,H.depart,H.arrivee,H.destination,H.nom_hotel,H.personne,H.enfants,H.chambres,H.pension,H.montant)!=EOF)
		if (strcmp(H.identifiant,idC)==0)
		{
			strcpy(T[n],H.id_devis);
			n++;
		}
	}
	fclose(f);
	return n;
}
//remplir combo excursion client
int remplir_combo_excursion_client(char idC[],char T[50][50])
{
	int n=0;
	Dexcursion E;
	FILE* f=NULL;
	f=fopen("devisexcursion.txt","a+");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",E.id_devis,E.identifiant,E.id_excursion,E.id_reservation,E.depart,E.arrivee,E.d.jour,E.d.mois,E.d.annee,E.personne,E.montant)!=EOF)
		if (strcmp(E.identifiant,idC)==0)
		{
			strcpy(T[n],E.id_devis);
			n++;
		}
	}
	fclose(f);
	return n;
}
//remplir combo vol client
int remplir_combo_vol_client(char idC[],char T[50][50])
{
	int n=0;
	char id_devis[30];
	char identifiant[30];
	FILE* f=NULL;
	Dvol V;
	f=fopen("devisvol.txt","a+");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",V.id_devis,V.identifiant,V.id_reservation,V.id_vol,V.depart.jour,V.depart.mois,V.depart.annee,V.arrivee.jour,V.arrivee.mois,V.arrivee.annee,V.vdepart,V.vdestination,V.personne,V.montant)!=EOF)
		if (strcmp(V.identifiant,idC)==0)
		{
			strcpy(T[n],V.id_devis);
			n++;
		}
	}
	fclose(f);
	return n;
}

void supprimer_devis(char id[],int typeprestation)
{

	if(typeprestation==0)
	{
	
			FILE*f=NULL;
			FILE*f1=NULL;
			Dhebergement H;
			f=fopen("devishebergement.txt","a+");
			f1=fopen("devishebergement_copie.txt","a+");
			
			while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",H.id_devis,H.identifiant,H.id_reservation,H.id_hebergement,H.depart,H.arrivee,H.destination,H.nom_hotel,H.personne,H.enfants,H.chambres,H.pension,H.montant)!=EOF)
			{
	        		if((strcmp(H.id_devis,id)!=0))
	        		{
	        			fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",H.id_devis,H.identifiant,H.id_reservation,H.id_hebergement,H.depart,H.arrivee,H.destination,H.nom_hotel,H.personne,H.enfants,H.chambres,H.pension,H.montant);

	        		}
			}
				fclose(f);
				fclose(f1);
				remove("devishebergement.txt");
				rename("devishebergement_copie.txt","devishebergement.txt");
	}



	else if (typeprestation==1)
	{
		FILE*f=NULL;
		FILE*f1=NULL;
		Dexcursion E;
		int b=0;
		f=fopen("devisexcursion.txt","a+");
		f1=fopen("devisexcursion_copie.txt","a+");
		
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",E.id_devis,E.identifiant,E.id_reservation,E.id_excursion,E.depart,E.arrivee,E.d.jour,E.d.mois,E.d.annee,E.personne,E.montant)!=EOF)
			{
			        if((strcmp(E.id_devis,id)!=0))	
			        {
        				fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s \n",E.id_devis,E.identifiant,E.id_reservation,E.id_excursion,E.depart,E.arrivee,E.d.jour,E.d.mois,E.d.annee,E.personne,E.montant);
				}
			}
			fclose(f);
			fclose(f1);
			remove("devisexcursion.txt");
			rename("devisexcursion_copie.txt","devisexcursion.txt");

				
			
	}

		else if (typeprestation==2)
		{
			FILE*f=NULL;
			FILE*f1=NULL;
			Dvol V;
			int b=0;
			f=fopen("devisvol.txt","a+");
			f1=fopen("devisvol_copie.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",V.id_devis,V.identifiant,V.id_reservation,V.id_vol,V.depart.jour,V.depart.mois,V.depart.annee,V.arrivee.jour,V.arrivee.mois,V.arrivee.annee,V.vdepart,V.vdestination,V.personne,V.montant)!=EOF)
			{
			        if((strcmp(V.id_devis,id)!=0))
			        {
				        fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",V.id_devis,V.identifiant,V.id_reservation,V.id_vol,V.depart.jour,V.depart.mois,V.depart.annee,V.arrivee.jour,V.arrivee.mois,V.arrivee.annee,V.vdepart,V.vdestination,V.personne,V.montant);

			        }
			}
			fclose(f);
			fclose(f1);
			remove("devisvol.txt");
			rename("devisvol_copie.txt","devisvol.txt");

			
		}

}

void ajouter_facture(Dhebergement H)
{

			/*do
			{
			sprintf(code_devis(0),"%d",id);
			strcpy(H.id_devis,id);
			}
			while(verifier_code(H.id_devis,0,0)!=0);*/
			FILE *f=NULL;
			f=fopen("facturehebergement.txt","a+");
			if(f!=NULL)
			{
				fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",H.id_devis,H.identifiant,H.id_reservation,H.id_hebergement,H.depart,H.arrivee,H.destination,H.nom_hotel,H.personne,H.enfants,H.chambres,H.pension,H.montant);
				fclose(f);
			
}
}
		/*else if (typeprestation==1)
		{

			Dexcursion E;
			char id[30];
			do
			{
			sprintf(code_devis(1),"%d",id);
			strcpy(E.id_devis,id);
			}
			while(verifier_code(E.id_devis,1,0)!=0);
			FILE *f=NULL;
			f=fopen("devisexcursion.txt","a");
			if(f!=NULL)
			{
				fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",E.id_devis,E.identifiant,E.id_reservation,E.id_excursion,E.depart,E.arrivee,E.d.jour,E.d.mois,E.d.annee,E.personne,E.montant);
				fclose(f);
			}
		}
		else if (typeprestation==2)
		{
			Dvol V;
			char id[30];
			do
			{
			sprintf(code_devis(2),"%d",id);
			strcpy(V.id_devis,id);
			}
			while(verifier_code(V.id_devis,2,0)!=0);
			FILE *f=NULL;
			Date depart,arrivee;
			f=fopen("devisvol.txt","a");
			if(f!=NULL)
			{
				fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",V.id_devis,V.identifiant,V.id_reservation,V.id_vol,V.depart.jour,V.depart.mois,V.depart.annee,V.arrivee.jour,V.arrivee.mois,V.arrivee.annee,V.vdepart,V.vdestination,V.personne,V.montant);
				fclose(f);
			}
		}
	}
	else if (type==1)
	{
		if (typeprestation==0)
		{
			Dhebergement H;
			char id[30];
			do
			{
			sprintf(code_devis(0),"%d",id);
			strcpy(H.id_devis,id);
			}
			while(verifier_code(H.id_devis,0,1)!=0);
			FILE *f=NULL;
			f=fopen("facturehebergement.txt","a");
			if(f!=NULL)
			{
				fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",H.id_devis,H.identifiant,H.id_reservation,H.id_hebergement,H.depart,H.arrivee,H.destination,H.nom_hotel,H.personne,H.enfants,H.chambres,H.pension,H.montant);
				fclose(f);
			}
		}
		else if (typeprestation==1)
		{
			Dexcursion E;
			char id[30];
			do
			{
			sprintf(code_devis(1),"%d",id);
			strcpy(E.id_devis,id);
			}
			while(verifier_code(E.id_devis,1,1)!=0);
			FILE *f=NULL;
			f=fopen("factureexcursion.txt","a");
			if(f!=NULL)
			{
				fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",E.id_devis,E.identifiant,E.id_reservation,E.id_excursion,E.depart,E.arrivee,E.d.jour,E.d.mois,E.d.annee,E.personne,E.montant);
				fclose(f);
			}
		}
		else if (typeprestation==2)
		{
			Dvol V;
			char id[30];
			do
			{
			sprintf(code_devis(2),"%d",id);
			strcpy(V.id_devis,id);
			}
			while(verifier_code(V.id_devis,2,1)!=0);
			Date depart,arrivee;
			FILE *f=NULL;
			f=fopen("facturevol.txt","a");
			if(f!=NULL)
			{
				fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",V.id_devis,V.identifiant,V.id_reservation,V.id_vol,V.depart.jour,V.depart.mois,V.depart.annee,V.arrivee.jour,V.arrivee.mois,V.arrivee.annee,V.vdepart,V.vdestination,V.personne,V.montant);
				fclose(f);
			}
		}
	}
}*/









