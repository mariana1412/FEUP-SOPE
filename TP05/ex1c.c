
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define READ    0
#define WRITE   1

int main(void){

    int fd[2];
    pid_t pid;
    
    if(pipe(fd) == -1){
        fprintf(stderr, "Pipe error");
        exit(1);
    }

    
    pid = fork();

    if(pid < 0){
        fprintf(stderr, "Fork error");
        exit(1);
    }
    else if(pid > 0){ //processo-pai
        char al[2][10];

        printf("Please insert two numbers (x y): ");
        scanf("%s %s", al[0], al[1]);

        close(fd[READ]);
        write(fd[WRITE], al, sizeof(al));

        close(fd[WRITE]);
    }
    else { //processo-filho
        char al[2][10];

        close(fd[WRITE]);
        read(fd[READ], al, sizeof(al));

        int aux;

        aux = atoi(al[0])+atoi(al[1]);
        printf("%s + %s = %d\n", al[0], al[1], aux);

        aux = atoi(al[0]) - atoi(al[1]);
        printf("%s - %s = %d\n", al[0], al[1], aux);

        aux = atoi(al[0]) * atoi(al[1]);
        printf("%s * %s = %d\n", al[0], al[1], aux);

        if(atoi(al[1]) == 0)
            printf("Error: Division by 0 is undefined.\n");

        else {
            float aux1 = (float)atoi(al[0]) / (float)atoi(al[1]);
            printf("%s / %s = %f\n", al[0], al[1], aux1);
        }

        close(fd[READ]);
    }

    return 0;
}