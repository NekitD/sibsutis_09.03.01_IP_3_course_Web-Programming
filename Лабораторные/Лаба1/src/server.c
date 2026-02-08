#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <string.h>
#include <unistd.h> 

#define BUFF_LEN 81

int main()
{
    double i = 0;
    int server_socket = 0;

    struct sockaddr_in client_addr;
    struct sockaddr_in server_addr;

    char msg[BUFF_LEN] = "";
    int msgLength = 0;

    //--------------------------------------------------------
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if(server_socket < 0){
        printf("SERVER SOCKET CREATION FAILED!");
        return -1;
    }

    bzero((char*)&server_addr, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = 0;
    
    if(bind(server_socket, &server_addr, sizeof(struct sockaddr_in)) < 0){
        printf("SERVER SOCKET INIT FAILED!");
        return -1;
    }
    //------------------------------------------------------------
    int length = 0;
    length = sizeof(server_addr);
    if (getsockname(server_socket, &server_addr, &length ))
    {
        printf("FAILED TO GET THE SERVER PORT!");
        return -1;
    }
    printf("SERVER: port - % d\n\n", ntohs(server_addr.sin_port ));

    char answer[BUFF_LEN] = "SERVER: I received - ";
    for( ; ; ) {
        length = sizeof(client_addr ) ;
        bzero(msg, sizeof(BUFF_LEN) );
        bzero(answer, sizeof(BUFF_LEN));
        if ( (msgLength = recvfrom(server_socket, msg, BUFF_LEN, 0 , &client_addr, &length) ) < 0 )
        { 
            printf("Invalid client socket.");
            break;
        }
        strcat(answer, msg);
        printf("SERVER: client IP: %d\n", inet_ntoa(client_addr.sin_addr) ) ;
        printf("SERVER: client port: %d\n", ntohs(client_addr.sin_port) ) ;
        printf("SERVER: message length - %d\n", msgLength);
        printf("SERVER: message: %s\n\n", msg);
        sendto(server_socket, answer, BUFF_LEN, 0 , &client_addr , sizeof(struct sockaddr_in));
    }
    close(server_socket);
    return 0;
}