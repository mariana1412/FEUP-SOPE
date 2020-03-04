#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX 50000

int main(int argc, char *argv[], char *envp[]) {

    int i;  
    pid_t pid;  
    char str[10];  

    pid=fork();
   
   
    switch (pid) {          
        case -1:                               
            perror("fork");                                    
            break;   

        case  0: //filho                
            for (i=1; i<=MAX; i++) {                                     
                sprintf(str,"-%d",i);                                          
                write(STDOUT_FILENO,str,strlen(str));                                    
            }                                    
            break; 

        default: //pai                
            for (i=1; i<=MAX; i++) {                                     
                sprintf(str,"+%d",i);                                          
                write(STDOUT_FILENO,str,strlen(str));                                    
            }       
    }  
    return 0; 
}

//inicialmente só o pai é que executa o programa e por isso é que só se vê "+"; uns milissegundos depois, o filho começa a imprimir numeros no ecrã de forma alternada com o pai

