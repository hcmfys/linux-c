//
// Created by tomcat on 2019-03-25.
//

//
// Created by tomcat on 2019-03-24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char * bad_ret(){
    char *p="user-name-x";
    //char p[]="user-name-x";
    printf("%p\n",p);
    return  p;
}

int find_num_string(char* outputstr,char *inputstr) {
    char *in = inputstr;
    char *out = outputstr;
    char *temp;
    char *final;
    int count = 0;
    int maxlen = 0;
    while (*in != '\0') {
        if (*in > 47 && *in < 58) {
            for (temp = in; *in > 47 && *in < 58; in++) {
                count++;
            }
        } else {
            in++;
        }

        if (maxlen < count) {
            maxlen = count;
            final = temp;
        }
        count = 0;
    }

    printf("temp=%s\n",temp);
    printf("final=%s\n",final);
    printf("in=%s\n",in);

    strncpy(out,final,maxlen);
    for (int i = 0; i < maxlen; i++) {
        //*out = *final;
        //out++;
       // final++;
    }
    *(out+maxlen) = '\0';
    return maxlen;
}





void reverse(char *p) {

    int length=strlen(p);
    char *p1=p;
    char *p2=p+length-1;
    while (p1<p2){
        char c=*p1;
        *p1=*p2;
        *p2=c;
        ++p1;
        --p2;
    }
}


int main(int argc,char*argv[]) {


    char strings[] = "abc1234567890f55b55123";
    char *p = (char *) malloc(strlen(strings) + 1);
    int cont = find_num_string(p, strings);
    printf("%s\n numbers=%d\n", p, cont);

    char p2[]= "12345678";
    reverse(p2);
    printf("p2=%s\n", p2);

    int a[10];


}

