#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]){
	if(argc < 1){
		perror("Falta argumentos");
		exit(1);
	}
	int fd =open("pipeprueba", O_WRONLY);
	write(fd, argv[1], strlen(argv[1]));
	close(fd);
return 0;
}
