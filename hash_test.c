//
// Created by Administrator on 2019/3/30.
//

#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

  int hash_function(const void *key, const int key_len) {
      printf("%s size=%d\n", (char *) key, key_len);
      int hash_code= SDBMHash(key, key_len);
      printf("hash_code=%d\n",hash_code);
      return  hash_code;
  }
int main(int argc,char*argv[]) {
    HashArray hashArray;
    hash_init_ex(&hashArray, hash_function, 100, 0.72,1024,false);
    char *key = "java";
    char *value = "javax";
    hash_insert_ex(&hashArray, key, strlen(key), value,strlen(value),false);
    char to[20];
    int len = 0;
    memset(to,0,20);
    hash_get(&hashArray, key, strlen(key), to, &len);

    printf("get values=%s\n", to);
    hash_destroy(&hashArray);
    return 0;
}