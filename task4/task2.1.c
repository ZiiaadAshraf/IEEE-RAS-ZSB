#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct Date {
    int day;
    int month;
    int year;
};

bool compare(struct Date date1, struct Date date2) {
    if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char dateS1[20], dateS2[20];
    printf("Enter date 1 (DD/MM/YYYY): ");
    scanf("%s", dateS1);

    printf("Enter date 2 (DD/MM/YYYY): ");
    scanf("%s", dateS2);
    struct Date date1, date2;
    sscanf(dateS1, "%d/%d/%d", &date1.day, &date1.month, &date1.year);
    sscanf(dateS2, "%d/%d/%d", &date2.day, &date2.month, &date2.year);
    if (compare(date1, date2)) {
        printf("Dates are equal\n");
    } else {
        printf("Dates are not equal\n");
    }

    return 0;
}
