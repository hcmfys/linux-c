//
// Created by Administrator on 2019/4/2.
//


#include<stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define  bool int
#define  true 1
#define false 0


int get_line(char *buff,int size,FILE *f ) {
    char *p = buff;
    while (1) {
        int c = getc(f);
        if ((p - buff) >= size) {
            return -1;
        }
        if (c == -1) {
            return c;
        }
        if (c == '\r'  ||c=='\n') {
            break;
        }
       *p=c;
        p++;
    }
    *p='\0';
    return p - buff;
}


bool index_of( char **data_list,size_t length,  char * data) {
    char **p=data_list;
    size_t  n=length;
    while(n) {
        if( strcmp(*p,data)==0) {
            return  true;
        }
        n--;
        p++;
    }
    return  false;

}
/**
 *
 * @param file_path
 * @param source_list
 * @param length
 */
void read_makefile(char *file_path,char **source_list,size_t length ) {
    char *data_list[1024];
    char **p_data = data_list;
    FILE *f = fopen(file_path, "r");
    if (f) {
        char buffer[1024];
        while (get_line(buffer, sizeof(buffer), f) != -1) {
            char *token = NULL;
            for (token = strtok(buffer, " \t"); token != NULL; token = strtok(NULL, " \t")) {
                if (token != NULL) {
                    if (strlen(token) > 2) {
                        char *p = token;
                        p = p + strlen(token) - 2;
                        if (strcmp(p, ".c") == 0) {
                            if (!index_of(data_list, p_data - data_list, token)) {
                                int len = strlen(token) + 1;
                                *p_data = (char *) malloc(len);
                                memset(*p_data, 0, len);
                                strcpy(*p_data, token);
                                p_data++;
                            }
                        }
                    }
                }
            }
        }
        fclose(f);
    }else{
        printf("%s no file exists\n",file_path);
    }
    size_t len=p_data-data_list;
    char **pp=data_list;
   while(len--){
        printf(" %d--%s\n",len, *pp++);
        free(*pp);
    }
}

int main(int argc, char *argv[]) {
    char* data_list[1024];
    //D:\nginx-1.15.10\objs
    read_makefile("D:/nginx-1.15.10/objs/Makefile",data_list,1024);

}