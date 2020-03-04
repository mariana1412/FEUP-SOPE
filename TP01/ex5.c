#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[], char *envp[]){


    //exercicio a
    /*for(int i = 0; envp[i] != NULL; i++)
        printf("%s\n", envp[i]);

    */

    //exercicio b
    /*for(int i = 0; envp[i] != NULL; i++){
        if(strncmp(envp[i], "USER=", 5) == 0){
            printf("Hello, %s!\n", envp[i]+5);
            return 0;
        }
    }*/

    //exercicio c
    //printf("Hello, %s!\n", getenv("USER"));
    

    //exercicio d
    //no terminal -> export USER_NAME=marianaalmeidatruta
    printf("Hello, %s!\n", getenv("USER_NAME"));


    return 0;
}






