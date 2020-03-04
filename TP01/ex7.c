#include <stdio.h>
#include <stdlib.h>

void functionA(){
    printf("Executing exit handler 1\n");
}

void functionB(){
    printf("Executing exit handler 2\n");
}


int main(void){

    //atexit causes the specified function func to be called when the program terminates
    atexit(functionA); // 3ºcoisa que vai aparecer
    atexit(functionB); // 2ºcoisa que vai aparecer
    //atexit(functionA); --> funciona 

    // abort(); --> não printa nada


    printf("Main done!\n"); // 1ºcoisa que vai aparecer

    return 0;
}