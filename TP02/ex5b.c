#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
  int fd;
  char *text1="CCCCC";
  char *text2="DDDDD";

  fd = open("f1.txt", O_WRONLY|O_SYNC,0600); //não consegue criar ficheiro; reescreve no ficheiro se ele existir

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

