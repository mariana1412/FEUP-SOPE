#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void sigint_handler(int signo) {
    printf("In SIGINT handler ...\n");
}


int main(void) {

    struct sigaction action;
    action.sa_handler = sigint_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;


    if (sigaction(SIGINT, &action, NULL) < 0) { //sigaction permite examinar e/ou modificar a ação associada associada a um sinal
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(1);
    }

    
    int sec = 30;
    printf("Sleeping for 30 seconds ...\n");
    sec = sleep(sec); 


    while(sec != 0){
        printf("%d\n", sec); 
        sec = sleep(sec);
    }

    printf("Waking up ...\n");
    exit(0);
} 