#include <stdio.h>

#define OPERATION(op, a, b) \
    ({                      \
        float result;       \
        switch (op)         \
        {                   \
        case '+':           \
            result = a + b; \
            break;          \
        case '-':           \
            result = a - b; \
            break;          \
        case '*':           \
            result = a * b; \
            break;          \
        case '/':           \
            result = (b == 0) ? 0 : (a / b); \
            break;          \
        default:            \
            printf("Invalid operation\n"); \
            result = 0;     \
            break;          \
        }                   \
        result;             \
    })

int main() {
    float num1, num2, result;
    char choice;

    while (1) {
        printf("\nMenu\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == '5') {
            break;
        }

        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);

        result = OPERATION(choice, num1, num2);
        printf("Result: %.2f\n", result);
    }

 return 0;
}



/*Conditional compilation directives (#ifdef, #else, #endif) decide which code gets
 included in the final program before compilation, while if-else statements control 
 the flow of execution at runtime. The preprocessor evaluates conditions in directives,
 while the compiler evaluates conditions in if statements.if-else decides what code runs
 during the program based on conditions. 
  #ifdef-#else decides what code gets included in the compiled program itself 
  based on pre-defined conditions.
  */