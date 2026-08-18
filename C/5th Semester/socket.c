#include <stdio.h>

typedef struct Socket {
    const char* socket_id; // Any string
    const char* socket_type; // TCP / UDP
    const char* host_id; // IP address
    const char* dest_id; // IP address
    int port_no; // 4 digit tve no.
    char status; // Y / N
} Socket;

void print_socket(const Socket* socket) {
    printf("Socket {\n");
    printf("\tsocket_id=%s\n", socket->socket_id);
    printf("\tsocket_type=%s\n", socket->socket_type);
    printf("\thost_id=%s\n", socket->host_id);
    printf("\tdest_id=%s\n", socket->dest_id);
    printf("\tport_no=%d\n", socket->port_no);
    printf("\tstatus=%c\n", socket->status);
    printf("}");
}

int main() {
    const Socket socket = {
        .socket_id = "2503",
        .socket_type = "TCP",
        .host_id = "192.168.1.1",
        .dest_id = "192.168.1.2",
        .port_no = 8080,
        .status = 'Y',
    };
    print_socket(&socket);
    return 0;
}
