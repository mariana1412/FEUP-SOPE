#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void sigint_handler(int signo) {
    printf("In SIGINT handler ...\n");
}


int main(void) {

    if (signal(SIGINT, sigint_handler) < 0) { 
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(1);
    }

    int sec = 30;

    printf("Sleeping for 30 seconds ...\n");
    sec = sleep(sec); //suspende o processo até que se passem 30 segundos ou até que um sinal seja recebido pelo processo e o signal handler retorne

    //alinea b
    while(sec != 0){
        printf("%d\n", sec); //só acontece se houver interrupção de um sinal
        sec = sleep(sec);
    }

    printf("Waking up ...\n");
    exit(0);
} 

/*alinea a -> se for enviado o sinal SIGINT (ctrl-C), é chamada a função sigint_handler e o programa "acorda". Nesta situação, o programa termina com exit code 0.
é isto que se vê no terminal:

    Sleeping for 30 seconds ...
    ^CIn SIGINT handler ...
    Waking up ...

se for enviado outro sinal, o programa termina abruptamente com exit code diferente de 0. 
por exemplo, fazendo "kill -SIGUSR1 {pid}+" num novo terminal, o programa termina com o exit code 138.

//alinea b -> se os segundos de sleep() passarem, a função retorna 0; caso seja interrompida por um sinal, a função retorna o nº de segundos que faltavam
*/