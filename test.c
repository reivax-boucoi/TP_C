#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "include/coureur.h"
#include "include/liste.h"
#include "include/coureur.h"
int NBETAPES=1;
#define NBTEAM 22

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
			char* tm1= malloc(sizeof(char)*50);
			t[j].name=malloc(sizeof(char)*50);
			strcpy(t[j].name,tm);//add team name to team list
			t[j].nb_c=0;
			t[j].time=0;
			strcpy(tm1,tm);
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
		printf("Success parsing\r\n");
		return l;
	}
}
//returns random etape time
int getEtapeTime(void){
	/*struct timeval tv ;
	gettimeofday(&tv, NULL) ;
	srand(tv.tv_usec) ;*/
	return (3000+(int)(1000.0*(float)rand()/(float)RAND_MAX));//returns values between 2000 and 4000, with an average of 3000
}
//returns if doped
int dope(float pct){
	/*struct timeval tv ;
	gettimeofday(&tv, NULL) ;
	srand(tv.tv_usec) ;*/
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


	Coureur *c=creer_coureur("Patrick","Tounsi",12,"Elec",6875,0);
	Coureur *x=creer_coureur("Xavier","Bourlot",35,"Fablab",3758,1);
	Coureur *p=creer_coureur("Popo","Combes",35,"France",3698,2);
	Coureur *l=creer_coureur("Lea","Cot",35,"signal",0,3);
	
	printf("\r\nTest function afficher_coureur :\r\n\r\n");
	afficher_coureur(*c);
	printf("\r\nEnd Test function afficher_coureur\r\n");
	Liste* test = init();
	
	printf("\r\nTest function ajouter_temps :\r\n\r\n");
	afficher_coureur(*l);
	ajouter_temps(l,500000);
	afficher_coureur(*l);
	printf("\r\nEnd Test function ajouter_temps\r\n");

	printf("\r\nTest function add_coureur :\r\n\r\n");
	display(test);
	add_coureur(test,c);
	display(test);
	printf("\r\nEnd Test function add_coureur\r\n");

	add_coureur(test,x);
	add_coureur(test,p);
	add_coureur(test,l);
	
	printf("\r\nTest function swap\r\n\r\n");
	display(test);
	swap(test->head,test->tail);
	printf("Result : \r\n");
	display(test);
	printf("\r\nEnd Test function swap\r\n");
	
	printf("\r\nTest function sort\r\n\r\n");
	sort(test);
	display(test);

	printf("\r\nTest function erase\r\n\r\n");
	test->current= test->head->suiv;
	erase_current(test);
	erase_current(test);
	display(test);
	printf("\r\nEnd Test function erase\r\n");
	return 0;


}
