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
    HashArray pHash;
    int result = 0;
    if ((result = hash_init_ex(&pHash, PJWHash, 2 * 1024, 0.75, 0, true)) != 0) {

        printf("file: "__FILE__", line: %d, " \
            "hash_init_ex fail, errno: %d, error info: %s", \
            __LINE__, result, STRERROR(result));
        return result;
    }
    char *key = "java";
    char *value = "javax";


    if ((result=hash_insert_ex(&pHash, key,
				strlen(key)+1, value,
				strlen(value)+1, true)) < 0) {
        printf("file: "__FILE__", line: %d, " \
            "hash_init_ex fail, errno: %d, error info: %s", \
            __LINE__, result, STRERROR(result));
        return result;
    }
        char to[20];
        int len = 20;
        memset(to, 0, 20);

        hash_get(&pHash, key, strlen(key) + 1, to, &len);

        printf("get values=%s ret=%d \n", to, result);
        hash_destroy(&pHash);
        return 0;
    }