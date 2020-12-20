#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	
	
	int fd = open("hola.txt", O_CREAT|O_WRONLY,0777);
	
	if(lockf(fd, F_TLOCK, 0)!=-1){//Si no está bloqueado bloquea
		write(fd, "Hola mundo", 10);
		if(lockf(fd, F_TEST,0)==0){
                	printf("Desbloqueado");
        	}else{
                	printf("Bloqueado");
       		}
		sleep(3);	
		lockf(fd, F_ULOCK,0);
	}	

return 1;
}
