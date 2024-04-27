#include <stdio.h>
#define ASCENDING_SORT 
void getInput(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

#ifdef ASCENDING_SORT
void sortAscending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
#endif

#ifdef DESCENDING_SORT
void sortDescending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
#endif

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    getInput(arr, size);

    #ifdef ASCENDING_SORT
    sortAscending(arr, size);
    printf("Sorted in ascending order: ");
    #endif

    #ifdef DESCENDING_SORT
    sortDescending(arr, size);
    printf("Sorted in descending order: ");
    #endif

    printArray(arr, size);

 return 0;
}
