#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main(){
    int i = 0;
    for(i; i < 255; i++){
        errno = i;
        printf("%d:", errno);
        perror("");
        printf("\n");
     }
return 1;
}
