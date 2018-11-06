#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <sys/time.h>
#include "include/liste.h"
#include "include/coureur.h"

int NBETAPES=1;
int NBTEAM=1;

struct Team{
char* name;
int time;
int nb_c;
};
typedef struct Team Team;

Liste * parse (char* fileName,Team* teamTable){
  Liste *l=init();
  int j=0;
  char* str = malloc(sizeof(char)*50);
  char* tm= malloc(sizeof(char)*50);
  FILE* a=fopen(fileName,"r");
  if(a==NULL){
    printf("Issue opening file !\r\n");
    return ;
  }
	fgets(tm,100,a);
	NBETAPES=atoi(tm);
	fgets(tm,100,a);
	NBTEAM=atoi(tm);
  	Team* t=calloc(NBTEAM,sizeof(Team));

	printf("%d",NBETAPES);
  	while(fgets(tm,100,a)){  //get team name  
	char* tm1= malloc(sizeof(char)*50);
	memcpy(tm1,tm,sizeof(tm));
	memcpy(t[j].name,tm,sizeof(tm));
	t[j].time=0;
	t[j].nb_c=0;
    for(int i=0;i<5;i++){
        fgets(str,100,a);//get runner details
        int nb;
        char* name =malloc(sizeof(char)*20);
        char* surname = malloc(sizeof(char)*20);
        sscanf(str,"%d,%[^,],%s\r\n",&nb,name,surname);
         
        Coureur *c=malloc(sizeof(Coureur));
        c=creer_coureur(name,surname,nb,tm1,0);
        add_coureur(l,c);

		t[j].nb_c++;
    }
	j++;
  }
	free(tm);
    free(str);
    teamTable=t;
    return l;
}

int getEtapeTime(void){
	struct timeval tv ;
	gettimeofday(&tv, NULL) ;
	srand(tv.tv_usec) ;
    return (3000+(int)(1000.0*(float)rand()/(float)RAND_MAX));//returns values between 2000 and 4000, with an average of 3000
}
int dope(float pct){
	struct timeval tv ;
	gettimeofday(&tv, NULL) ;
	srand(tv.tv_usec) ;
    return ((float)rand()/(float)RAND_MAX)<pct ? 1 : 0;//returns
}

int main(void){
   Team *t;
    Liste* l=parse("fichier_coureurs.txt",t);

    
    for(int i=0;i<NBETAPES;i++){
    	aller_debut(l);
        printf("Etape %d\r\n",i+1);
        while(l->current != NULL){
            ajouter_temps(l->current->c,getEtapeTime());
            if(dope(0.05)){
                printf("\t%s %s est dope !\r\n",l->current->c->name,l->current->c->surname);
                erase_current(l);
            }else{
                avancer(l);
            }
        }
        sort(l);
		//display(l);
    }
    printf("Fin de la course, classement final :\r\n");
    display(l);
	

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
