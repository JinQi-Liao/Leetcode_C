#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef enum {false, true} bool;
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int m = matrixSize;
    int n = matrixColSize[0];
    int* row = (int*) malloc(sizeof(int) * n);
    int* col = (int*) malloc(sizeof(int) * n);
    memset(row, 0, sizeof(int) * m);
    memset(col, 0, sizeof(int) * n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!matrix[i][j]) {
                row[i] = col[j] = true;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

}

int main() {

}