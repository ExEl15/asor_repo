#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

volatile int borrar = 0;


void handler(int senial){
	if(senial == SIGUSR1)  borrar=1;
}
int main(int argc, char *argv[]){
	if(argc < 1){
		perror("Especifique los segundos");
		exit(1);
	}

	char *sleep_secs = getenv("SLEEP_SECS");
	int secs_sleep = atoi(sleep_secs);

	//sigset_t set;
	//sigemptyset(&set);

	struct sigaction act;
	sigaction(SIGUSR1, NULL, &act);
	act.sa_handler = handler;
	sigaction(SIGUSR1, &act, NULL);
	int i = 0;
	while(i<secs_sleep && borrar == 0){
		i++;
		sleep(1);
	}
	
	
	if(borrar == 0){
		printf("La señal no ha llegado a tiempo se va a eliminar el programa en 3...2...1\n");
		unlink(argv[0]);
	}else{
		printf("La señal ha llegado a tiempo\n");
	}

return 0;
}
