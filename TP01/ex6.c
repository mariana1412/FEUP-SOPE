#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define BUF_LENGTH 256


//exercicio a
/*int main(void){

    FILE *src, *dst;
    char buf[BUF_LENGTH];

    if ( ( src = fopen( "infile.txt", "r" ) ) == NULL ) {
        exit(1);
    }

    if ( ( dst = fopen( "outfile.txt", "w" ) ) == NULL ) {
        exit(2);
    }

    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL ) {
        fputs( buf, dst );
    }

    fclose(src);
    fclose(dst);
    exit(0); //0 significa que a função terminou com sucesso
}

exercicio b -> o modo 'r' na função 'fopen()' implica que o ficheiro tem de existir para ser lido. se não existir, a função vai terminar com o exit code 1.
por isso, é que o programa não é executado corretamente.

exercicio c -> o que foi dito na alínea anterior é confirmado com a verificação do código de terminação na shell (echo $? ---> 1);

*/


int main(void){

    FILE *src, *dst;
    char buf[BUF_LENGTH];

    if ( ( src = fopen( "infile.txt", "r" ) ) == NULL ) {
        //perror("1. Error"); //mostra no ecrã uma mensagem de erro --> alinea d
        printf("1. errno = %d\n", errno); //alinea e
        exit(1);
    }

    if ( ( dst = fopen( "outfile.txt", "w" ) ) == NULL ) {
        //perror("2. Error"); --> alinea d
        printf("2. errno = %d\n", errno); //alinea e
        exit(2);
    }

    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL ) {
        fputs( buf, dst );
    }

    fclose(src);
    fclose(dst);
    exit(0); 
}