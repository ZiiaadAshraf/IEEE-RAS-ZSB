#include <stdio.h>

struct student_info {
    unsigned int roll_number : 4;
    unsigned int age : 8;
    unsigned int marks : 3;
    char *address;
    char *name;
};

void print_student_info(struct student_info *student, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", student[i].roll_number);
        printf("Age: %d\n", student[i].age);
        printf("Marks: %d\n", student[i].marks);
        printf("Address: %s\n", student[i].address);
        printf("Name: %s\n", student[i].name);
        printf("\n");
    }
}

int main() {
    struct student_info students[15];

    for (int i = 0; i < 15; i++) {
        students[i].roll_number = i + 1;
        students[i].age = 18 + i;
        students[i].marks = i % 4;
        students[i].address = "Address";
        students[i].name = "Name";
    }

    print_student_info(students, 15);

    printf("Size of student_info struct: %lu bytes\n", sizeof(struct student_info));

 return 0;
}