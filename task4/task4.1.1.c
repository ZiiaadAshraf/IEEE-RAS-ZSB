#include <stdio.h>
#include <string.h>
struct student_info {
    int roll_number;
    int age;
    char address[100];
    char name[100];
    float marks;
};

int main() {
    struct student_info students[15];
    for (int i = 0; i < 15; i++) {
        students[i].roll_number = i + 1;
        students[i].age = 22 + i; 
        snprintf(students[i].address, sizeof(students[i].address), "Address%d", i + 1);
        snprintf(students[i].name, sizeof(students[i].name), "Student%d", i + 1);
        students[i].marks = 100.0 + i; 
    }

    // Print the information of each student
    printf("Roll Number\tName\t\tAge\tAddress\t\tMarks\n");
    for (int i = 0; i < 15; i++) {
        printf("%d\t\t%s\t\t%d\t%s\t\t%.2f\n", students[i].roll_number, students[i].name,
               students[i].age, students[i].address, students[i].marks);
    }

    return 0;
}
