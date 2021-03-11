#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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