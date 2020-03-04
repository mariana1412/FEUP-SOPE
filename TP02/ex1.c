#include <termios.h>
#include <unistd.h>
#include <string.h> 


#define MAX_LEN 20

int main(void){

    struct termios oldterm, newterm;
    char pass[MAX_LEN + 1], ch, echo = '*';

    write(STDOUT_FILENO, "\nPassword: ", 11); //STDOUT_FILENO é um descritor para o standard output; vai escrever a mensagem no ecra
    tcgetattr(STDIN_FILENO, &oldterm); //STDIN_FILENO é um descritor para o standar input; vai ler o que o utilizador escreveu
    
    
    newterm = oldterm;
    newterm.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON); //ver o API de apoio
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &newterm); //altera caracteristicas da consola

    int i = 0;

    while((i<MAX_LEN) && read(STDIN_FILENO, &ch, 1) && (ch != '\n')){
        pass[i++] = ch;
        write(STDOUT_FILENO, &echo, 1);
    }

    pass[i] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &oldterm); //volta a colocar as caracteristicas da consola como estava

    write(STDOUT_FILENO, "\n\nPassword: ", 12);
    write(STDOUT_FILENO, pass, strlen(pass));
    write(STDOUT_FILENO, "\n", 1);


    return 0;
}