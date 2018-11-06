
#include "liste.h"


Liste* init(){
    Liste* l= malloc (sizeof(Liste));
    l->head= NULL;
    l->tail= NULL;
    l->current = NULL;
    return l;
}

void add_coureur(Liste* l, Coureur *c){
    Elt* element;
    element= malloc (sizeof(Elt));
    element->c=c;
    element->suiv=NULL;


    if(l->head==NULL){
        l->head=element;

    }
    if (l->tail==NULL){
        l->tail= element;
    }
    else{
        l->tail->suiv=element;
    }
    l->tail=element;

}

void aller_debut (Liste* l) //positionne le courant au début de la liste
{
    
    l->current=l->head;
}
void avancer (Liste *l) //fait avancer le courant dans la liste
{
    
    if (l->current != NULL){
   (l->current)=(l->current->suiv);}


}
int fin (Liste *l) //renvoie 1 si le courant est à la fin de la liste, renvoie 0 sinon
{
    int valeur;
    if ((l->current->suiv)=NULL) {
        valeur=1;
    }
    else{
        valeur=0;
    } 
    return valeur;   
}
void swap(Elt* a, Elt* b){ // untested
    Elt *temp = malloc(sizeof(temp));
    memcpy(temp,a,sizeof(a));
    a=b;
    b=temp;
    free(temp);
    }

Coureur* current_coureur(Liste *l){//untested
 return l->current->c;
}
void erase_current(Liste *l){
Elt* tampon= malloc(sizeof(Elt));
tampon= l->head;
if (l->current == l->head){  //si le courant est au début de la liste,
    l->head=l->head->suiv;
    l->current=l->head; //le pointeur pointe sur le nouveau 1er de la liste
}
else if (l->current == l->tail){ //si le courant est à la fin de la liste

    while (tampon->suiv != l->current){
        tampon=tampon->suiv;
    }
    tampon->suiv=NULL;
    l->tail=tampon;
    l->current = l->tail;
}

else{
     while (tampon->suiv != l->current){
        tampon=tampon->suiv;
    }
    tampon->suiv=l->current->suiv;
    l->current=tampon->suiv; //le courant est positionne juste apres celui efface
    }
}


void sort(Liste *l){//untested
    int swapped=1;
    l->current=l->head;
    while(swapped){
        swapped = 0;
        while((l->current != l->tail) && (l->current->suiv != NULL)){
            if (l->current->c->time < l->current->suiv->c->time){
                swap(l->current,l->current->suiv);
                swapped = 1;
            }
            l->current=l->current->suiv;
        }
    }
    }

void display(Liste * l){

    aller_debut(l);
    if (l->head == NULL)
    {
    printf("La liste est vide\r\n");
    }
    else 
    {
        while (l->current != NULL) {

            afficher_coureur (*(current_coureur(l)));
            avancer(l);
           
        } 
    
    }
}

