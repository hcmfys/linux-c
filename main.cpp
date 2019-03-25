#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <netinet/in.h>
#include <assert.h>
#include <strings.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>


void *hand_event(void *fd) {
    char buff[256];
    int *s = (int *) fd;
    int sock = *s;
    bool stop = false;
    while (!stop) {
        int n = recv(sock, buff, 256, 0);
        printf(" recv length=%d\n", n);
        if (n > 0) {
            buff[n] = '\0';
            printf("%s", buff);
            int send_len = n + 10;
            char data[send_len];
            bzero(data, send_len);
            sprintf(data, "send to %s\n", buff);
            send(sock, data, strlen(data), 0);
        } else if (n == 0) {
            stop = true;
            close(sock);
            return 0;
        } else if (n == -1) {
            return 0;
        }
    }
    close(sock);
    return 0;
}

void connect_host(char *ip, int port) {
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, ip, &address.sin_addr);
    printf("addr=%d  port=%d \n", address.sin_addr, htons(address.sin_port));
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    int ret = bind(sock, (struct sockaddr *) &address, sizeof(address));
    bool stop = false;
    pthread_t pt;

    printf("socket =%d\n", sock);
    if (ret == -1) {
        printf("error to  bind\n");
    } else {
        ret = listen(sock, 5);
        if (ret == -1) {
            printf("error to listen ");
        } else {
            printf("bind %s  ok \n", ip);
            while (!stop) {
                struct sockaddr_in remote_addr;
                socklen_t client_length = sizeof(remote_addr);
                int fd = accept(sock, (struct sockaddr *) &remote_addr, &client_length);
                if (fd < 0) {
                    printf("error is %d\n", errno);
                } else {
                    printf("accepet \n");
                    char remote_name[INET_ADDRSTRLEN];
                    inet_ntop(AF_INET, &remote_addr.sin_addr, remote_name, INET_ADDRSTRLEN);
                    printf("remote client=%s \n", remote_name);
                    ret = pthread_create(&pt, NULL, hand_event, &fd);
                    printf("create a thead to %d\n", ret);

                }
            }
        }
    }
    close(sock);
}

int main() {
    connect_host("127.0.0.1", 8080);
    return 0;
}