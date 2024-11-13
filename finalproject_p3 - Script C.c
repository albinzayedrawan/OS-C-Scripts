#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void errorHandling(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int clientSocket, port = 9999;
    struct sockaddr_in serverAddress;
    
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
        errorHandling("ERROR opening socket");
    
    bzero((char*) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(port);
    
    if (connect(clientSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) == 0) {
        printf("'This is Client C.' message was sent to the server. \n");
        
        char buf[1024];
        strncpy(buf, "This is Client C.", sizeof(buf));
        write(clientSocket, buf, strlen(buf));
        
        int count = read(clientSocket, buf, sizeof(buf));
        printf("Got echo of %.*s from server\n", count, buf);
        
        shutdown(clientSocket, SHUT_RDWR);
    }
    else {
        errorHandling("ERROR connecting");
    }
    
    return 0;
}