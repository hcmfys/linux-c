//
// Created by tomcat on 2019-03-26.
//
#include "m.h"

#define  MAX_XY(x,y) (x) * (y)

void kill_man(int *man, int n, int s, int m) {
    for (int i = 0; i < n; i++) {
        man[i] = 1;
    }

    int temp = s;
    int counts = 0;
    int left = 0;
    int winner = -1;
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
                winner = temp;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {

        printf("%d ", man[i]);
        if (man[i] == 1) {

            winner = i;
        }

    }


    printf("\n %d is winner\n",winner);


}


int main(int argc, char *argv[]) {


    int a[10];
    kill_man(a, 10, 6, 8);
    int x=MAX_XY(2,3);
    printf("%d\n",x);


}
