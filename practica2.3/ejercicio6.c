#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

void imprimir(){
		printf("Id del proceso: %i\n", getpid());
                printf("Id del padre: %i\n", getppid());
                printf("Id del grupo: %i\n",getpgid(getpid()));
                printf("Id de la sesion: %i\n", getsid(getpid()));

                struct rlimit limite;
                if(getrlimit(RLIMIT_NOFILE, &limite)==-1){
                perror("Error");
                exit(1);
                }

                printf("Numero maximo de ficheros: %d\n",limite.rlim_max);

                char buffer[512];
                printf("El directorio actual es: %s\n", getcwd(buffer,-1));



}
int main(){
	
	pid_t id = fork();

	switch(id){//Hijo
	case -1:
		perror("Error fork()");//Padre
		exit(1);
	break;
	case 0: 
		printf("[Padre]");
                imprimir();
		//sleep(3);
	break;
	default:
		//Crear session
		setsid();
		//Cambiar directorio
		if(chdir("/tmp")== -1){
			perror("Error: cambiar directorio trabajo");
		}
		printf("[Hijo]");	
		imprimir();
		sleep(3);	
	break;
	}
return 1;
}
