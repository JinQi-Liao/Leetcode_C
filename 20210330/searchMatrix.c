#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    false,
    true
} bool;


// 1、暴力法
bool searchMatrix1(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize;
    int n = matrixColSize[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == target) {
                return true;
            }
        }
    }

    return false;
}

//2、 直接二分查找：先降维，然后查找;这个思路对整个数组进行了两次扫描不行
bool searchMatrix2(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int size = m * n;
    int* array = (int*) malloc(sizeof(int) * size);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
             *(array + i* m + j) = *((int*)matrix + i * m + j);
            
        }
    }

    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if ( target < array[mid] ) {
            right = mid - 1;
        }
        else if (array[mid] < target) {
            left = mid + 1;
        }
        else {
            return true;
        }
    }

    return false;
    
}


// 3、先对列进行二分查找，再对行进行二分查找
int binarySearchFirstColumn(int** matrix, int matrixSize, int target) {
    int low = -1, high = matrixSize - 1;
    while (low < high) {
        int mid = (high - low + 1) / 2 + low;
        if (matrix[mid][0] <= target) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

bool binarySearchRow(int* row, int rowSize, int target) {
    int low = 0, high = rowSize - 1;
    while (low <= high) {
        int mid = (high - low) / 2 + low;
        if (row[mid] == target) {
            return true;
        } else if (row[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int rowIndex = binarySearchFirstColumn(matrix, matrixSize, target);
    if (rowIndex < 0) {
        return false;
    }
    return binarySearchRow(matrix[rowIndex], matrixColSize[rowIndex], target);
}





int main() {
    int matrix[3][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int matrixSize = 3;
    int matrixColsize = 4;
    bool res = searchMatrix2((int**)matrix, matrixSize, &matrixColsize, 3);

    return 0;
}