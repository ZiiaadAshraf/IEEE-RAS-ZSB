#include <stdio.h>
#define my_sizeof(type) sizeof(type)

int main() {
    int arr[10];
    printf("Size of arr: %ld\n", my_sizeof(arr));
    printf("Size of int: %ld\n", my_sizeof(int));
    return 0;
}
