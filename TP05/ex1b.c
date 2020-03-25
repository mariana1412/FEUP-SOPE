
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define READ    0
#define WRITE   1

struct numbers{
    int x;
    int y;
};


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
        struct numbers numbers;

        printf("Please insert two numbers (x y): ");
        scanf("%d %d", &numbers.x, &numbers.y);

        close(fd[READ]);
        write(fd[WRITE], &numbers, sizeof(numbers));

        close(fd[WRITE]);
    }
    else { //processo-filho
        struct numbers numbers;

        close(fd[WRITE]);
        read(fd[READ], &numbers, sizeof(numbers));

        int aux;

        aux = numbers.x+numbers.y;
        printf("%d + %d = %d\n", numbers.x, numbers.y, aux);

        aux = numbers.x - numbers.y;
        printf("%d - %d = %d\n", numbers.x, numbers.y, aux);

        aux = numbers.x * numbers.y;
        printf("%d * %d = %d\n", numbers.x, numbers.y, aux);

        if(numbers.y == 0)
            printf("Error: Division by 0 is undefined.\n");

        else {
            float aux1 = (float)numbers.x / (float)numbers.y;
            printf("%d / %d = %f\n", numbers.x, numbers.y, aux1);
        }

        close(fd[READ]);
    }

    return 0;
}