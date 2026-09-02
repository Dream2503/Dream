#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void error(const char* msg) {
    perror(msg);
    exit(0);
}

int main(const int argc, char* argv[]) {
    struct sockaddr_in serv_addr;
    char buffer[256];

    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    const struct hostent* server = gethostbyname(argv[1]);

    if (!server) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }
    printf("Please enter the message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        error("ERROR writing to socket");
    }
    bzero(buffer, 256);

    if (read(sockfd, buffer, 255) < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);
    return 0;
}
