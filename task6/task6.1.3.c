#include <stdio.h>
#include <string.h>
int main() {
    int maxLength;
    printf("Enter the maximum length for the name: ");
    scanf("%d", &maxLength);

    char name[maxLength + 1]; 
    printf("Enter your name: ");
    scanf(" %[^\n]s", name);

    printf("Name entered: %s\n", name);

    int charFrequancy[256] = {0}; 

    for (int i = 0; i < strlen(name); i++) {
        charFrequancy[name[i]]++;
    }

    int maxFrequancy = 0;
    char mostRepeatedChar;
    for (int i = 0; i < 256; i++) {
        if (charFrequancy[i] > maxFrequancy) {
            maxFrequancy = charFrequancy[i];
            mostRepeatedChar = (char)i;
        }
    }

    printf("Most repeated character: %c, Frequency: %d\n", mostRepeatedChar, maxFrequancy);

return 0;
}