#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <string.h>

#define BUFF_LEN 81

int main()
{
    double i = 0;
    int client_socket = 0;
    char* hostname;
    int port = 0;
    char msg[BUFF_LEN] = "";

    struct sockaddr_in client_addr;
    struct sockaddr_in server_addr;
    struct hostent *hp, *gethostbyname();

    //---------------------------------------------------------------------
    
    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if(client_socket < 0){
        printf("CLIENT SOCKET CREATION FAILED!");
        return -1;
    }

    bzero((char*)&client_addr, (sizeof(struct sockaddr_in)));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = 0;
    
    if(bind(client_socket, &client_addr, sizeof(struct sockaddr_in)) < 0){
        printf("CLIENT SOCKET INIT FAILED!");
        return -1;
    }
    //---------------------------------------------------------------------
    printf("HELLO USER! LET'S HAVE SOME FUN \n");
    printf("Input some value: ");
    scanf("%lf\n", &i);
    sprintf(msg, "%.2f", i);
    printf("\nInput hostname (no spaces): ");
    scanf("%s\n", &hostname);
    printf("\nInput port: ");
    scanf("%d\n", &port);
    //---------------------------------------------------------------------

    bzero((char*)&server_addr, (sizeof(struct sockaddr_in)));
    server_addr.sin_family = AF_INET;
    hp = gethostbyname(hostname);
    bcopy(hp->h_addr, &server_addr.sin_addr, hp->h_length) ;
    server_addr.sin_port = htons(port);

    //---------------------------------------------------------------------
    int counter;
    for(counter = 0; counter < i; counter++){
        if( sendto(client_socket, msg, BUFF_LEN, 0 , &server_addr , sizeof(struct sockaddr_in) ) < 0)
            {
                printf("SEND TO SERVER FAILED!");
                break;
            }
        printf("%f was sent.\n", i);
        sleep(i);
    }

    
    char* answer = "Server sent answer - ";
    int length = 0;
    for( ; ; ) {
        length = sizeof(server_addr) ;
        bzero(msg, sizeof(BUFF_LEN) );
        if ( (recvfrom(client_socket, msg, BUFF_LEN, 0 , &server_addr, &length) ) < 0 )
        { 
            printf("Invalid server socket.");
            break;
        }
        printf( "%s\n", answer);
    }
    return 0;
}