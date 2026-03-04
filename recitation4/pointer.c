#include <stdio.h>

// int foo() { //crash
//     int x = 100;
//     return &x;
// }

int main() {
    // int x = 5;
    // printf("%d\n", x++ + ++x); // Undefined Behavior
    // return 0;
    //---
    // int i = 10;
    // int *p = &i;
    // int *q = p;
    // *q = 20;

    // printf("%d-%d\n", i, *p);
    //---
    // int *p = foo();
    // printf("%d\n", *p);
    // ---
    // int a[] = {1, 2, 3, 4, 5};
    // int *p = a;
    // printf("%d=%d\n", a[2], *(p+2));

    // return 0;
    //---
    int arr[10]; // Arr size = 4 byte per int, 10 int
    int *p = arr; // Decompose all the info, int ptr, 
    // 32 bit cpu ptr = 32 byte/8 = 4 byte,
    // 64 bit cpu ptr = 64 byte/8 = 8 byte
    printf("%d-%d\n", sizeof(arr), sizeof(p));
}