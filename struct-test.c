//
// Created by tomcat on 2019-03-26.
//
#include "m.h"

struct student {

    int number;
    char name[20];
    int age;
    char addr[30];
};
union  data{
    int i;
    char c;
};

int main() {

    struct student s[3] = {
            {12,  "java",  'a', "hcmfys"},
            {120, "javfa", 'a', "ghbd"},
            {128,  "jacva", 'a', "ggbvd"}
    };
    struct student *p;
    for (p = s; p < s + 3; p++) {
        printf("%s %d \n", (*p).addr, (*p).age);
    }
    union data c;
    c.c='a';
    c.i=1;
    printf("%d\n",c.c);
    printf("%c\n",c.i);
    return 0;
}

