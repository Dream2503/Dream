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
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    const int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    bzero((char*)&serv_addr, sizeof(serv_addr));
    const int portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }
    listen(sockfd, 5);
    int clilen = sizeof(cli_addr);
    int newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);

    while (1) {
        if (newsockfd < 0) {
            error("ERROR on accept");
        }
        bzero(buffer, 256);
        int n = read(newsockfd, buffer, 255);

        if (n < 0) {
            error("Error reading from socket");
        }
        if (buffer[0] == 'b' && buffer[1] == 'y' && buffer[2] == 'e') {
            close(sockfd);
            close(newsockfd);
            exit(0);
        }
        printf("Here is the message: %s\n", buffer);
        printf("Enter your message: ");
        bzero(buffer, 256);
        fgets(buffer, 256, stdin);

        if (buffer[0] == 'b' && buffer[1] == 'y' && buffer[2] == 'e') {
            close(sockfd);
            close(newsockfd);
            break;
        }
        n = write(newsockfd, buffer, strlen(buffer));

        if (n < 0) {
            error("ERROR writing to socket");
        }
    }
    return 0;
}
