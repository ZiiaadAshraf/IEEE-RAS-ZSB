#include <stdio.h>
int main() {
    int num1 = 10;
    char ch = 'A';
    long num2 = 1000;

    int *p1 = &num1;
    char *p2 = &ch;
    long *p3 = &num2;

    p1++;
    p2++;
    p3++;

    printf("the next integer in memory: %p\n", p1);
    printf("the next character in memory: %p\n", p2);
    printf("next long integer in memory: %p\n", p3);

return 0;
}