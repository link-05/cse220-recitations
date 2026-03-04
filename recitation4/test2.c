#include <stdio.h>

int main(void) {
    // int *p;
    // *p = 10; //bug
    int i = 5, j = 10;
    int *p = &i;
    int *q = &j;

    *q = *p;

    printf("i = %d\n", i); // 5
    printf("j = %d\n", j); // 5
    printf("*q = %d\n", *q); // 5


    printf("%d\n", *p);
    return 0;
}