#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 2503
#define MAX_CLIENTS 100
#define BUFFER_SIZE (64 * 1024)

static void error(const char* msg) {
    perror(msg);
    exit(1);
}

static int send_all(const int sock_fd, const void* data, const size_t size) {
    size_t total = 0;

    while (total < size) {
        const ssize_t n = write(sock_fd, (const char*)data + total, size - total);

        if (n <= 0) {
            return -EXIT_FAILURE;
        }
        total += n;
    }
    return EXIT_SUCCESS;
}

int main() {
    const int opt = 1;
    int clients[MAX_CLIENTS];
    char filename[256], buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i] = -1;
    }
    const int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        error("ERROR opening socket");
    }

    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        error("ERROR setting socket options");
    }
    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }
    if (listen(sock_fd, MAX_CLIENTS) < 0) {
        error("ERROR on listen");
    }
    printf("Server started on port %d.\n", PORT);
    printf("Waiting for clients...\n");

    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sock_fd, &read_fds);
        FD_SET(STDIN_FILENO, &read_fds);
        int max_fd = sock_fd;

        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] != -1) {
                FD_SET(clients[i], &read_fds);

                if (clients[i] > max_fd) {
                    max_fd = clients[i];
                }
            }
        }
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            error("ERROR on select");
        }
        if (FD_ISSET(sock_fd, &read_fds)) {
            struct sockaddr_in cli_addr;
            socklen_t clilen = sizeof(cli_addr);
            const int new_client = accept(sock_fd, (struct sockaddr*)&cli_addr, &clilen);

            if (new_client < 0) {
                perror("ERROR on accept");
            } else {
                int added = 0;

                for (int i = 0; i < MAX_CLIENTS; i++) {
                    if (clients[i] == -1) {
                        clients[i] = new_client;
                        added = 1;
                        printf("Client connected: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
                        break;
                    }
                }
                if (!added) {
                    printf("Maximum clients reached.\n");
                    close(new_client);
                }
            }
        }
        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            printf("Enter file name: ");
            fflush(stdout);

            if (scanf("%255s", filename) != 1) {
                break;
            }
            if (strcmp(filename, "bye") == 0) {
                break;
            }
            FILE* file = fopen(filename, "rb");

            if (file == NULL) {
                perror("ERROR opening file");
                continue;
            }
            fseek(file, 0, SEEK_END);
            const long file_size_long = ftell(file);
            fseek(file, 0, SEEK_SET);

            if (file_size_long < 0) {
                fclose(file);
                perror("ERROR getting file size");
                continue;
            }
            const uint64_t file_size = file_size_long;
            const uint32_t filename_length = strlen(filename);
            printf("Sending %s (%lu bytes) to connected clients...\n", filename, (unsigned long)file_size);

            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] == -1) {
                    continue;
                }
                if (send_all(clients[i], &filename_length, sizeof(filename_length)) < 0) {
                    printf("Client %d disconnected.\n", i + 1);
                    close(clients[i]);
                    clients[i] = -1;
                    continue;
                }
                if (send_all(clients[i], filename, filename_length) < 0) {
                    printf("Client %d disconnected.\n", i + 1);
                    close(clients[i]);
                    clients[i] = -1;
                    continue;
                }
                if (send_all(clients[i], &file_size, sizeof(file_size)) < 0) {
                    printf("Client %d disconnected.\n", i + 1);
                    close(clients[i]);
                    clients[i] = -1;
                    continue;
                }
                fseek(file, 0, SEEK_SET);
                size_t bytes_read;

                while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
                    if (send_all(clients[i], buffer, bytes_read) < 0) {
                        printf("Client %d disconnected.\n", i + 1);
                        close(clients[i]);
                        clients[i] = -1;
                        break;
                    }
                }
                if (ferror(file)) {
                    fclose(file);
                    error("ERROR reading file");
                }
                if (clients[i] != -1) {
                    printf("Client %d: file sent successfully.\n", i + 1);
                }
            }
            fclose(file);
            printf("File transmission complete.\n");
            printf("Waiting for next file...\n");
        }
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] != -1 && FD_ISSET(clients[i], &read_fds)) {
                char temp;
                const ssize_t n = read(clients[i], &temp, 1);

                if (n == 0) {
                    printf("Client %d disconnected.\n", i + 1);
                    close(clients[i]);
                    clients[i] = -1;
                } else if (n < 0) {
                    close(clients[i]);
                    clients[i] = -1;
                }
            }
        }
    }
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != -1) {
            close(clients[i]);
        }
    }
    close(sock_fd);
    return 0;
}
