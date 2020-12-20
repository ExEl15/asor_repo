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

	int fd = open(argv[1], O_RDWR|O_CREAT, 0777);

	if(fd == -1){
		exit(1);
	}
	
	//Redirigimos a fd2 la salida estandar
	int fd2 = dup2(fd, 1);

	printf("Ha sido redirigido a  %s\n", argv[1]);

	
  	dup2(fd2, fd);
return 0;

}
