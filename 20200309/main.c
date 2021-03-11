#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define SWITCH 0

typedef unsigned char bool;

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
	if (numsSize == 0) {
		return NULL;
	}
	int* ret = (int*)malloc(sizeof(int) * numsSize);
	memset(ret, -1, sizeof(int) * numsSize);

	int *stk = (int*) malloc(sizeof(int) *(numsSize * 2 - 1));
	int top = 0;
	for (int i = 0; i < numsSize * 2 - 1; i++) {
		while (top > 0 && nums[stk[top - 1]] < nums[i % numsSize]) {
			ret[stk[top - 1]] = nums[i % numsSize];
			top--;
		}
		stk[top++] = i % numsSize;
	}
	return ret;
}


int minCut(char* s) {
	int n = strlen(s);
	
	// 使用malloc分配一个二维数组
	bool** g = (bool**) malloc(sizeof(bool) * n);
	for (int i = 0; i < n; ++i) {
		g[i] = (bool*) malloc(sizeof(bool) * n);
	}
	
	memset(g, 1, sizeof(g));

	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
		}
	}

	//int f[n];
	int* f = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i) {
		f[i] = INT_MAX;
	}
	for (int i = 0; i < n; ++i) {
		if (g[0][i]) {
			f[i] = 0;
		}
		else {
			for (int j = 0; j < i; ++j) {
				if (g[j + 1][i]) {
					f[i] = fmin(f[i], f[j] + 1);
				}
			}
		}
	}

	return f[n - 1];
}


char* removeDuplicates(char* S) {
	int n = strlen(S);
	char* stk = (char*)malloc(sizeof(char) * (n + 1));
	int retSize = 0;
	for (int i = 0; i < n; i++) {
		if (retSize > 0 && stk[retSize - 1] == S[i]) {
			retSize--;
		}
		else {
			stk[retSize++] = S[i];
		}
	}

	stk[retSize] = '\0';
	return stk;
}

/*
#ifdef SWITCH
int calculate(char* s) {
    int n = strlen(s);
	int* ops = (int*) malloc(sizeof(int) * n);
    int  top = 0;
    int sign = 1;
    ops[top++] = sign;

    int ret = 0;
    int i = 0;
    while (i < n) {
        if (s[i] == ' ') {
            i++;
        } else if (s[i] == '+') {
            sign = ops[top - 1];
            i++;
        } else if (s[i] == '-') {
            sign = -ops[top - 1];
            i++;
        } else if (s[i] == '(') {
            ops[top++] = sign;
            i++;
        } else if (s[i] == ')') {
            top--;
            i++;
        } else {
            long num = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                i++;
            }
            ret += sign * num;
        }
    }
    return ret;
}

#endif
*/

int calculate(char* s) {
    int n = strlen(s);
	int* stk = (int*) malloc(sizeof(int) * n);
    int  top = 0;
    char preSign = '+';
    int num = 0;
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            num = num * 10 + (int)(s[i] - '0');
        }
        if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
            switch (preSign) {
                case '+':
                    stk[top++] = num;
                    break;
                case '-':
                    stk[top++] = -num;
                    break;
                case '*':
                    stk[top - 1] *= num;
                    break;
                default:
                    stk[top - 1] /= num;
            }
            preSign = s[i];
            num = 0;
        }
    }
    int ret = 0;
    for (int i = 0; i < top; i++) {
        ret += stk[i];
    }
    return ret;
}


int main() {
	/*
    char S1[] = "1+1";
	char S2[] = "2-1+2";
	char S3[] = "(1+(4+5+2)-3)+(6+8)";
	int a1 = calculate(S1);
	int a2 = calculate(S2);
	#endif 0*/

	char S3[] = "3+2*2";
	int a3 = calculate(S3);
    system("pause");
	return 0;
}



