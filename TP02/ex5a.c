#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
  int fd;
  char *text1="AAAAA";
  char *text2="BBBBB";

  fd = open("f1.txt",O_CREAT|O_EXCL|O_WRONLY|O_SYNC, 0600); //não escreve se existir o ficheiro, dá erro

  if(fd == -1){
    perror("Error");
    return 1;
  }

  if(write(fd, text1, 5) == -1){
    perror("Error");
    return 2;
  }

  if(write(fd, text2, 5) == -1){
    perror("Error");
    return 3;
  }

  close(fd);
  return 0;
}

