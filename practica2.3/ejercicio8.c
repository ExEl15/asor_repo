#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


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
int main(int argc, char* argv[]){
	
	pid_t id = fork();

	switch(id){//Hijo
	case -1:
		perror("Error fork()");//Padre
		exit(1);
	break;
	case 0: 
		//Crear session
		setsid();
		//Cambiar directorio
		if(chdir("/tmp")== -1){
			perror("Error: cambiar directorio trabajo");
		}
		printf("[Hijo]");	
		//imprimir();
		int fd = open("/tmp/daemon.out",O_CREAT|O_RDWR,0777);
		int er = open("/tmp/daemon.err",O_CREAT|O_RDWR, 0777);
		int null = open("/dev/null",O_CREAT|O_RDWR,0777);
		dup2(fd,2);
		dup2(er,1);
		dup2(null,0);

		//Exec
		if(argc > 1){
	       		execvp(argv[1], argv+1); //Si esto se ha ejecutado lo de abajo no se ejecuta
                	perror("Error exec");
        	}

		imprimir();
		//sleep(3);	
	break;
	default:
		printf("[Padre]");
                imprimir();
                //sleep(3);
        break;
	}
return 1;
}
