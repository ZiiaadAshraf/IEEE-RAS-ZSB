#include <stdio.h>
int main() {
    char stopCode[] = "!!";
    char input[100];

    while (1) {
        printf("Enter a string (Enter '!!' to stop): ");
        scanf("%s", input);

        int stop = 1;
        for (int i = 0; i < 2; i++) {
            if (input[i] != stopCode[i]) {
                stop = 0;
                break;
            }
        }
        if (stop) {
            printf("Stopping...\n");
            break;
        }

        char seen[256] = {0}; 
        printf("Unique characters: ");
        for (int i = 0; input[i] != '\0'; i++) {
            if (!seen[input[i]]) {
                printf("%c", input[i]);
                seen[input[i]] = 1;
            }
        }
        printf("\n");
    }

 return 0;
}