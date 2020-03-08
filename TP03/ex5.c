#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(void){

    pid_t pid = fork();  

    if(pid > 0)
        write(STDOUT_FILENO, "Hello ", 6);
    else
        return 0;
    


    pid = fork();

    if(pid > 0)
        write(STDOUT_FILENO, "my ", 3);
    else
        return 0;


    pid = fork();

    if(pid > 0)
        write(STDOUT_FILENO, "friends!\n", 9);
    else
        return 0;
    


    return 0;
}