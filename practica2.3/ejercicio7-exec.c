#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	
	if(argc > 1){
		execvp(argv[1], argv+1); //Si esto se ha ejecutado lo de abajo no se ejecuta
		perror("Error exec");
	}
	
	printf("Se ha terminado la ejecucion");


return 0;
}
