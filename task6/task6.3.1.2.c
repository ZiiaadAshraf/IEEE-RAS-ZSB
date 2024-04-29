#include <stdio.h>
inline size_t my_sizeof_inline(const void *ptr) {
    return (size_t)(&((char *)ptr)[1]);
}

int main() {
    int arr[10];
    double d;

    printf("Size of int array: %zu bytes\n", my_sizeof_inline(arr));
    printf("Size of double: %zu bytes\n", my_sizeof_inline(&d));

    return 0;
}
