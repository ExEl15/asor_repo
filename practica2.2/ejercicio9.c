#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(){
	struct stat buf;
	if(stat("prueba.txt",&buf) == -1){
	 	printf("error");
		exit(0);
	}else{
		printf("Mayor y minor: %ld, %ld\n",major(buf.st_dev), minor(buf.st_dev));
		printf("I-nodo: %ld\n",buf.st_ino);
		 printf("File type:");

           switch (buf.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }

		printf("Ultimo acceso:%s\n",ctime(&buf.st_atime));
	
	}	
	
	


return 0;
}
