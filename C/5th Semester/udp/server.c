#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char buf[1024];
    struct sockaddr_in server, client;
    socklen_t client_addr_len = sizeof(client);
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("\nError in opening socket...");
        exit(1);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htons(INADDR_ANY);
    server.sin_port = htons(7777);

    if (bind(sockfd, (struct sockaddr*)&server, sizeof(server))) {
        perror("\nError in bind...");
        exit(2);
    }
    printf("\nSocket has port # %hd \n", htons(server.sin_port));

    while (1) {
        bzero(buf, 1024);

        if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&client, &client_addr_len) < 0) {
            printf("Invalid Datagram Received\n");
        }
        printf("Received: %s \n", buf);

        if (strcmp(buf, "bye") == 0) {
            break;
        }
    }
    close(sockfd);
    return 0;
}
