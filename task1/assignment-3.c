#include <stdio.h>
int compareStrings(char text1[], char text2[]) {
    int i = 0;
    while (text1[i] != '\0' || text2[i] != '\0') {
        if (text1[i] != text2[i]) {
            // return false if characters dont match
            return 0; 
        }
        i++;
    }
    if (text1[i] == '\0' && text2[i] == '\0') {
        return 1; 
    }
    // return false if they dont match
    return 0; 
}
// thats for the fourth code
void stringCopy(char text1[], char text2[]) {
    int i = 0;
    while (text1[i] != '\0') {
        text1[i] = text2[i];
        i++;
    }
    text2[i] = '\0'; 
}
int main()
{
    char text1[20];
    char text2[20];
    printf("Enter text1: ");
    scanf("%s", text1);
    printf("Enter text2: ");
    scanf("%s", text2);
    // printing text1 for the first code in assignmet 3
    printf("Your text is %s.", text1);
    printf("\n");
    // thats for the second code in assignment 3
    printf("Individual characters: ");
    for (int i = 0; text1[i] != '\0'; i++) {
        printf("%c ", text1[i]);
    }
    printf("\n");
    return 0;
}