#include <stdio.h>
typedef struct {
    float real;
    float imaginary;
} Complex;

Complex add(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

int main() {
    typedef unsigned int u_int;
    typedef int integer;
    typedef char character;
    typedef float floating_point;
    printf("Size of u_int: %lu bytes\n", sizeof(u_int));
    printf("Size of integer: %lu bytes\n", sizeof(integer));
    printf("Size of character: %lu bytes\n", sizeof(character));
    printf("Size of floating_point: %lu bytes\n", sizeof(floating_point));

    Complex num1, num2, result;
    num1.real = 2.5;
    num1.imaginary = 3.7;
    num2.real = 1.3;
    num2.imaginary = 4.6;

    result = add(num1, num2);

    printf("Sum: %.2f + %.2fi\n", result.real, result.imaginary);

return 0;
}
