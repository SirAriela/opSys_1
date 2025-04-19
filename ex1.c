#include "stdio.h"

// 1.1
//recursive function that exceeds from stack memory
int recusive_fun(int n) {
    if (n == 0) {
        return 1;
    }
    return n * recusive_fun(n - 1);
}

// 1.2
//devidion by 0 [=0]
int division(int a, int b) {
    return a / b;
}

// 1.3
//using not allocatad memmory
int memmory() {
    int *p = 0;
    *p = 10;
    return *p;
}

int main() {
    int x = division(10, 0);
    printf("x = %d\n", x);
    x = recusive_fun(-3);
    x = memmory();
    printf("%d\n", x);
    return 0;
}