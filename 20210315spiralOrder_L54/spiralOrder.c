#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    // 动态分配一个二维数组，并初始化
    int rows = matrixSize, columns = matrixColSize[0];
    int** visited = (int**) malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; ++i) {
        visited[i] = (int*) malloc(sizeof(int) * columns);
        memset(visited[i], 0, sizeof(int) * columns);
    }

    //这个用法有问题？？memset里面第一个参数是void* Dest
    //memset(visited, 0, sizeof(visited));

    //对结果数组进行动态分配
    int total = rows * columns;
    *returnSize = total;
    int* order = (int*) malloc(sizeof(int) * total);


    int row = 0, column = 0;
    int directionIndex = 0;
    for (int i = 0; i < total; i++) {
        // 不能用这种方式进行访问二维数组中的元素吗？？，这样会出现Segment Fault
        //order[i] = matrix[row][column];
        // order[i] = *(*(matrix + row) + column);

        order[i] = *((int*)matrix + row * columns + column);

        visited[row][column] = 1;
        int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
        if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
            directionIndex = (directionIndex + 1) % 4;
        }
        row += directions[directionIndex][0];
        column += directions[directionIndex][1];
    }
    return order;
}

int main() {
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int matrixSize = 3;
    int matrixColsize = 3;
    int returnSize = 0;

    //二维数组的传参问题???
    int* order = spiralOrder((int**)matrix, matrixSize, &matrixSize, &returnSize);
    for(int i = 0; i < returnSize; i++) {
        printf("%d ", order[i]);
    }
    return 0;
}