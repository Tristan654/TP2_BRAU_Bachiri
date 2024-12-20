#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stddef.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>



int main (int argc, char *argv[]){
    
    
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;           // IPv4
    serv_addr.sin_port = htons(69);         // assgnement to PORT 69


    int domain = PF_INET; // IPv4
    int type = SOCK_DGRAM;//Datagram mode (⇒ UDP)
    int protocol = IPPROTO_UDP;//defines the Level-4 protocol to use : UDP


    int sock = socket(domain,type,protocol);//creating a socket

    if (sock <  0){
        perror("creating error");
        exit(EXIT_FAILURE);
    }
    

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {//initiate the UDP connection with the server 
        perror("Erreur de connexion");
        close(sock);
        exit(EXIT_FAILURE);
    }else if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0){
        write(STDOUT_FILENO,"the socket is connected",sizeof("the socket is connected"));
    }

    return 0;
    }

