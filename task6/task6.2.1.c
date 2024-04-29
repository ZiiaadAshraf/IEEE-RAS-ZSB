#include <stdio.h>
int main() {
    int hours, minutes, seconds;

    printf("Enter time [hh:mm:ss]: ");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);

    int time = hours * 3600 + minutes * 60 + seconds;

    printf("Time entered: %02d:%02d:%02d\n", hours, minutes, seconds);

    printf("Time stored in a single integer: %d seconds\n", time);

 return 0;
}