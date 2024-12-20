
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stddef.h>
#include <netdb.h>

int main (int argc, char *argv[]){
    struct addrinfo hints;
    struct addrinfo *res,*r;

    char *filename = argv[1];
    char *host = argv[2];
    

    memset(&hints, 0, sizeof(struct addrinfo));//tilisée pour remplir une zone de mémoire avec une valeur spécifique.
    hints.ai_family = AF_INET;    /* Allow IPv4  */
    hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
    hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */


    int status = getaddrinfo(argv[2],NULL,&hints,&res);
    if (status != 0){
        fprintf(stderr,"%s\n",gai_strerror(status));//stdout sortie standart / stderr flux d'erreur restera tj afficher dans la console alors stdout peut etre ecrit dans un fichier
        exit(EXIT_FAILURE);   
    }
    

    
    for (r = res; r != NULL; r=r->ai_next){
        char buffer[100];  
        int length;
        write(STDOUT_FILENO, "1",1);
        length = snprintf(buffer, 100,"famille = %d \n TypeSocket = %d \n  protocol = %d\n",r->ai_family,r->ai_socktype,r-> ai_protocol);
        write(STDOUT_FILENO, buffer, length);
    }
    freeaddrinfo(res);
    exit(EXIT_SUCCESS);

    
return 0;
}

