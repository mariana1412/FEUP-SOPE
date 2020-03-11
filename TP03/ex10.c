#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <wait.h>


int main(int argc, char *argv[], char *envp[]) {

    pid_t pid;
    int status;

    if (argc != 2 && argc != 3) {
        printf("usage: %s dirname\n",argv[0]);
        exit(1);
    }

    pid = fork();

    if(pid < 0){
        perror("Fork Error");
        exit(2);
    }
    else if (pid > 0){
        printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);
        wait(&status);
    }
    else if (pid == 0){

        if(argc == 3){
            int file = open(argv[2], O_WRONLY|O_CREAT, 0666); //abre só para escrita; criar se não existir
            dup2(file, STDOUT_FILENO); //redireciona a standard output para o ficheiro cujo descritor é file
        }

        execlp("ls", "ls, ""-laR", argv[1], NULL);
        printf("Command not executed !\n");
        exit(3);
    }

    exit(0);
}