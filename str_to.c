//
// Created by tomcat on 2019-03-29.
//


#include "m.h"


double my_sqrt(double x) {
    assert(x >= 0.0);
    return sqrt(x);
}


int main(int argc, char *argv[]) {


    char msg[] = "java c++ php";
    char *to;
    char *sp = " ";
    char *t;

    for (t = strtok_r(msg, sp, &to); t != NULL; t = strtok_r(NULL, sp, &to)) {
        printf("%s\n", t);
    }

    char *nums = "2134454.67fsfv";
    char *end;
    long s = strtol(nums, NULL, 10);
    double d = strtod("1235.6897hvg", NULL);

    printf("%ld -- %f\n", s, d);

    char *a = strpbrk("jvascfrtp1234", "cf3ffc");
    printf("%s\n", a);
    my_sqrt(-0.6);
    return 0;

}