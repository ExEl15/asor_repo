#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define P_W 1
#define P_R 0

int main(int argc, char *argv[]){
	int p_h[2];
	int h_p[2];
	
	pipe(p_h);
	pipe(h_p);
	
	pid_t pid = fork();
	
	switch(pid){
	case 0://Hijo
		close(p_h[P_W]);close(h_p[P_R]);
		char mensajePadre[255];
		char flag = 'l';
		int i = 0;
		for(i; i<10;i++){
			ssize_t size = read(p_h[P_R], &mensajePadre, 255);
			printf("[HIJO]He recibido el mensaje: %s\n",mensajePadre);
			if(i == 9)flag ='q';
			sleep(2);
			write(h_p[P_W],&flag, 1);
		}	
		close(p_h[P_R]);close(h_p[P_W]);
	break;
	case -1://Error
		perror("Error Fork");
		exit(1);
	break;
	default://Padre
		close(p_h[P_R]);close(h_p[P_W]);
		char mensaje[255];
		char stop = 'l';
		while(stop != 'q'){
			printf("[Padre] Escriba un mensaje:\n");
			ssize_t size = read(0, &mensaje, 255);	
			mensaje[size] = '\0';
			write(p_h[P_W], &mensaje, 255);
			read(h_p[P_R], &stop, 255);
		}
		close(p_h[P_W]);close(h_p[P_R]);
	
	break;
	
	}
	

return 0;
}
