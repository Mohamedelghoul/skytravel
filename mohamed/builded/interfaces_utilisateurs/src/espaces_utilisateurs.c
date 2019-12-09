#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "espaces_utilisateurs.h"

void ajouter_utilisateur(utilisateur u)
{
	FILE* f=NULL;
	f=fopen("utilisateurs.txt","a");
	if(f!=NULL)
	{
		fprintf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,u.naissance.jour,u.naissance.mois,u.naissance.annee,u.cin,u.role);
		fclose(f);
		//compare_u.role
	}
	else
		printf("Erreur: Probleme dans l'overture du fichier dans fonction ajouter_employee.");
}

int verifier_authentification (char user[], char pass[])
{
	FILE* f=NULL;
	utilisateur u;
	f=fopen("utilisateurs.txt","r");
	if(f !=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if(strcmp(user,u.identifiant)==0)
			{
				if(strcmp(pass,u.mot_de_passe)==0)
					{
						fclose(f);
						if(strcmp(u.role,"admin")==0)
							return(1);
						if(strcmp(u.role,"employee")==0)
							return(2);
						if(strcmp(u.role,"client")==0)
							return (3);
					}
			}
		}
		fclose(f);
	}
	else
		printf("Erreur: Probleme dans l'overture du fichier dans fonction verifier_authentification.");
	return (-1);
}

void supprimer_utilisateur(char identifiant[])
{
	utilisateur u;
	FILE *fichierIn=NULL;
	FILE *fichierOut=NULL;
	if((fichierIn=fopen("utilisateurs.txt","r"))==NULL)
		printf("Erreur : Probleme de l'overture du fichier du lecture dans fonction suuprimer_employee.\n");
	if((fichierOut=fopen("utilisateurs_copie.txt","w"))==NULL)
	{
		fclose(fichierIn);
		printf("Erreur : Probleme de l'overture du fichier d'ecriture dans fonction suuprimer_employee.\n");
	}

	while(fscanf(fichierIn,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role)!=EOF)
	{
		if(strcmp(u.identifiant,identifiant)!=0)
			fprintf(fichierOut,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,u.naissance.jour,u.naissance.mois,u.naissance.annee,u.cin,u.role);
	}

	fclose(fichierIn);
	fclose(fichierOut);	
	remove("utilisateurs.txt");
	rename("utilisateurs_copie.txt","utilisateurs.txt");
}

int verifier_identifiant(char I[])
{
	utilisateur u;
	FILE* f=NULL;
	f=fopen("utilisateurs.txt","r");
	if(f !=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %s %d %d %d %s %s \n",u.identifiant,u.mot_de_passe,u.nom,u.prenom,&u.naissance.jour,&u.naissance.mois,&u.naissance.annee,u.cin,u.role);
			if (strcmp(I,u.identifiant)==0)
				return (1);
		}
	}
	else
		printf("Erreur : Probleme dans l'overture du fichier dans fonction verification_identifiant.");
	return (0);
}
