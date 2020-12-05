#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	printf("El id real es %d\n", getuid());
        printf("El id efectivo es %d\n", geteuid());

return 1;
}
