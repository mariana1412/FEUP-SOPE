#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[], char *envp[]) {
    pid_t pid;
    if (argc != 2) {
        printf("usage: %s dirname\n",argv[0]);
        exit(1);
    }

    pid=fork();
    char *command[] = {"ls", "-laR", NULL};

    if (pid > 0)
        printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);
    
    else if (pid == 0){
        //o processo‐filho faz o que o processo‐pai anuncia que ele vai fazer
        execlp("ls", "ls, ""-laR", argv[1], NULL); // alinea a
        //execl("/bin/ls","ls","-laR",argv[1],NULL); //alinea b
        //execvp("ls", command); //alinea c
        //execv("/bin/ls", command); //alinea d
        //execve("/bin/ls", command, envp); //alinea e

        printf("Command not executed !\n");
        exit(1);
    }

    exit(0);
}