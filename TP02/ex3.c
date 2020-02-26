#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    int fd1, fd2, nr, nw;
    unsigned char buffer[BUFFER_SIZE];

    if ((argc != 2) && (argc != 3)) {
    printf("Usage: %s <source>  OR  %s <source> <destination>\n", argv[0], argv[0]);
    return 1;
    }
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        perror(argv[1]);
        return 2;
    }

    if(argc == 3){

        fd2 = open("outfile.txt", (O_WRONLY|O_CREAT|O_EXCL), 0644);

        if (fd2 == -1) {
            perror(argv[2]);
            close(fd1);
            return 2;
        }
        
        dup2(fd2, STDOUT_FILENO);
    }


    while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0){
        if ((nw = write(STDOUT_FILENO, buffer, nr)) <= 0 || nw != nr) {
            perror("Error");
            close(fd1);
            return 4;
        }
    }
    close(fd1);
    return 0;
}

