#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSize) {
    int maxNum = n * n;
    int curNum = 1;
    int** matrix = (int**) malloc(sizeof(int*) * n);
    *returnSize = n;
    *returnColumnSize = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * n);
        memset(matrix[i], 0, sizeof(int) * n);

        //这个类型应该不可以访问
        (*returnColumnSize)[i] = n;
    }

    int row = 0, column = 0;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 右下左上
    int directionIndex = 0;
    while (curNum <= maxNum) {
        matrix[row][column] = curNum;
        curNum++;
        int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
        if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || matrix[nextRow][nextColumn] != 0) {
            directionIndex = (directionIndex + 1) % 4;  // 顺时针旋转至下一个方向
        }
        row = row + directions[directionIndex][0];
        column = column + directions[directionIndex][1];
    }
    return matrix;
}

int main() {
    
    int n = 3;
    int** returnColumnSizes = NULL;
    int returnSize = 0;
    int** matrix = generateMatrix(n, &returnSize, returnColumnSizes);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp = matrix[i][j];
            printf("%d ", temp);
        }
        printf("/n");
    }

    return 0;
}
