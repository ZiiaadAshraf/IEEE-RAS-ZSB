#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct info {
    char name[100];
    int age;
};

int main() {
    struct info person;
    struct info *ptr_person;
    ptr_person = &person;
    strcpy(person.name, "ziad");
    person.age = 22;
    printf("Name: %s\n", ptr_person->name);
    printf("Age: %d\n", ptr_person->age);

    return 0;
}
