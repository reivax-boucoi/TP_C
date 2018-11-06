#include "coureur.h"

//creer coureur
  Coureur* creer_coureur(char* name, char* surname,int nb, char* team, int time){
    Coureur *c=malloc(sizeof(Coureur));
    c->name= name;
    c->surname= surname;
    c->nb= nb;
    c->team=team;
    c->time=time;
    
    return c;

  }
//afficher coureur
void afficher_coureur(Coureur c){
  int heure= c.time/3600;
  int minute=(c.time % 3600) / 60;
  int seconde=(c.time % 3600) % 60;

    printf("Nom: %s, Prenom : %s, Dossard: %d, Team: %s, Temps cumule: %d heures %d minutes %d secondes\r\n",c.name,c.surname,c.nb,c.team,heure,minute,seconde);

  }
//ajouter temps
  void ajouter_temps(Coureur* c, int time){
    c->time+=time;

  }

