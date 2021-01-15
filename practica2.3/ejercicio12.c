#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

volatile int sig_int = 0;
volatile int sig_tstp = 0;


void handler(int senial){
	if(senial == SIGINT) sig_int++;
	if(senial == SIGTSTP) sig_tstp++;
}

int main(){
	struct sigaction act;
	
	//Recuperamos el handler antiguo
	sigaction(SIGINT,NULL,  &act);
	act.sa_handler = handler;	
	sigaction(SIGINT,&act, NULL);
	
	sigaction(SIGTSTP,NULL,  &act);
        act.sa_handler = handler;
        sigaction(SIGTSTP,&act, NULL);
	
	sigset_t blk_set;
	sigemptyset(&blk_set);

	while(sig_int + sig_tstp < 10){
		//sigsuspend(&blk_set);
	}

	printf("La señal SIGINT ha aparecido: %i veces\n",sig_int);
	printf("La señal SIGTSTP ha aparecido: %i veces\n", sig_tstp);
	
return 0;
}
