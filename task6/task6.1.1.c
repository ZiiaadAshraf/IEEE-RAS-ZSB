#include <stdio.h>
#include <stdlib.h>
int main() {

    int ptr1 = (int)malloc(sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory allocation failed for ptr1\n");
        return 1;
    }
    *ptr1 = 10;

    int ptr2 = (int)calloc(1, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation failed for ptr2\n");
        free(ptr1); 
        return 1;
    }
    *ptr2 = 20;

    int ptr3 = (int)realloc(ptr2, 2 * sizeof(int));
    if (ptr3 == NULL) {
        printf("Memory reallocation failed for ptr3\n");
        free(ptr1); 
        free(ptr2);  
        return 1;
    }
    ptr3[1] = 30;

    printf("Value of ptr1: %d\n", *ptr1);
    printf("Value of ptr2: %d\n", *ptr2);
    printf("Values of ptr3: %d, %d\n", ptr3[0], ptr3[1]);

    free(ptr1);
    free(ptr3);

 return 0;
}