#include <stdio.h>
#include <string.h>
struct student_info {
    int roll_number;
    int age;
    char address[100];
    char name[100];
    float marks;
};
int printStudentInfo(struct student_info students[], int num_students) {
    int count = 0;

    printf("Roll Number\tName\t\tAge\tAddress\t\tMarks\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d\t\t%s\t\t%d\t%s\t\t%.2f\n", students[i].roll_number, students[i].name,
               students[i].age, students[i].address, students[i].marks);

        if (students[i].marks < 12.0) {
            count++;
        }
    }

    return count;
}

int main() {
    struct student_info students[15];
    for (int i = 0; i < 15; i++) {
        students[i].roll_number = i + 1;
        students[i].age = 22 + i; 
        snprintf(students[i].address, sizeof(students[i].address), "Address%d", i + 1);
        snprintf(students[i].name, sizeof(students[i].name), "Student%d", i + 1);
        students[i].marks = 8.0 + i; 
    }
    int count_low_marks = printStudentInfo(students, 15);
    printf("\nNumber of students with marks less than 12: %d\n", count_low_marks);

    return 0;
}
