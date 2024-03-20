#include <stdio.h>
// thats a function to print duplicates and unique elemntes and in the same time counts the frequancy of each element
 void duplicatesAndUnique(int arr[], int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
// frequancy array for the third code in first assignment
    int freq[max + 1];
    for (int i = 0; i < max + 1; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    printf("duplicate elements in the array are: ");
    for (int i = 0; i < max + 1; i++) {
        if (freq[i] > 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("unique elements in the array are: ");
    for (int i = 0; i < max + 1; i++) {
        if (freq[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
// thats the function that add two numbers using pointers for the fourth one
void addNumbers(int *a, int *b, int *sum) {
    *sum = *a + *b;
} 

int main() {
    int arr[] = {1, 2, 3, 4, 1, 2, 5, 6, 7, 8, 9, 3, 5};
    int num1 = 10, num2 = 20, sum;
    int size = sizeof(arr) / sizeof(arr[0]);

    duplicatesAndUnique(arr, size);
    // here i pass the adress of the varaibels to the function
    addNumbers(&num1, &num2, &sum);

    printf("Sum: %d\n", sum);

    return 0;
}
