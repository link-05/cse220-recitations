#include <stdio.h>
#include <string.h>

void modifyValue(int x); // wrong approach
void modifyValueByReference(int *x); // correct approach
void swap2(int a, int b); // wrong approach
void swap(int *a, int *b); // correct approach
int printArray(int *arr, int size);
void printCharacters(char *str);

int main()
{
    printf("===== PASS BY VALUE vs PASS BY REFERENCE=====\n");
    // Pass by value: a copy of the value is passed to the function, 
    // so changes to the parameter do not affect the original variable.
    int num = 10;
    printf("Before modifyValue: %d\n", num);
    modifyValue(num);
    printf("After modifyValue: %d\n", num);
    // Pass by reference: a reference (or pointer) to the original variable is passed
    //  to the function, so changes to the parameter do affect the original variable.
    printf("Before modifyValueByReference: %d\n", num);
    modifyValueByReference(&num);
    printf("After modifyValueByReference: %d\n", num);

    printf("===== SWAP USING VALUES=====\n");
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap2(x, y);
    printf("After swap: x = %d, y = %d\n", x, y);

    x = 5, y = 10;
    printf("Before swap2: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap2: x = %d, y = %d\n", x, y);

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = printArray(arr, size);
    printf("Sum of array: %d\n", sum);

    printf("===== STRING MANIPULATION=====\n");
    char string[] = "stonybrook";
    printf("Original String: %s\n", string);
    printCharacters(string);

    return 0;
}

void modifyValue(int x)
{
    x = x + 10;
}

void modifyValueByReference(int *x)
{
    *x = *x + 10;
}

void swap2(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int printArray(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        // arr = 0x10
        // arr + 1 = 0x14
        // arr + 2 = 0x18
        // arr + i = 0x10 + sizeOf(int) * i

        sum += *(arr + i); // equivalent to sum += arr[i];
    }
    return sum;
}

void printCharacters(char *str)
{
    while(*str != '\0') {
        printf("%c ", *str);
        str++;
    }
    // or we can also do
    while (*str) {
        printf("%c ", *str);
        // str = 0x0
        str++;
        // str = 0x1
    }
    printf("\n");
}

void toUpperCase(char *str)
{
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32;
        }
        str++;
    }
}
