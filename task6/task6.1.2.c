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
    free(ptr2);

    int ptr4 = (int)malloc(2 * sizeof(int));
    if (ptr4 == NULL) {
        printf("Memory allocation failed for ptr4\n");
        free(ptr1); 
        return 1;
    }
    ptr4[0] = 40;
    ptr4[1] = 50;

    printf("Value of ptr1: %d\n", *ptr1);
    printf("Values of ptr4: %d, %d\n", ptr4[0], ptr4[1]);

    free(ptr1);
    free(ptr4);

 return 0;
}