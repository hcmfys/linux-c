#include <sys/poll.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

int main(int args, char *argv[]) {

    if (args <= 2) {
        printf("usage :%s ip address port number", basename(argv[0]));
        return 1;
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);
    int ret = 0;
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = ntohs(port);
    inet_pton(AF_INET, ip, &address.sin_addr);
    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(listenfd >= 0);
    ret = bind(listenfd, (struct sockaddr *) &address, sizeof(address));
    assert(ret != -1);
    ret = listen(listenfd, 5);
    assert(ret != -1);
    struct sockaddr_in client_address;
    socklen_t client_addresslength = sizeof(client_address);
    int confd = accept(listenfd, (struct sockaddr *) &client_address, &client_addresslength);
    if (confd < 0) {
        printf("error no %d\n", errno);
        close(listenfd);
    }
    char buff[1024];
    fd_set read_fds;
    fd_set exception_fds;
    FD_ZERO(&read_fds);
    FD_ZERO(&exception_fds);
    while (1) {
        memset(buff, 0, sizeof(buff));
        FD_SET(confd, &read_fds);
        FD_SET(confd, &exception_fds);
        ret = select(confd + 1, &read_fds, NULL, &exception_fds, NULL);
        if (ret < 0) {
            printf("select failure\n");
            break;
        }

        if (FD_ISSET(confd, &read_fds)) {
            ret = recv(confd, buff, sizeof(buff), 0);
            if (ret <= 0) {
                break;
            }
            printf("get %d bytes data=%s", ret, buff);
        } else if (FD_ISSET(confd, &exception_fds)) {
            ret = recv(confd, buff, sizeof(buff), MSG_OOB);
            if (ret <= 0) {
                break;
            }
            printf("get %d bytes oob data=%s", ret, buff);
        }

    }

    close(confd);
    close(listenfd);
    return 0;

}
