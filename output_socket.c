#include "output.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#ifndef OUTPUT_IP
#define OUTPUT_IP "127.0.0.1"
#endif

#ifndef OUTPUT_PORT
#define OUTPUT_PORT 12345
#endif

static int sockfd = -1;

static void write_to_socket(const char *str) {
    size_t len = strlen(str);
    size_t sent = 0;
    while (sent < len) {
        ssize_t n = send(sockfd, str + sent, len - sent, 0);
        if (n < 0) {
            perror("Error sending data");
            exit(1);
        }
        sent += n;
    }
}

void output_init() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(OUTPUT_PORT);
    if (inet_pton(AF_INET, OUTPUT_IP, &addr.sin_addr) != 1) {
        fprintf(stderr, "Error converting IP address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
}

void output_cleanup() {
    close(sockfd);
}

void output(const char *format, ...) {
    char buf[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(buf, sizeof(buf), format, args);
    va_end(args);
    write_to_socket(buf);
}
