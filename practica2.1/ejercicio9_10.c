#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(){


	printf("El id real es %d\n", getuid());
        printf("El id efectivo es %d\n", geteuid());

        struct passwd *data;
        if((data = getpwuid(getuid()))!= NULL){
                printf("Nombre del usuario %s \n",data->pw_name);
                printf("Descripción del usuario %s \n",data->pw_gecos);
                printf("Nombre del directorio %s \n",data->pw_dir);

        }else{
              	perror("Error");
        }
return 1;
}

