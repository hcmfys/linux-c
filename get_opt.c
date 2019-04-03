//
// Created by tomcat on 2019-03-30.
//

#include "m.h"
int main(int argc,char *argv[]) {

    int opt=0;
    while (( opt=getopt(argc,argv,":ltf:m")) !=-1){
        switch(opt) {

            case 'l':
                printf(" l is good");
                break;
            case 'f':
                printf(" f need a file-name %s\n",optarg);
                break;
            case ':':
                printf("bad options");
                break;
            case '?':
                printf(" ---?? =%c\n",optopt);
                break;
        }
    }
    for(;optind<argc;optind++) {
        printf("argment %s\n", argv[optind]);
    }

}