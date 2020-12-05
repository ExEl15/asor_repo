#include <sys/utsname.h>
#include <stdlib.h>
#include <stdio.h>


int main(){
        struct utsname data;


        if(uname(&data)== -1){
                exit(0);
        }

        printf("%s\n", data.sysname);
        printf("%s\n", data.nodename);
        printf("%s\n", data.release);
        printf("%s\n", data.version);
        printf("%s\n", data.machine);
        //printf("%s", data.domainname);        

        return 1;
}
