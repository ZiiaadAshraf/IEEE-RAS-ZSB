#include <stdio.h>
enum Operation {
    ADD = '+',
    SUBTRACT = '-',
    MULTIPLY = '*',
    DIVIDE = '/',
    AND = '&',
    OR = '|',
    NOT = '!'
};

float calculate(float operand1, float operand2, enum Operation operation) {
    switch (operation) {
        case ADD:
            return operand1 + operand2;
        case SUBTRACT:
            return operand1 - operand2;
        case MULTIPLY:
            return operand1 * operand2;
        case DIVIDE:
            return operand1 / operand2;
        case AND:
            return (int)operand1 & (int)operand2;
        case OR:
            return (int)operand1 | (int)operand2;
        case NOT:
            return ~(int)operand1;
        default:
            return 0.0f;
    }
}

int main() {
    float operand1, operand2;
    char operationChar;
    enum Operation operation;

    printf("Enter first operand: ");
    scanf("%f", &operand1);

    printf("Enter operation (+, -, *, /, &, |, !): ");
    scanf(" %c", &operationChar);
    operation = operationChar;

    printf("Enter second operand: ");
    scanf("%f", &operand2);

    float result = calculate(operand1, operand2, operation);
    printf("Result: %.2f\n", result);

 return 0;
}
/*
 The size of the enum Operation is compiler-dependent. It is usually the size of an integer (4 bytes on most systems)
 because enums are typically implemented as integers.If additional members are added to the enum, the size of the enum 
 may remain the same because enums are often padded to align with the size of an integer
*/
