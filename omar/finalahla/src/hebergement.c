#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hebergement.h"
#include <gtk/gtk.h>




enum
{
	IDENTIFIANT,
	NOM,
	PRIX,
	ADRESSE,
	COLUMNS
};




void afficher_hotel(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;

 char ID [30];
 char nom [30];
 char prix[30];
 char adresse[30];

 store=NULL;
 FILE *f;

 store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{

         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 	

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Hotel", renderer, "text",NOM, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Prix par nuitee", renderer, "text",PRIX, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Adresse", renderer, "text",ADRESSE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	}


 store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 f = fopen("/home/omarab/Projects/finalahla/src/hebergement.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else
	
	{ 
	f=fopen("/home/omarab/Projects/finalahla/src/hebergement.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",ID,nom,prix,adresse)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,IDENTIFIANT,ID,NOM,nom,PRIX,prix,ADRESSE,adresse,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
	
}



int supprimer_hotel(char s1[],char s2[],char s3[],char s4[])
{
  FILE*f,*f1;
  int i,j;
  f=fopen("/home/omarab/Projects/finalahla/src/hebergement.txt","r+");
  f1=fopen("/home/omarab/Projects/finalahla/src/hebergement.txt","w+");
  char st1[20];char st2[20];
  char st3[20];char st4[20];
  
  

  i=0;
  j=0;
  
  if(f !=NULL) 
  { 
     while(fscanf(f,"%s %s %s %s\n",st1,st2,st3,st4)!=EOF)
    {
	 i++;
     if ((strcmp(s1,st1)!=0)&&(strcmp(s2,st2)!=0)||((strcmp(s3,st3)!=0))||(strcmp(s4,st4)!=0))
    	{fprintf(f1,"%s %s %s %s \n",st1,st2,st3,st4);
		j++;}

    }
  fclose(f1);
  fclose(f);
  }
  f=fopen("/home/omarab/Projects/finalahla/src/hebergement.txt","w+");
  f1=fopen("/home/omarab/Projects/finalahla/src/hebergement.txt","r+");
 while (fscanf(f1,"%s  %s %s %s\n",st1,st2,st3,st4)!=EOF)
	fprintf(f,"%s %s %s %s\n",st1,st2,st3,st4);

  fclose(f1);
  fclose(f);
  

  if (i==j)
  {
	  return (1);
  }
 else
	return (0);
}

void cherhotel(char s1[],char idk[],char ide[],char idb[])
{
	char st1[20];char st2[20];
	char st3[20];char st4[20];
	FILE *f;
    f = fopen("/home/omarab/Projects/finalahla/src/hebergement.txt", "r");
	if(f==NULL)
	{

		return;
	}		
	else 
    {
		while(fscanf(f,"%s %s %s %s\n",st1,st2,st3,st4)!=EOF)
        {
		if ((strcmp(s1,st1)==0))
		{
			strcpy(idk,st2);
			strcpy(ide,st3);
			strcpy(idb,st4);
		}
		}
    }
    fclose(f);
}



























