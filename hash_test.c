//
// Created by Administrator on 2019/3/30.
//

#include "hash.h"
#include <string.h>
#include <stdio.h>

/**
 *
 * @param key
 * @param key_len
 * @return
 */
int hash_function(const void *key, const int key_len) {
    printf("%s size=%d\n", (char *) key, key_len);
    int hash_code = SDBMHash(key, key_len);
    printf("hash_code=%d\n", hash_code);
    return hash_code;
}

struct goods {
    long goods_id;
    int goods_name_length;
    char *goods_name;
};

int main(int argc, char *argv[]) {
    HashArray pHash;
    int result = 0;
    if ((result = hash_init_ex(&pHash, PJWHash, 2 * 1024, 0.75, 0, true)) != 0) {

        printf("file: "__FILE__", line: %d, "
               "hash_init_ex fail, errno: %d, error info: %s",
               __LINE__, result, STRERROR(result));
        return result;
    }


    struct goods food_goods;
    food_goods.goods_id = 12345;
    food_goods.goods_name = "我爱中国人";
    food_goods.goods_name_length = strlen(food_goods.goods_name) + 1;

    int len = sizeof(struct goods) + food_goods.goods_name_length * sizeof(char) + 1;

    if ((result = hash_insert_ex(&pHash, &food_goods.goods_id,
                                 sizeof(food_goods.goods_id), &food_goods,
                                 sizeof(food_goods), true)) < 0) {
        printf("file: "__FILE__", line: %d, "
               "hash_init_ex fail, errno: %d, error info: %s",
               __LINE__, result, STRERROR(result));
        return result;
    }

    struct goods foot;
    printf("%d -%d -%d \n", sizeof(long), sizeof(char*), sizeof(int));
    hash_get(&pHash, &food_goods.goods_id, sizeof(food_goods.goods_id), &foot, &len);
    printf("get values=%s ret=%d \n", foot.goods_name, result);
    hash_destroy(&pHash);
    return 0;
}