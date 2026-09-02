#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define TRUE 1

int main(int argc, char* argv[]) {
    int chpid;
    socklen_t len;
    char buf[1024], buf1[1024];
    struct sockaddr_in server, client;
    socklen_t addrlen = sizeof(client);
    // portno = 5001;

    /* First call to socket() functiom */
    const int soc = socket(AF_INET, SOCK_STREAM, 0);

    if (soc < 0) {
        perror("Error opening socket");
        exit(1);
    }
    // ---Configure settings for the server address structure-----
    // Initialize socket structure elements to zero
    // bzero((char*)&serv_addr, sizeof(serv_addr));
    // Set Address family = Internet
    server.sin_family = AF_INET;
    // Set IP address to localhost
    // serv_addr.sin_addr.s_addr = INADDR_ANY;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    // Set port number, using htons function to use proper byte order
    // serv_addr.sin_port = htons(portno);
    server.sin_port = 0;

    /* Now bind he host address using bind() call. */
    if (bind(soc, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Error in binding...");
        exit(1);
    }
    /* Now start listening for the client, here process will go in sleep mode and wait for the incoming connection*/
    len = sizeof(server);

    if (getsockname(soc, (struct sockaddr*)&server, &len)) {
        perror("\nError in getting port..");
        exit(3);
    }
    printf("\nSocket has port no: %hd\n", htons(server.sin_port));
    listen(soc, 5); // Listen on the socket, with 5max connection requests queued
    signal(SIGCHLD, SIG_IGN);

    do {
        /* Accept actual connection from the client */
        const int msgsock = accept(soc, (struct sockaddr*)&client, (socklen_t*)&addrlen);

        if (msgsock == -1) {
            perror("\nError in accept..");
            exit(0);
        } else {
            if ((chpid = fork()) == 0) {
                close(soc);
                do {
                    read(msgsock, buf, 1024);
                    printf("\nMessage from client: %s\n", buf);
                    printf("Message to client: ");
                    scanf(" %[^\n]", buf1);
                    write(msgsock, buf1, 1024);
                } while (strcmp(buf1, "bye") != 0);
                close(msgsock);
                exit(0);
            } else {
                close(msgsock);
            }
        }
    } while (strcmp(buf1, "bye") != 0);
    close(soc);
    return 0;
}
