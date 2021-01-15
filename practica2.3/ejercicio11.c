#include <stdlib.h>
#include <signal.h>
#include <stdio.h>


int main(){
	sigset_t blk_set;
	
	sigemptyset(&blk_set);
	sigaddset(&blk_set, SIGINT);
	sigaddset(&blk_set, SIGTSTP);

	sigprocmask(SIG_BLOCK, &blk_set,NULL);
	
	//Obtener variable del entorno
	char *sleep_secs = getenv("SLEEP_SECS");
	int secs = atoi(sleep_secs);

	printf("El proceso se dormira durante: %d segundos\n", secs);
	sleep(secs);
	//Señales pendientes
	sigset_t pendientes;
	sigpending(&pendientes);
	//Comprobamos  si la señal ha llegado
	if(sigismember(&pendientes, SIGINT)== 1){//SEÑAL SIGINT
		printf("Se recibio la señal SIGINT\n");
		sigdelset(&blk_set, SIGINT);
	}else{
		printf("No se recibio la señal SIGINT\n");
	}
	if(sigismember(&pendientes, SIGTSTP)== 1){//SEÑAL SIGTSTP
                printf("Se recibio la señal SIGTSTP\n");
                sigdelset(&blk_set, SIGTSTP);
        }else{
                printf("No se recibio la señal SIGTSTP\n");
        }

	sigprocmask(SIG_UNBLOCK, &blk_set, NULL);

return 0;
}
