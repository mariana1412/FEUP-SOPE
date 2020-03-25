
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define READ    0
#define WRITE   1

struct Data{
    int numI;
    float numF;
    int type[2]; //type[0] indica se é um numero valido ou não, type[1] indica se é inteiro ou não
};

int main(void){

    int fd[2], fd1[2];
    pid_t pid;
    
    if(pipe(fd) == -1 || (pipe(fd1) == -1)){
        fprintf(stderr, "Pipe error");
        exit(1);
    }

    
    pid = fork();

    if(pid < 0){
        fprintf(stderr, "Fork error");
        exit(1);
    }
    else if(pid > 0){ //processo-pai
        int al[2];
        struct Data operations[4]; 

        printf("Please insert two numbers (x y): ");
        scanf("%d %d", &al[0], &al[1]);

        close(fd[READ]);
        write(fd[WRITE], al, sizeof(al));
        close(fd[WRITE]);
        
        close(fd1[WRITE]);
        read(fd1[READ], operations, sizeof(operations));

        if(operations[0].type[0] && operations[0].type[1]){
            printf("%d + %d = %d\n", al[0], al[1], operations[0].numI);
        }

        if(operations[1].type[0] && operations[1].type[1]){
            printf("%d - %d = %d\n", al[0], al[1], operations[1].numI);
        }

        if(operations[2].type[0] && operations[2].type[1]){
            printf("%d * %d = %d\n", al[0], al[1], operations[2].numI);
        }

        if(operations[3].type[0] && !operations[3].type[1]){
            printf("%d / %d = %f\n", al[0], al[1], operations[3].numF);
        }
        else if(!operations[3].type[0])
            printf("Error: Division by 0 is undefined.\n");        

        close(fd1[READ]);
    }
    else { //processo-filho
        int al[2];

        close(fd[WRITE]);
        read(fd[READ], al, sizeof(al));

        struct Data aux;
        struct Data operations[4]; 
        
        
        aux.numI = al[0] + al[1];
        aux.type[0] = 1;
        aux.type[1] = 1;
        operations[0] = aux;

        aux.numI = al[0] - al[1];
        aux.type[0] = 1;
        aux.type[1] = 1;
        operations[1] = aux;
        
        aux.numI = al[0] * al[1];
        aux.type[0] = 1;
        aux.type[1] = 1;
        operations[2] = aux;
        
      

        if(al[1] == 0){
            aux.numF = 0;
            aux.numI = 0;
            aux.type[0] = 0;
            operations[3] = aux;
        }
        else {
            aux.numF = (float)al[0] / (float)al[1];
            aux.type[0] = 1;
            aux.type[1] = 0;
            operations[3] = aux;
        }

        close(fd[READ]);
        write(fd1[WRITE], operations, sizeof(operations));
        close(fd1[WRITE]);
    }

    return 0;
}