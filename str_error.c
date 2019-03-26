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

void print_error(int code){

    char *message=strerror(code);
    printf("%d: %s\n",code,message);
}


void  file_info(char *file){
    int ret;
    int fd;
    int access_mode;

    if((fd=open(file,O_CREAT |O_TRUNC| O_RDWR,S_IRWXU)) ==-1){
        printf("%d error\n",__LINE__);
        exit(1);
    }
    ret=fcntl(fd,F_SETFL,O_APPEND);
    printf("%d\n",ret);
    ret=fcntl(fd,F_GETFL,0);
    printf("ret=%d\n",ret);
    if(ret & O_APPEND) {
        printf("O_APPEND\n");
    }
    close(fd);


}

int  main(int argc,char **argv) {
    for(int i=0;i<=sys_nerr;i++) {
        print_error(i);
    }

    file_info("./t.log");

}

