#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
int main(){

	struct timeval before;
        struct timeval after;
        int i = 0;
        int v = 0;

        gettimeofday(&before,NULL);

        for(i = 0;i< 1000000;i++){
                v++;
        }

	gettimeofday(&after, NULL);

        suseconds_t final = after.tv_usec - before.tv_usec;

        printf("Microsegundos %ld\n", final);


return 1;
}

