#include <stdio.h>
#include <unistd.h>

int main(){

	printf("La longitud  maxima de argumentos es %d\n",sysconf(_SC_ARG_MAX));
        printf("El numero maximo de hijos por proceso es %d\n", sysconf(_SC_CHILD_MAX));
        printf("El numero maximo de ficheros por proceso es %d\n", sysconf(_SC_OPEN_MAX));

return 1;
}
