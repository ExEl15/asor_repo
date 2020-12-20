#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv []){
	
	if(link(argv[1], "/home/cursoredes/enlaceS.sym")==-1){
		exit(1);
	}
	 if(symlink(argv[1], "/home/cursoredes/enlaceR.hard")==-1){
                exit(1);
        }



return 0;
}
