//
// Created by tomcat on 2019-03-25.
//



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void reverse(char *p) {
    if (*p == '\0') {
        return;
    }
    //printf("-->\n");
    reverse(p + 1);
    printf("%c", *p);
}


int main(int argc, char *argv[]) {

    reverse("abcdf");


}

