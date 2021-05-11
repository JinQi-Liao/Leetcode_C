#include <stdio.h>

#define min(X, Y) ((X) < (Y)) ? (X) : (Y)

int main() {
	printf("this min is %d\n", min(3,4));
	return 0;
}