#include <stdio.h>
struct test {
    int id;
    char name[100];
    char class_id;
};

int main() {
    printf("Size of struct first: %lu bytes\n", sizeof(struct test));

    // Change the order of definition of the string to be the first
    struct test_modified {
        char name[100];
        int id;
        char class_id;
    };

    // Print the size of the struct with the modified order
    printf("Size of struct second : %lu bytes\n", sizeof(struct test_modified));

    return 0;
}
//The output will likely show a difference in size due to padding and alignment requirements imposed by the compiler.
