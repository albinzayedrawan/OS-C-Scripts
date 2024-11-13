#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

void errorHandling(const char *msg)
{
    perror(msg);
    exit(1);
}

void* echo(void* param)
{
    char buf[1024];
    int count;
    int clientSocket = *(int*)param;
    pthread_detach(pthread_self());
    
    while ((count = read(clientSocket, buf, 1023)) > 0) {
        printf("Server received: %s\n", buf);
        write(clientSocket, buf, count);
    }
    
    close(clientSocket);
    free(param);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int serverSocket, newConn, port = 9999;
    
    // Create a TCP/IP socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
        errorHandling("ERROR opening socket");
    
    struct sockaddr_in serverAddress;
    
    // Clear address structure
    memset((char*)&serverAddress, 0, sizeof(serverAddress));
    
    // Server byte order
    serverAddress.sin_family = AF_INET;
    
    // Automatically be filled with current host's IP address
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    
    // Port number to bind to
    serverAddress.sin_port = htons(port);
    
    // Bind the socket to the current IP address on the specified port
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        errorHandling("ERROR on binding");
    }
    
    // Listen for incoming connections
    listen(serverSocket, 5);
    
    while (1) {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        
        // Accept a new connection
        newConn = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength);
        if (newConn < 0)
            errorHandling("ERROR on accept");
        
        // Create a new thread to handle the connection
        int* socket_ptr = malloc(sizeof(int));
        *socket_ptr = newConn;
        
        pthread_t thread;
        pthread_create(&thread, NULL, echo, (void*)socket_ptr);
    }
    
    close(serverSocket);
    
    return 0;
}