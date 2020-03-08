#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <stdlib.h>
#include <wait.h>


int main(int argc, char *argv[]){


    //compila o ficheiro passado como argumento

    char prog[20];
    sprintf(prog,"%s.c",argv[1]);
    execlp("gcc","gcc",prog,"-Wall","-o",argv[1],NULL); // l --> lista de argumentos passados um a um; p --> o argumento é o nome do ficheiro executável 
    printf("Can't execute it!\n");
    exit(0);
}