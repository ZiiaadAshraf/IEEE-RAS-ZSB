#include <stdio.h>

int x = 1, y = 2, z = 3;
int *p, *q, *r;
// i declared the function here before main to be visible to compiler
void printPointers(); 

int main() {
    p = &x;
    q = &y;
    r = &z;

    printPointers();
    printf("Swapping pointers\n");
    int *temp = r;
    r = p;
    p = q;
    q = temp;
    printPointers();
    return 0;
}

void printPointers() {
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    printf("p = %p\n", (void *)p);
    printf("q = %p\n", (void *)q);
    printf("r = %p\n", (void *)r);
    printf("*p = %d\n", *p);
    printf("*q = %d\n", *q);
    printf("*r = %d\n", *r);
}
