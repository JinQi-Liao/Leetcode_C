#include <stdio.h>
#include <malloc.h>
#include <uhash.h>

// #1、暴力算法
/*
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
} */ 


// #2、使用哈希表实现这个功能
struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;// ??C语言库自带的函数？
};

// 定义一个全局变量的hashtable
struct hashTable* hashtable;

struct hashTabele* find(int ikey) {
    struct hashTable* tmp;
    HASH_FIND_INT(hashtable,&ikey, tmp); //
    return tmp;
}

void insert(int ikey, int ival) {
    struct hashTable* it = find(ikey);
    if (it == NULL) {
        struct hashTable* tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey,tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp); //
    }
    else {
        it->val = ival;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 先将哈希表置空
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* it = find(target - nums[i]);
        if (it != NULL) {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;
        }
    }

    // 考虑如果没有答案的话
    *returnSize = 0;
    return NULL;
}


int main() {
    int nums[] = {2,7,9,11};
    int returnSize;
    int * res = twoSum(nums, 4, 9, &returnSize);
    free(res);
    return 0;
}