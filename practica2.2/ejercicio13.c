#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	if(argc < 2){
		exit(1);
	}

	int fd = open(argv[1], O_RDWR|O_CREAT, 0555);

	if(fd == -1){
		exit(1);
	}
	
	//Redirigimos a fd2 la salida estandar
	int fd2 = dup2(fd, 1);
	//Redirigimos a fd3 la salida error
	int fd3 = dup2(fd, 2);
	printf("Ha sido redirigido a  %s\n", argv[1]);

	char* error;
	if(setuid(0) == -1){
		perror(error);
	}
	dup2(fd2, fd);
  	dup2(fd3, fd);
return 0;

}
