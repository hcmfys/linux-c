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


struct student get_student(){
    struct  student s;
    s.age=20;
    printf("-------%p\n",&s);
    return s;
}



void trim(char *data,int len){
    assert(len>=1);
    printf("len=%d\n",len);
    char *p=data;
    char *p_end=data+len-1;
    for(;;){
        if(*p==' ' || *p =='\t'){
            p++;
        }else{
            break;
        }
    }

    for(;;){
        if(*p_end==' ' || *p_end =='\t'){
            p_end--;
        }else{
            break;
        }
    }
    int start=p-data;
    int end=p_end-data;
    *(data+end+1)='\0';
    data=data+start;
    printf("%s\n",data);

}



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


    struct student my_student= get_student();
    printf("%d\n",my_student.age);
    printf("%p\n",&my_student);

    char buffer[20]="  jsp";
    trim(buffer,strlen(buffer));
    return 0;
}

