#include <stdio.h>
#include <stdlib.h>

//exercicio a; se no terminal colocar aspas 

/*int main(int argc, char *argv[]){

    printf("Hello, %s!\n", argv[1]);
    return 0;
}
*/


//exercicio b

int main(int argc, char *argv[]){

    int n = atoi(argv[argc-1]);

    while(n != 0){
        printf("%d. Hello, %s!\n", n, argv[1]);
        n--;
    }


    return 0;
}
