//
// Created by tomcat on 2019-03-29.
//

#include "m.h"



#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
int sec;

void sigroutine(int signo) {
    printf("%d\n",signo);
    switch (signo) {
        case SIGALRM:
            printf("Catch a signal -- SIGALRM ");
            break;
        case SIGVTALRM:
            printf("Catch a signal -- SIGVTALRM ");
            break;
    }
    return;
}

int main(int argc,char *argv[]) {
    struct itimerval value,ovalue,value2;
    sec = 5;

    printf(" process id is %d ",getpid());
    signal(SIGALRM, sigroutine);
    signal(SIGVTALRM, sigroutine);

    value.it_value.tv_sec = 1;
    value.it_value.tv_usec = 0;
    value.it_interval.tv_sec = 1;
    value.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &value, &ovalue);

    value2.it_value.tv_sec = 0;
    value2.it_value.tv_usec = 500000;
    value2.it_interval.tv_sec = 0;
    value2.it_interval.tv_usec = 500000;
    setitimer(ITIMER_VIRTUAL, &value2, &ovalue);

    for (;;) ;
}