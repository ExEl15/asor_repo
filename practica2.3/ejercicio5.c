#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
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
	

return 1;
}
