#include <stdio.h>

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a / b;
}

int main() {
    float num1, num2, result;
    int choice;

    float (*operation)(float, float) = NULL;

    while (1) {
        printf("\nMenu\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);

        switch (choice) {
            case 1:
                operation = &add;
                break;
            case 2:
                operation = &subtract;
                break;
            case 3:
                operation = &multiply;
                break;
            case 4:
                operation = &divide;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

        result = (*operation)(num1, num2);
        printf("Result: %.2f\n", result);
    }

    return 0;
}