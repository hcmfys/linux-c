//
// Created by tomcat on 2019-03-24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc,char*argv[]) {


    char *weeks[7];
    weeks[0] = "星期天";
    weeks[1] = "星期一";
    weeks[2] = "星期二";
    weeks[3] = "星期三";
    weeks[4] = "星期四";
    weeks[5] = "星期五";
    weeks[6] = "星期六";

    char **p = weeks;
    printf("%p\n", p);
    char **p_last = weeks+6;
    printf("%p\n", p_last);
    for (; *p < p_last; *p++) {
        printf("%s\n", *p);
    }

}

