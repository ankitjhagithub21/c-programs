#include <stdio.h>
#include <string.h>

int main() {
    
    char inputString[100];
    int charCount[256] = {0}; // Assuming ASCII characters

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    
    inputString[strcspn(inputString, "\n")] = '\0';

    
    for (int i = 0; inputString[i] != '\0'; i++) {
        charCount[(int)inputString[i]]++;
    }

    printf("Character frequency in the string:\n");

    for (int i = 0; i < 256; i++) {
        if (charCount[i] > 0) {
            printf("Character '%c': %d times\n", (char)i, charCount[i]);
        }
    }

    return 0;
}
