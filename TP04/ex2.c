#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void sigint_handler(int signo){

    printf("Entering SIGINT handler ...\n");
    sleep(10);
    printf("Exiting SIGINT handler ...\n");

} 

void sigterm_handler(int signo){

    printf("Entering SIGTERM handler ...\n");
    sleep(10);
    printf("Exiting SIGTERM handler ...\n");

} 

int main(void){

    struct sigaction action;
    action.sa_handler = sigint_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;


    if (sigaction(SIGINT, &action, NULL) < 0){
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(1);
    }

    if (sigaction(SIGTERM, &action, NULL) < 0){
        fprintf(stderr, "Unable to install SIGTERM handler\n");
        exit(2);
    }


    printf("Try me with CTRL-C ...\n");

    while(1)
        pause();

    exit(0);

} 

//alinea a --> o ctrl-C só é detetado uma vez a cada dez segundos já que na função que é chamada quando há um sinal SIGINT, existe um sleep(10) o que fará
//com que o programa adormeça por 10 segundos, ignorando qualquer ctrl-C.

//alinea b --> "ps -u" seguida de "kill [pid]", envia o sinal SIGTERM ao processo fazendo com que ele termine
