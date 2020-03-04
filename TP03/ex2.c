#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


/*
 --> exercicio a:
    Depois de fork(), o código é realizado 2 vezes (quando tudo correu bem); já que o filho vai executar o código do processo pai; 
    assim sendo, o que vai aparecer no ecrã é algo do genero "1\n 23\n 45\n";
 --> exercicio c/d:
    "\n causes that output buffer to flush after the first printf() call, and when the fork hits, both processes have an empty buffer".
    Basta para passar para tprintf e já não há este problema


*/


int main(void){
    /*write(STDOUT_FILENO, "1", 1);
    write(STDOUT_FILENO,"\n",1);*/

    printf("%d\n", 1);

    if(fork() > 0) {
        /*write(STDOUT_FILENO,"2",1);
        write(STDOUT_FILENO,"3",1); */
        printf("%d", 2);
        printf("%d", 3);
    }
    else {
        /*write(STDOUT_FILENO,"4",1);
        write(STDOUT_FILENO,"5",1);*/
        printf("%d", 4);
        printf("%d", 5);
    }

    //write(STDOUT_FILENO,"\n",1);
    printf("\n");
    return 0; 
}