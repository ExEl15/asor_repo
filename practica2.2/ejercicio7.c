#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	umask(0027);
	
	if(open("prueba.txt",O_CREAT|O_WRONLY, 0645) == -1){
		exit(0);
	}

return 0;
}

