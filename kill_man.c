//
// Created by tomcat on 2019-03-26.
//
#include "m.h"

void kill_man(int *man, int n, int s, int m) {
    for (int i = 0; i < n; i++) {
        man[i] = 1;
    }

    int temp = s;
    int counts = 0;
    int left = 0;
    while (1) {

        temp++;
        if (temp >= n) {
            temp = 0;
        }
        if (man[temp] == 1) {
            counts++;
        }

        if (counts == m) {
            man[temp] = 0;
            counts = 0;
            left++;
            if (left == n - 1) {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (man[i] == 1) {
            printf("%d is winner\n", i);
        }

    }


}


int main(int argc, char *argv[]) {


    int a[10];
    kill_man(a, 10, 2, 7);


}
