//
// Created by tomcat on 2019-03-26.
//


#include "m.h"
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <utime.h>

void print_error(int code) {

    char *message = strerror(code);
    printf("%d: %s\n", code, message);
}


void file_info(char *file) {
    int ret;
    int fd;
    int access_mode;

    if ((fd = open(file, O_CREAT | O_TRUNC | O_RDWR, S_IRWXU)) == -1) {
        printf("%d error\n", __LINE__);
        exit(1);
    }
    ret = fcntl(fd, F_SETFL, O_APPEND);
    printf("%d\n", ret);
    ret = fcntl(fd, F_GETFL, 0);
    printf("ret=%d\n", ret);
    if (ret & O_APPEND) {
        printf("O_APPEND\n");
    }
    close(fd);


}


void print_file_info(char *file) {


    struct stat buf;
    int ret = stat(file, &buf);
    printf("ret=%d\n", ret);
    time_t time1 = time(0);
    long t1 = buf.st_ctime;
    printf("t1=%d\n", t1);

    printf("文件创建时间: %s", ctime(&buf.st_ctime));
    printf("访问日期: %s", ctime(&buf.st_atime));
    printf("最后修改日期: %s", ctime(&buf.st_mtime));


    //timespec1.tv_nsec;
    struct tm *t = localtime(&t1);
    printf("%ld\n", time1);

    printf("%d-%d-%d %d:%d:%d", 1900 + t->tm_year, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

}

int main(int argc, char **argv) {
    for (int i = 0; i <= sys_nerr; i++) {
        print_error(i);
    }

    // file_info("./t.log");
    print_file_info("./tcp");

}

