#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>


int main(int argc, char *argv[]) {

    pid_t pid, childpid;
    int status;

    if (argc != 2) {
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
        childpid = wait(&status);

        if(WIFEXITED(status)){
            printf("A child with PID %d terminated normally with EXIT CODE %d\n", childpid, WEXITSTATUS(status)); // WEXITSTATUS(status) => permite obter o exit status do filho
        }
        else if(WIFSIGNALED(status)){
            printf("A child with PID %d terminated abnormally with SIGNAL NUMBER %d\n", childpid, WTERMSIG(status));
        }
        else if(WIFSTOPPED(status)){
            printf("A child with PID %d stopped because of the SIGNAL NUMBER %d\n", childpid, WSTOPSIG(status));
        }        
    }
    else if (pid == 0){
        execlp("ls", "ls", "-laR", argv[1], NULL);
        printf("Command not executed !\n");
        exit(3);
    }

    exit(0);
}


//nota alinea a: para matar o filho, é necessario fazer ps -u no terminal, encontrar o pid do filho e executar o comando "kill pidfilho"