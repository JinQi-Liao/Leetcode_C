#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 使用动态规划进行求解
// https://leetcode-cn.com/problems/distinct-subsequences/solution/bu-tong-de-zi-xu-lie-by-leetcode-solutio-urw3/
int numDistinct(char* s, char* t) {
    int m = strlen(s), n = strlen(t);
    if (m < n) {
        return 0;
    }

    // 动态分配数组dp[m+1][n+1]
    // dp[i][j] 表示在 s[i:] 的子序列中 t[j:] 出现的个数。
    long** dp = (long**) malloc(sizeof(long*) * (m + 1) );
    for (int i = 0; i < m + 1; i++) {
        dp[i] = (long*) malloc(sizeof(long) * (n + 1));
        memset(dp[i], 0, sizeof(long) * (n+1));
    }

    // 初始化边界条件
    for (int i = 0; i <= m; i++) {
        dp[i][n] = 1;
    }
    for (int i = m - 1; i >= 0; i--) {
        char sChar = s[i];
        for (int j = n - 1; j >= 0; j--) {
            char tChar = t[j];
            if (sChar == tChar) {
                 dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                // *((long*)dp + i*n + j) = *((long*)dp + (i+1)*n + j + 1) + *((long*)dp + (i+1)*n + j);
            }
            else {
                 dp[i][j] = dp[i+1][j];
                // *((long*)dp + i*n + j) = *((long*)dp + (i+1)*n + j);
            }
        }
    }

    return dp[0][0];
}

int main() {
    char* s = "babgbag";
    char* t = "bag";
    int res = numDistinct(s, t);
    printf("%d\n", res);
    return 0;
}