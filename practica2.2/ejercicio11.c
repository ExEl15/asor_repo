#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv []){
	if(argc< 2){
		perror("No hay suficientes argumentos");
	}
	
	if(link(argv[1], "/home/cursoredes/enlaceS.sym")==-1){
		perror("Ruta invalida");
	}
	 if(symlink(argv[1], "/home/cursoredes/enlaceR.hard")==-1){
                perror("Ruta invalida");
        }



return 0;
}
