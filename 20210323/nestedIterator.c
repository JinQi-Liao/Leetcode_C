#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef enum {false, true} bool;
struct NestedInteger {

};

struct NestedIterator {
    int *vals;
    int size;
    int cur;
};

bool NestedIntegerIsInteger(struct NestedInteger* nestedInteger) {

}

int NestedIntegerGetInteger(struct NestedInteger* nestedInteger) {

}

int NestedIntegerGetListSize(struct NestedInteger* nestedInteger) {

}

void dfs(struct NestedIterator *iter, struct NestedInteger** nestedList, int nestedListSize) {
    for (int i = 0; i < nestedListSize; i++) {
        if (NestedIntegerIsInteger(nestedList[i])) {
            (iter->vals)[(iter->size)++] = NestedIntegerGetInteger(nestedList[i]);
        } else {
            dfs(iter, NestedIntegerGetList(nestedList[i]), NestedIntegerGetListSize(nestedList[i]));
        }
    }
}

struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize) {
    struct NestedIterator *ret = malloc(sizeof(struct NestedIterator));
    ret->vals = malloc(sizeof(int) * 20001);
    ret->size = 0;
    ret->cur = 0;
    dfs(ret, nestedList, nestedListSize);
    return ret;
}

bool nestedIterHasNext(struct NestedIterator *iter) {
    return iter->cur != iter->size;
}

int nestedIterNext(struct NestedIterator *iter) {
    return (iter->vals)[(iter->cur)++];
}

void nestedIterFree(struct NestedIterator *iter) {
    free(iter->vals);
    free(iter);
}




/*
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/flatten-nested-list-iterator/solution/bian-ping-hua-qian-tao-lie-biao-die-dai-ipjzq/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/