#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef enum {false, true} bool;


// 暴力解法
bool find132pattern1(int* nums, int numsSize){
    if (numsSize < 3) {
        return false;
    }
    for (int j = 1; j < numsSize - 1; j++) {
        // 查找j左边比nums[j]小的数
        for (int i = 0; i < j; i++) {
            if (nums[i] < nums[j]) {
                // 在查找j右边比nums[j]小且比nums[i]大的数
                for (int k = j + 1; k < numsSize; k++) {
                    if (nums[k] < nums[j] && nums[i] < nums[k]) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

// 贪心算法
bool find132pattern2(int* nums, int numsSize) {
    if (numsSize < 3) {
        return false;
    }
    int numMin = nums[0];
    for (int j = 1; j < numsSize; j++) {
        for (int k = numsSize - 1; k > j; k--) {
            if (numMin < nums[k] && nums[k] < nums[j]) {
                return false;
            }
        }
        numMin = fmin(numMin, nums[j]);
    }
    return false;

}

// 使用单调栈进行实现??一定要学会如何利用C语言数组来实现栈这种结构？？？
bool find132pattern(int* nums, int numsSize) {
    int n = numsSize;
    int* candidate_k = (int*) malloc(sizeof(int) * n);
    int top = 0;
    candidate_k[top++] = nums[n - 1];
    int max_k = INT_MIN;

    for (int i = n - 2; i >= 0; --i) {
        if (nums[i] < max_k) {
            return true;
        }
        while (top && nums[i] > candidate_k[top - 1]) {
            max_k = candidate_k[--top];
        }
        if (nums[i] > max_k) {
            candidate_k[top++] = nums[i];
        }
    }

    return false;
}


/*
bool find132pattern(int* nums, int numsSize) {
    if (numsSize < 3) {
        return false;
    }

    // 维护一个最小数组
    int n = numsSize;
    int* minNums = (int*) malloc( sizeof(int) * n);
    minNums[0] =  INT_MAX;
    for (int i = 1; i < n; i++) {
        minNums[i] = min(minNums[i-1], nums[i-1]);
    } 

    // 开始维护一个单调栈
    int* stack = (int* )malloc(sizeof(int) * n);
    int top = 0;
    for (int j = n - 1; j > 0; j--) {
        //确保了左边有比nums[j]小的数
        if (nums[j] > minNums[j]) {
            while (top && stack[top] < nums[j])
            {
                top--;
                stack[top] = nums[j]
            }
            
        }

    }

}*/

/*
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/132-pattern/solution/132mo-shi-by-leetcode-solution-ye89/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int main() {
    int nums[] = {3,1,4,2};
    int numsSize = 4;
    bool res = find132pattern(nums, numsSize);
    return 0;
}