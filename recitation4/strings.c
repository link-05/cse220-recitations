#include <stdio.h>
#include <string.h>

int main() {
    // char *s = "Hello"; // String literal are not string arrays, to edit 2 options
    // // char s[] = "Hello"; //copy string literal into array
    // // char s[] = {'H', 'e', 'l', 'l', 'o'};
    // s[0] = 'h';
    // printf("%s\n", s);
    //sizeOf vs strlen
    char s[] = "Hello";
    printf("%d-%d\n", sizeof(s), strlen(s)); // 6 - 5, strlen does not inlcude null, size of pointer will be 8 byte if we pass in pointer.
    return 0;
}