#ifndef _LISTE_H_
#define _LISTE_H_
#
#include <string.h>
#include "coureur.h"

struct Elt{
    Coureur *c;
    struct Elt* suiv;
};
typedef struct Elt Elt;

struct Liste{
    Elt* head;
    Elt* current;
    Elt* tail;
};
typedef struct Liste Liste;


Liste* init();
void add_coureur(Liste* l, Coureur *c);//ajoute un coureur a la liste

//4
void aller_debut (Liste* l); //positionne le courant au début de la liste
void avancer (Liste *l); //fait avancer le courant dans la liste
int fin (Liste *l); //renvoie 0 si le courant est à la fin de la liste, renvoie 1 sinon

Coureur* current_coureur(Liste *l);//retourne le coureur courant
void erase_current(Liste *l);//current should point to next available, previous if already at tail
void sort(Liste *l);//ordonne un liste selon le temps de chaque coureur
void swap(Elt* a, Elt* b);//echange deux coureurs
void display(Liste * l);//affiche une liste
  
#endif
