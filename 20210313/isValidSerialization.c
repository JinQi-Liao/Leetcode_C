#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/*
typedef unsigned int bool;
*/

typedef enum {
    false,
    true
} bool;

bool isValidSerialization(char * preorder){
    int n = strlen(preorder);
    int* stk = (int*) malloc(sizeof(int) * n);
    int top = 0;
    stk[top++] = 1;
    int i = 0;
    while (i < n)
    {
        /* code */
        if (!top) {
            return false;
        }
        if (preorder[i] == ',') {
            i++;
        }
        else if (preorder[i] == '#') {
            stk[top - 1] -= 1;
            if (stk[top-1] == 0) {
                top--;
            }
            i++;
        }
        else {
            while (i < n && preorder[i] != ',')
            {
                i++;
            }
            stk[top-1] -= 1;
            if (stk[top-1] == 0) {
                top--;
            }
            stk[top++] = 2;
            
        }
    }

    return !top;

}

int main() {
    char s[] = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    bool res = isValidSerialization(s);
    return 0;
}