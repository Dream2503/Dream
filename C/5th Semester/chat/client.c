#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

/*
Name: Swapnaraj Mohanty
SIC:  24BCSH93
Sec:  B-2
*/

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
    const int port_no = atoi(argv[2]);
    const int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        error("ERROR opening socket");
    }
    const struct hostent* server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port_no);

    if (connect(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }
    while (1) {
        printf("Please enter the message: ");
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);
        int n = write(sock_fd, buffer, strlen(buffer));

        if (buffer[0] == 'b' && buffer[1] == 'y' && buffer[2] == 'e') {
            break;
        }
        if (n < 0) {
            error("ERROR writing to socket");
        }
        bzero(buffer, 256);
        n = read(sock_fd, buffer, 255);

        if (n < 0) {
            error("ERROR reading from socket");
        }
        server = gethostbyname(argv[1]);
        if (server == NULL) {
            exit(0);
        }
        printf("%s\n", buffer);
    }
    return 0;
}
