#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "include/coureur.h"
#include "include/liste.h"
#include "include/coureur.h"

#define NBETAPES 10

Liste * parse (char* fileName){
  Liste *l=init();
  char* str = malloc(sizeof(char)*50);
  char* team= malloc(sizeof(char)*50);
  FILE* a=fopen(fileName,"r");
  if(a==NULL){
    printf("Issue opening file !\r\n");
    return -1;
  }
  while(fgets(team,100,a)){  //get team name  
    for(int i=0;i<5;i++){
        fgets(str,100,a);//get runner details
        int nb;
        char* name =malloc(sizeof(char)*20);
        char* surname = malloc(sizeof(char)*20);
        sscanf(str,"%d,%[^,],%s\r\n",&nb,name,surname);
         
        Coureur *c=malloc(sizeof(Coureur));
        c=creer_coureur(name,surname,nb,team,0);
        add_coureur(l,c);
        //printf("Name %s Surname %s Dossard %d\r\n",name,surname,nb); //for debug only
        //afficher_coureur(*c);//for debug only
        //afficher_coureur(*(l->tail->c));//for debug only
    }
  }
    free(team);
    free(str);
    display(l);
    
    return l;
    }
int getEtapeTime(void){
    return (200+(int)(100.0*(float)rand()/(float)RAND_MAX));//returns values between 100 and 300, with an average of 200
}
int dope(float pct){
    return ((float)rand()/(float)RAND_MAX)<pct ? 1 : 0;//returns
}

int main(void){
   
  // TEST DE COUREUR.C => ok

  /* Coureur *c=creer_coureur("Patrick","Tounsi",12,"Elec",0);
     Coureur *p=creer_coureur("Popo","Combes",35,"France",0);
     afficher_coureur(*c);
     afficher_coureur(*p);
     ajouter_temps(c,120);
     afficher_coureur(*c);*/
  
/*

    Liste* test = init();

    add_coureur(test,c);
    display(*test);
    add_coureur(test,p);
    sort(test);
    display(*test);
    erase_current(test);
    display(*test);
*/
/*        printf("Finished preliminary testing\r\n");

    Liste* l=parse("fichier_coureurs.txt");
    display(*l);
    l->current=l->head;
    

    afficher_coureur(*(l->head->c));
    afficher_coureur(*(l->head->suiv->c));
    afficher_coureur(*(l->tail->c));
    
    for(int i=0;i<NBETAPES;i++){
        printf("Etape %d\r\n",i+1);
        while(l->current != NULL){
            ajouter_temps(l->current->c,getEtapeTime());
            if(dope(0.01)){
                printf("\t%s %s est dope !\r\n",l->current->c->name,l->current->c->surname);
                erase_current(l);
            }else{
                l->current=l->current->suiv;
            }
        }
        l->current=l->head;
        sort(l);
    }
    
    display(*l);
    afficher_coureur(*(l->head->c));
    afficher_coureur(*(l->head->suiv->c));
    afficher_coureur(*(l->tail->c));

*/
//TEST DE LISTE.C TOUT MARCHE SAUF SORT
  Coureur *c=creer_coureur("Patrick","Tounsi",12,"Elec",875);
  Coureur *x=creer_coureur("Xavier","Bourlot",35,"Fablab",3758);
  Coureur *p=creer_coureur("Popo","Combes",35,"France",3698);
  Coureur *l=creer_coureur("Lea","Cot",35,"signal",698);
  //afficher_coureur(*c);
  Liste* test = init();
 
  add_coureur(test,c);
  //display(test);
 add_coureur(test,x);
 add_coureur(test,p);
  add_coureur(test,l);
  //display(test);
  //sort(test);
  test->current= test->head->suiv;
  erase_current(test);
  erase_current(test);
  display(test);
  return 0;
  //TODO later
  //for each runner
  //if part of a new team
    //create team
  //else
    //find runners'team
  //accumulate time
  //add 1 runner
 
}
