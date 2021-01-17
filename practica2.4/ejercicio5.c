#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>

int main(int argc, char *argv[]){
	
	//Abrimos las dos tuberias
	int pipe1 =open("pipeprueba", O_RDONLY|O_NONBLOCK);
	char *tuberia = "tuberia2";
	mkfifo(tuberia, 0644);
	int pipe2 = open(tuberia, O_RDONLY| O_NONBLOCK);
	ssize_t size = 256;
	char buffer[size];
	int cambios = 0; 
	int pipeAct;
	
	
	while(cambios != -1){
		fd_set set;

    		FD_ZERO(&set);
		FD_SET(pipe1, &set);
		FD_SET(pipe2, &set);
	
		int nPipe;
	
		cambios = select((pipe1 < pipe2) ? pipe2 + 1 : pipe1 + 1, &set, NULL,NULL,NULL);
		
		if(cambios > 0){
			//Buscamos en que pipe estamos
			if(FD_ISSET(pipe1, &set)){
				nPipe = 1;
				pipeAct = pipe1;		
			}else if(FD_ISSET(pipe2, &set)){
				nPipe= 2;
				pipeAct = pipe2;
			}
		
			
		size = read(pipeAct,buffer,256);
		buffer[size] = '\0';
		printf("Tuberia: %d, mensaje: %s", nPipe, buffer);
			
		//Cerramos y abrimos las tuberias
		if(size != 256 && pipeAct == pipe1){
			close(pipe1);
			pipe1 = open("pipeprueba", O_RDONLY|O_NONBLOCK); 
		}else if(size != 256 && pipeAct == pipe2){
			close(pipe2);
                	pipe2 = open(tuberia, O_RDONLY| O_NONBLOCK);
		}

		}//cambios 
	}//while
	
	close(pipe1);
	close(pipe2);
return 0;
}
