#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int main(){

	time_t t;

        time(&t);

        printf("Segundos %ld\n",t);

return 1;
}

