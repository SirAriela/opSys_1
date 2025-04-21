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
    //1.2
    // int x = division(10, 0);
    // printf("x = %d\n", x);

    //1.1
    int y = recusive_fun(-3);

    // //1.3
    // int z = memmory();
    // printf("%d\n", z);
    return 0;
}