#ifndef _COUREUR_H_
#define _COUREUR_H_
#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR

struct Coureur{
	char* name;
	char* surname;
	int nb;
	char* team;
	int time;   
	int nb_team;
};
typedef struct Coureur Coureur;

//creer coureur
Coureur* creer_coureur(char* name, char* surname,int nb, char*team, int time,int nb_team); 

//afficher coureur
void afficher_coureur(Coureur c);

//ajouter temps
void ajouter_temps(Coureur* c, int time);



#endif
