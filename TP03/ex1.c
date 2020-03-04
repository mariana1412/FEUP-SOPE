#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int global=1; 


int main(void){

    int local = 2;

    if(fork() > 0){
        printf("Pai --> PID = %d; PPID = %d\n", getpid(), getppid());
        global++;
        local--; 
    }
    else {
        printf("Filho -> PID = %d; PPID = %d\n", getpid(), getppid()); 
        global--;
        local++;
    }

    printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local); 
    //getpid() -> obter PID do próprio processo
    //getppid() -> obter PID do processo pai
    //dá para identificar o filho e o pai quando o programa corre sem utilizar "Pai-->" e "Filho->"; só é preciso analisar os pids e ppids de cada um
    //os valores de ppid e de pid mudam sempre que o programa é executado;
    //é sempre executado Pai->Filho
    return 0;


}