#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(void){

    pid_t pid;
    int i, j, status;

    printf("I'm process %d. My parent is %d.\n", getpid(),getppid());

    for (i=1; i<=3; i++) {
        pid = fork();
        if ( pid < 0) {
            printf("fork error");
            exit(1);
            }
        else if (pid == 0) {
            printf("I'm process %d. My parent is %d. I'm going to work for 1 second ...\n", getpid(),getppid());
            sleep(1); // simulando o trabalho do filho
            printf("I'm process %d. My parent is %d. I finished my work\n", getpid(),getppid());
            exit(0);
        }
        else
        // a eliminar na alinea c)
        // simulando o trabalho do pai
            for (j=1; j<=10; j++) {
                sleep(1);
                waitpid(-1, &status, WNOHANG); //pid == -1 --> espera por um filho qualquer; options == WNOHANG --> waitpid não bloqueia se o filho especificado por pid não estiver imediatamente disponível
                printf("father working ...\n");
            }
    }

    exit(0);
}