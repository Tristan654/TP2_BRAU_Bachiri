#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define Size_message 10;


int main(int argc, char* argv[]){

    char buffer[100];  
    int length;
    length = snprintf(buffer, sizeof(buffer), "le nombre d'argument est de : %d\n", argc);
    write(STDOUT_FILENO, buffer, length);


    char *filename = argv[1];
    char *host = argv[2];
    
    write(STDOUT_FILENO, "Filename: ", sizeof("Filename: "));
    write(STDOUT_FILENO, filename, strlen(filename)); 
    write(STDOUT_FILENO, "\n", 1); 

    write(STDOUT_FILENO, "Host: ", sizeof("Host: "));
    write(STDOUT_FILENO, host, strlen(host)); 
    write(STDOUT_FILENO, "\n", 1); 
    
return 0;
}