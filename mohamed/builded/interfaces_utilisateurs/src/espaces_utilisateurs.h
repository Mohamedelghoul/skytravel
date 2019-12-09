#ifndef ESPACES_UTILISATEURS_H_
#define ESPACES_UTILISATEURS_H_

typedef struct date
{
	int jour;
	int mois;
	int annee;
}date;

typedef struct utilisateur
{
	char identifiant[20];
	char mot_de_passe[100];
	char nom[20];
	char prenom[20];
	date naissance;
	char cin[20];
	char role[20];
}utilisateur;


void ajouter_utilisateur(utilisateur u);
int verifier_authentification (char user[], char pass[]);
void supprimer_utilisateur(char identifiant[]);
int verifier_identifiant(char I[]);

#endif

