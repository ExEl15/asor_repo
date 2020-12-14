#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	if(open("prueba.txt",O_CREAT|O_WRONLY, 0645) == -1){
		exit(0);
	}
	
return 0;
}
