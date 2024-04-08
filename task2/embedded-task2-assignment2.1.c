#include <stdio.h>
void increment(int *num) {
    (*num)++;
}

int main() {
    int value = 5;
    int *ptr = &value; 

    printf("Before increment: value = %d\n", value);
    increment(ptr); 
    printf("After increment: value = %d\n", value);

    return 0;
}
