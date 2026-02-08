#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>


int main()
{
    double i = 0;
    int client_socket = 0
    char* hostname
    int port = 0

    sockaddr_in client_addr
    sockaddr_in server_addr
    struct hostent *hp, *gethostbyname();

    //---------------------------------------------------------------------
    
    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if(client_socket < 0){
        printf("CLIENT SOCKET CREATION FAILED!");
        return -1
    }

    bzero((char*)client_addr, (sizeof(sockaddr_in)))
    client_addr.sin_family = AF_INET;
    client_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = 0;
    
    if(bind(client_socket, &c_socket_addr, sizeof(sockaddr_in)) < 0){
        printf("CLIENT SOCKET INIT FAILED!");
        return -1
    }
    //---------------------------------------------------------------------
    printf("HELLO USER! LET'S HAVE SOME FUN \n");
    printf("Input some value: ");
    scanf("%f\n", i);
    printf("\nInput hostname (no spaces): ");
    scanf("%s\n", hostname);
    printf("\nInput port: ");
    scanf("%s\n", port);
    //---------------------------------------------------------------------

    bzero((char*)server_addr, (sizeof(sockaddr_in)))
    server_addr.sin_family = AF_INET;
    hp = gethostbyname(hostname)
    bcopy( hp -> h_addr, &servAddr.sin_addr, hp -> h_length ) ;
    server_addr.sin_port = htons(port);

    //---------------------------------------------------------------------
    int counter;
    for(counter = 0; counter < i; counter++){
        if( sendto ( sock, message, i, sizeof(double) , &server_addr , sizeof(sockaddr_in) ) < 0 )
            {
                printf("SEND TO SERVER FAILED!");
                break;
            }
        printf("%f was sent.\n", i);
    }

    return 0;
}