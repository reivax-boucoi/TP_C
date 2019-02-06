#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <sys/time.h>
#include "include/liste.h"
#include "include/coureur.h"

int NBETAPES=0;
#define NBTEAM 22
#define DOPE_RATE 0.01

struct Team{
	char* name;
	int time;
	int nb_c;
}t[22];
typedef struct Team Team;

//recupere les coureurs et les equipes du fichier texte
Liste * parse (char* fileName){
	Liste *l=init();
	int j=0;
	char* str = malloc(sizeof(char)*50);
	char* tm= malloc(sizeof(char)*50);
	FILE* a=fopen(fileName,"r");//fichier contenant les coureurs, les nb etapes et nb team
	if(a==NULL){
		printf("Issue opening file !\r\n");
	}else{
	fgets(tm,100,a);//get etape number
	NBETAPES=atoi(tm);
	fgets(tm,100,a);//get team number
	
	printf("NBETAPES : %d\r\n",NBETAPES);
	
	while(fgets(tm,100,a)){  //get team name  
		char* tm1= malloc(strlen(tm));
		t[j].name=malloc(strlen(tm));
        
        memcpy(t[j].name,tm,strlen(tm)-1);//add team name to team list
		t[j].nb_c=0;
		t[j].time=0;
        memcpy(tm1,tm,strlen(tm)-1);
		for(int i=0;i<5;i++){
			fgets(str,100,a);//get runner details
			int nb;
			char* name =malloc(sizeof(char)*20);
			char* surname = malloc(sizeof(char)*20);
			sscanf(str,"%d,%[^,],%s\r\n",&nb,name,surname);//get name, surname and dossard
			
			Coureur *c=malloc(sizeof(Coureur));
			c=creer_coureur(name,surname,nb,tm1,0,j);//create coureur
			add_coureur(l,c);
			t[j].nb_c++;//add coureur to team
		}
		j++;
	}
	free(tm);
	free(str);
    free(a);
	printf("Success parsing file !\r\n");
	return l;
	}
}
//returns random etape time
int getEtapeTime(void){
	struct timeval tv ;
	gettimeofday(&tv, NULL) ;
	srand(tv.tv_usec) ;
	return (3000+(int)(1000.0*(float)rand()/(float)RAND_MAX));//returns values between 2000 and 4000, with an average of 3000
}
//returns if doped
int dope(float pct){
	struct timeval tv ;
	gettimeofday(&tv, NULL) ;
	srand(tv.tv_usec) ;
	return ((float)rand()/(float)RAND_MAX)<pct ? 1 : 0;//returns
}
//affiche une equipe
void display_team(Team t){
	int heure= t.time/3600;
	int minute=(t.time % 3600) / 60;
	int seconde=(t.time % 3600) % 60;
	printf("Equipe %s nb_c : %d , Temps cumule: %d heures %d minutes %d secondes\r\n",t.name,t.nb_c,heure,minute,seconde);
}
int main(void){
	Liste* l=parse("fichier_coureurs.txt");
	printf("Debut de la course !\r\n");
	for(int i=0;i<NBETAPES;i++){//for each etape
		aller_debut(l);
		printf("Etape %d\r\n",i+1);
		while(l->current != NULL){//for each runner
			int time=getEtapeTime();
			ajouter_temps(l->current->c,time);//ajouter son temps d'etape
			t[l->current->c->nb_team].time+=time;
			if(dope(DOPE_RATE)){//if runner doped
				printf("\t%s %s est dope !\r\n",l->current->c->name,l->current->c->surname);
				t[l->current->c->nb_team].nb_c--;//enlever un coureur
				t[l->current->c->nb_team].time-=l->current->c->time;//enlever le temps des joureurs disqualifies
				printf("\t%d runner left in team %s\r\n",t[l->current->c->nb_team].nb_c,t[l->current->c->nb_team].name);
				erase_current(l);//remove runner from list
			}else{
				avancer(l);//next runner
			}
		}
		sort(l);
		//display(l); // To show intermediary classement steps, uncomment here <-----------------------------------------------------------
	}
	printf("Fin de la course, classement final coureurs:\r\n");
    
	display(l);
	
	printf("\r\nFin de la course, classement final equipes:\r\n");
	for(int j=0;j<NBTEAM-1;j++){//tri des equipes 
		for(int i=0;i<NBTEAM-1;i++){
			if(t[i].time>t[i+1].time){//tri sur le temps global des equipes
				Team temp=t[i+1];
				t[i+1]=t[i];
				t[i]=temp;
			}
		}
	}
	int i=1;
	for(int j=0;j<NBTEAM-1;j++){//affichage du classement
		if(t[j].nb_c>=3){//seules les equipes ayant plus de 3 coureurs sont classees
			printf("%d : ",i++);
			display_team(t[j]);
		}
	}

	return 0;
}
