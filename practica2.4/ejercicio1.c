#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	int fd[2];
	if(pipe(fd)== -1){
		perror("Error pipe");
	}
	
	pid_t pid = fork();
	
	switch(pid){
	case 0://Hijo
		dup2(fd[0],0);//Recibe	
		close(fd[0]);
		//close(fd[1]);
		//printf(argv[2]);
		//system(argv[2]);
		//execlp(argv[3], argv[3],argv[4]);
	break;
	case -1://Error
		perror("Error Fork");
		exit(1);
	break;
	default://Padre
		dup2(fd[1],1);//Envia
		//close(fd[0]);
		close(fd[1]);
		//system(argv[1]);
		execvp(argv[1],argv+1);
	break;
	
	}
	

return 0;
}
