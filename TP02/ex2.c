#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_LENGTH 512

//exercicio a
/*int main(void){

    FILE *file1, *file2;
    char buf[BUF_LENGTH];

    if((file1 = fopen("infile.txt", "r")) == NULL){ //'r'--> opens a file for reading, the file must exit
        perror("Error");
        exit(1);
    }

    if((file2 = fopen("outfile.txt", "w")) == NULL){ // 'w' --> Creates an empty file for writing. If a file with the same name already exists, its content is erased and the file is considered as a new empty file.
        perror("Error");
        exit(1);
    }

    while(fgets(buf, BUF_LENGTH, file1) != NULL){
        fputs(buf, file2);
    }

    fclose(file1);
    fclose(file2);


    return 0;
}*/

//exercicio b
int main(void){

    int file1, file2;
    char buf[BUF_LENGTH], cr, cw;

    file1 = open("infile.txt", O_RDONLY);

    if(file1 == -1){
        perror("infile.txt");
        exit(1);
    }

    file2 = open("outfile.txt", (O_WRONLY|O_CREAT|O_EXCL), 0644);

    if(file2 == -1){
        perror("outfile.txt");
        close(file1);
        exit(2);
    }

    while((cr = read(file1, buf, BUF_LENGTH)) > 0){
        if((cw = write(file2, buf, cr)) <= 0 || (cw != cr)){
            perror("outfile.txt");
            close(file1);
            close(file2);
            exit(3);
        }
    }

    close(file1);
    close(file2);

    exit(0);
}

/*

NOTAS:
-> read() retorna o nº de bytes lidos, 0 se fim de ficheiro, -1 se erro
-> write() retorna o nº bytes escritos, -1 se erro


*/