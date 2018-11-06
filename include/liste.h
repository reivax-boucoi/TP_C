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
void add_coureur(Liste* l, Coureur *c);

//4
void aller_debut (Liste* l); //positionne le courant au début de la liste
void avancer (Liste *l); //fait avancer le courant dans la liste
int fin (Liste *l); //renvoie 0 si le courant est à la fin de la liste, renvoie 1 sinon

Coureur* current_coureur(Liste *l);
void erase_current(Liste *l);//current should point to next available, previous if already at tail
void sort(Liste *l);
void swap(Elt* a, Elt* b);
void display(Liste * l);
  
#endif
