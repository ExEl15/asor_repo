#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
int main(){
	time_t t;
        struct tm *st;
        char buffer[100];
        time(&t);

        st = localtime(&t);

        strftime(buffer, 100, "%A, %d de %B de %Y, %H:%M", st);

        printf(buffer);

return 1;
}
