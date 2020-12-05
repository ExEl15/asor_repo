#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	int maxEnlaces = pathconf("/", _PC_LINK_MAX);
        int maxRuta = pathconf("/", _PC_PATH_MAX);
        int maxNombreF = pathconf("/", _PC_NAME_MAX);
        if(maxEnlaces == -1 || maxRuta == -1 || maxNombreF == -1){
                exit(1);
        }


	printf("El numero maximo de enlaces es %d\n", maxEnlaces);
        printf("La longitud maxima de ruta es %d\n", maxRuta);
        printf("La longitud maxima de nombre de fichero es %d\n", maxNombreF);

return 1;
}
     