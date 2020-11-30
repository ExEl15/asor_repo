#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <errno.h>
#include <string.h> 

int main(){
    if(setuid(0) == -1){
        printf("%d:", errno);
        perror("Error");
    }
    
return 1;
}   
