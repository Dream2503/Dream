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
    server.sin_port = htons(atoi(argv[1]));

    if (connect(soc, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("\nError in connection...");
        exit(2);
    }
    do {
        printf("\nClient input: ");
        scanf(" %[^\n]", buf);
        write(soc, buf, 1024);
        printf("\n");
        read(soc, buf1, 1024);
        printf("Message from server: %s\n", buf1);
    } while (strcmp(buf, "bye") != 0);
    return 0;
}
