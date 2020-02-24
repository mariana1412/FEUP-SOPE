#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/times.h>

int main(int argc, char *argv[]){


    int n = atoi(argv[2]), max = atoi(argv[1]), number = max, counter = 0;

    clock_t start, end;
    struct tms t;
    long ticks;
    start = times(&t); /* início da medição de tempo */
    ticks = sysconf(_SC_CLK_TCK);

    srand((unsigned)time(NULL));

    while(number != n){
        counter++;
        number = rand() % max;
        printf("%d. Number = %d\n", counter, number);
    }

    printf("\nClock ticks per second: %ld\n", ticks);

    end = times(&t); /* fim da medição de tempo */

    printf("Clock:                %4.2f s\n", (double)(end-start)/ticks);  
    printf("User time:            %4.2f s\n", (double)t.tms_utime/ticks);
    printf("System time:          %4.2f s\n", (double)t.tms_stime/ticks);
    printf("Children user time:   %4.2f s\n", (double)t.tms_cutime/ticks);
    printf("Children system time: %4.2f s\n", (double)t.tms_cstime/ticks); 


    return 0;

}