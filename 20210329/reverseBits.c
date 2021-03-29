#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

/*
// #1、直接方法
int hammingWeight(uint32_t n) {
    int num = 0;
    while (n != 0)
    {
        uint32_t r = n % 2;
        if (r == 1) {
            num++;
        }
        n = n/2;
    }

   return num; 

}

// #2、按位方法
int hammingWeight2(uint32_t n) {
    int ret = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1u << i)) {
            ret++;
        }
    }

    return ret;
}

// #3、法2的进一步优化
int hammingWeight3(uint32_t n) {
    int ret = 0;
    while (n)
    {
        // n &= (n-1);
        n &= n-1;
        ret++;

    }
    return ret;
    
}
*/

// 使用移位技术进行实现
uint32_t reverseBits1(uint32_t n) {
    uint32_t res = 0;
    int nums = 0;
    while ( nums != 32)
    {
        uint32_t r = n % 2;
        res = (res<<1) + r; // 这里需要注意+, <<运算符的优先级
        n = n/2;
        nums++;
    }

   return res; 
}

uint32_t reverseBits2(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32 && n > 0; i++) {
        res |= (n & 1)<<(31-i);
        n = n>>1;
    }
    return res;
}

int main() {
    uint32_t n = 43261596;
    uint32_t res = reverseBits2(n);
    return 0;
}