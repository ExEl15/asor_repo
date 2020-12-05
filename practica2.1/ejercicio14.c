#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
int main(){
	time_t t;
        struct tm *st;

        time(&t);

        st = localtime(&t);

        printf("Horas %ld\n", st->tm_hour);


return 1;
}

