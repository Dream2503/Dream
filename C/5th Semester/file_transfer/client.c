#include <netdb.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define IP "192.168.20.111"
#define PORT 2503
#define BUFFER_SIZE (64 * 1024)

static void error(const char* msg) {
    perror(msg);
    exit(1);
}

int main() {
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE], filename[256];
    const int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        error("ERROR opening socket");
    }
    const struct hostent* server = gethostbyname(IP);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting to server");
    }
    printf("Connected to server.\n");
    printf("Waiting for files...\n");

    while (1) {
        uint32_t filename_length;
        uint64_t file_size;
        size_t total_received = 0;
        ssize_t n = read(sock_fd, &filename_length, sizeof(filename_length));

        if (n < 0) {
            error("ERROR reading filename length");
        }
        if (n == 0) {
            printf("Server disconnected.\n");
            break;
        }
        while (n < sizeof(filename_length)) {
            const ssize_t temp = read(sock_fd, (char*)&filename_length + n, sizeof(filename_length) - n);

            if (temp <= 0) {
                error("ERROR receiving filename length");
            }
            n += temp;
        }
        if (filename_length >= sizeof(filename)) {
            fprintf(stderr, "ERROR, filename too long\n");
            close(sock_fd);
            exit(1);
        }
        n = read(sock_fd, filename, filename_length);

        if (n < 0) {
            error("ERROR reading filename");
        }
        while (n < filename_length) {
            const ssize_t temp = read(sock_fd, filename + n, filename_length - n);

            if (temp <= 0) {
                error("ERROR receiving filename");
            }
            n += temp;
        }
        filename[filename_length] = '\0';
        n = read(sock_fd, &file_size, sizeof(file_size));

        if (n < 0) {
            error("ERROR reading file size");
        }
        while (n < sizeof(file_size)) {
            const ssize_t temp = read(sock_fd, ((char*)&file_size) + n, sizeof(file_size) - n);

            if (temp <= 0) {
                error("ERROR receiving file size");
            }
            n += temp;
        }
        printf("\nReceiving %s (%lu bytes)...\n", filename, (unsigned long)file_size);
        FILE* file = fopen(filename, "wb");

        if (file == NULL) {
            perror("ERROR creating file");
            continue;
        }
        while (total_received < file_size) {
            const size_t remaining = file_size - total_received;
            const size_t to_read = remaining < BUFFER_SIZE ? remaining : BUFFER_SIZE;
            n = read(sock_fd, buffer, to_read);

            if (n < 0) {
                fclose(file);
                error("ERROR receiving file");
            }
            if (n == 0) {
                fclose(file);
                close(sock_fd);
                error("ERROR, server disconnected during file transfer");
            }
            if (fwrite(buffer, 1, n, file) != (size_t)n) {
                fclose(file);
                error("ERROR writing file");
            }
            total_received += n;
        }
        fclose(file);
        printf("File received successfully.\n");
        printf("Saved as: %s\n", filename);
        printf("Received: %lu bytes\n", (unsigned long)total_received);
        printf("Waiting for next file...\n");
    }
    close(sock_fd);
    return 0;
}
