/*
    Name: Swapnaraj Mohanty
    SIC:  24BCSH93
    Sec:  B-2
*/

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void error(const char* msg) {
    perror(msg);
    exit(1);
}

int main(const int argc, char* argv[]) {
    char buffer[256];

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    struct sockaddr_in serv_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(atoi(argv[1])),
        .sin_addr.s_addr = INADDR_ANY,
    };
    struct sockaddr cli_addr;
    const int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }
    listen(sockfd, 5);
    int clilen = sizeof(cli_addr);
    int newsockfd = accept(sockfd, &cli_addr, &clilen);

    if (newsockfd < 0) {
        error("ERROR on accept");
    }
    bzero(buffer, 256);

    if (read(newsockfd, buffer, 255) < 0) {
        error("Error reading from socket");
    }
    printf("Here is the message: %s\n", buffer);

    if (write(newsockfd, "I got your message", 18) < 0) {
        error("ERROR writing to socket");
    }
    return 0;
}
