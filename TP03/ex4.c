#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(void){

    pid_t pid = fork();  
    //int p; //alinea a


    if(pid == -1){ //Erro
        perror("fork");
        return 1;
    }
    else if(pid == 0){ //filho
        //printf("Hello"); //alinea a
        printf("world!\n"); //alinea b

    }
    else{ //pai
        //wait(&p); //alinea a
        //printf("world !"); //alinea a
        printf("Hello "); //alinea b
    }

    return 0;
}