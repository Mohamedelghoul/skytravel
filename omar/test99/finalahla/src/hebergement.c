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
	 column = gtk_tree_view_column_new_with_attributes("Destination", renderer, "text",ADRESSE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	}


 store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 f = fopen("hebergement.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else
	
	{ 
	f=fopen("hebergement.txt","a+");
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


int supprimer_hotel(char id1[10])
{ 	
	FILE*f ,*s;
    	hotel h;
	int i,j;

    	f=fopen("hebergement.txt","a+");
	    s=fopen("hebergement.tmp.txt","a+");
	if(f!=NULL) 
	{
			
    			

			while(fscanf(f,"%s %s %s  %s ",h.ID,h.nom,h.prix,h.adresse)!=EOF)
			{i++;
    				if(strcmp(h.ID,id1)!=0)
    				{	
						fprintf(s,"%s %s %s  %s  \n",h.ID ,h.nom,h.prix,h.adresse);
						j++;}
			}
			fclose(f);
			fclose(s);

			remove("hebergement.txt");
			rename("hebergement.tmp.txt","hebergement.txt");
}

  if (i==j)
  {
	  return (1);
  }
 else
	return (0);
}


int remplir_combo(hotel tab[])
{
	int n=0;
	FILE* f=fopen("hebergement.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s ",tab[n].ID,&tab[n].nom,&tab[n].prix,&tab[n].adresse)!=EOF)
			{n++;}
		fclose(f);
	}
	return n;
}


void ajouter_hotel10(hotel h)
{

 FILE *f;
 f=fopen("hebergement.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s \n",h.ID,h.nom,h.prix,h.adresse);
 fclose(f);
 }
}




void modifier_hotel(char n[],char nom[],char prix[],char adresse[])
{
char s1[20];char s2[20];
char s3[20];char s4[20];

 FILE*f,*f1;
  
  f=fopen("hebergement.txt","r+");
  f1=fopen("hebergement1.txt","w+");

 if(f !=NULL) 
  { 
    while (fscanf(f,"%s %s %s %s \n",s1, s2, s3 ,s4)!=EOF)
 {
     if (strcmp(s1,n)==0)	 
	{
    strcpy(s2,nom);strcpy(s3,prix);strcpy(s4,adresse);
	  fprintf(f1,"%s %s %s %s \n",s1, s2, s3 ,s4);
	}

 else 
     	fprintf(f1,"%s %s %s %s \n",s1, s2, s3 ,s4);
    }
  fclose(f1);
  fclose(f);
  }
f=fopen("hebergement.txt","w+");
  f1=fopen("hebergement1.txt","r+");
    while (fscanf(f1,"%s %s %s %s \n",s1, s2, s3 ,s4)!=EOF)
	fprintf(f,"%s %s %s %s \n",s1, s2, s3 ,s4);


  fclose(f1);
  fclose(f);
   
}






int remplir_combo2(hotel tab[],hotel tab2[],char bo[])
{
	int n=0;int i=0;
	FILE* f=fopen("hebergement.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s ",tab[n].ID,&tab[n].nom,&tab[n].prix,&tab[n].adresse)!=EOF)
			{n++;}
		fclose(f);
}

	for(i=0;i<n;i++)
{
	if (strcmp(bo,tab[i].adresse)==0)
	
	strcpy(tab2[i].nom,tab[i].nom);
	


	
	}
return n;	
}



void occu(hotel tab[],int size)
{
int i;
int j;
int k;

for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            /* If any duplicate found */
            if(strcmp(tab[i].adresse,tab[j].adresse)==0) 
            {
                /* Delete the current duplicate element */
                for(k=j; k<size; k++)
                {
                    strcpy(tab[k].adresse,tab[k+1].adresse); 
                }

                /* Decrement size after removing duplicate element */
                size--;

                /* If shifting of elements occur then don't increment j */
                j--;
            }
        }
    }


}



void cherID(char s4[],char w[])
{
	char st1[20];char st2[20];
	char st3[20];char st4[20];
	FILE *f;
    f = fopen("hebergement.txt", "r");
	if(f==NULL)
	{

		return;
	}		
	else 
    {
		while(fscanf(f,"%s %s %s %s\n",st1,st2,st3,st4)!=EOF)
        {
		if ((strcmp(s4,st2)==0))
		{
			strcpy(w,st1);
			
		}
		}
    }
    fclose(f);
}

void cherPrix(char kas[],char krout[])
{
	char st1[20];char st2[20];
	char st3[20];char st4[20];
	FILE *f;
    f = fopen("hebergement.txt", "r");
	if(f==NULL)
	{

		return;
	}		
	else 
    {
		while(fscanf(f,"%s %s %s %s\n",st1,st2,st3,st4)!=EOF)
        {
		if ((strcmp(kas,st2)==0))
		{
			strcpy(krout,st3);
			
		}
		}
    }
    fclose(f);
}


void cherDesination(char mak[],char rouna[])
{
	char st1[20];char st2[20];
	char st3[20];char st4[20];
	FILE *f;
    f = fopen("hebergement.txt", "r");
	if(f==NULL)
	{

		return;
	}		
	else 
    {
		while(fscanf(f,"%s %s %s %s\n",st1,st2,st3,st4)!=EOF)
        {
		if ((strcmp(mak,st2)==0))
		{
			strcpy(rouna,st4);
			
		}
		}
    }
    fclose(f);
}


int getmontant(int prixn,int ndn,int ndp,float coef,int nde,int ndc)
{
int montant;
montant=(prixn*ndn*ndp*coef)+(nde*prixn*ndn*coef*0.5);
if (ndc>1)
montant=(montant+montant*(ndc*0.33));
return montant;
}


void ajouter_hotreservation(reshotel r)
{

 FILE *f;
 f=fopen("hebergementreserve.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s \n",r.ID_client,r.ID_res,r.h.ID,r.date_depart,r.date_arrive,r.h.adresse,r.h.nom,r.personne,r.enfants,r.chambres,r.pension,r.montant);
 fclose(f);
 }
}




int verifier_code_hotel(char C[])
{
	hotel h;
	FILE* f=NULL;
	f=fopen("hebergement.txt","r");
	if(f !=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s",h.ID);
			if (strcmp(C,h.ID)==0)
				return (1);
		}
	}
	return (0);
}






























