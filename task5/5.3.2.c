#include <stdio.h>

#define ADD(a, b) (a + b)
#define SUBTRACT(a, b) (a - b)

int main() {
    int option, num1, num2;
    
    while(1) {
        printf("Enter option:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Exit\n");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%d %d", &num1, &num2);
                printf("Result: %d\n", ADD(num1, num2));
                break;
                
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%d %d", &num1, &num2);
                printf("Result: %d\n", SUBTRACT(num1, num2));
                break;
                
            case 3:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid option\n");
        }
    }

 return 0;
}