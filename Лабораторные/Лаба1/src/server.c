#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define BUFF_LEN 15

int main()
{
    double i = 0;
    int server_socket = 0

    sockaddr_in client_addr
    sockaddr_in server_addr

    char msg[BUFF_LEN];
    int msgLength = 0;

    //--------------------------------------------------------
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if(server_socket < 0){
        printf("SERVER SOCKET CREATION FAILED!");
        return -1
    }

    bzero( (char *) &server_addr, sizeof( server_addr ) );
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl( INADDR_ANY );
    server_addr.sin_port = 0;
    
    if(bind(server_socket, &server_addr, sizeof(sockaddr_in)) < 0){
        printf("SERVER SOCKET INIT FAILED!");
        return -1
    }
    //------------------------------------------------------------
    int length = 0;
    length = sizeof(server_addr);
    if (getsockname(server_socket, &server_addr, &length ))
    {
        printf("FAILED TO GET THE SERVER PORT!");
        return -1
    }
    printf("SERVER: port - % d\n", ntohs(server_addr.sin_port ) )
    for( ; ; ) {
        length = sizeof(clientAddr ) ;
        bzero(msg, sizeof(BUFF_LEN) );
        if ( (msglength = recvfrom(client_socket, msg, BUFF_LEN, 0 , &clientAddr, &length) ) < 0 )
        { 
            printf("Invalid client socket.");
            break;
        }
        printf( "SERVER: client IP: %s\n", inet_ntoa(clientAddr.sin_addr) ) ;
        printf( "SERVER: client port: %d\n", ntohs(clientAddr.sin_port) ) ;
        printf( "SERVER: message length - %d\n", msgLength);
        printf( "SERVER: message: %s\n\n", msg);
        if( sendto ( sock, message, i*i, sizeof(double) , &server_addr , sizeof(sockaddr_in) ) < 0 )
        {
            printf("SEND TO CLIENT FAILED!");
            break;
        }
        printf("%f was sent.\n", i*i);
    }
    return 0;
}