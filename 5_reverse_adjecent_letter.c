#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseAdjacentLetters(char *str) {
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            int j = i + 1;
            while (j < len && isalpha(str[j])) {
                
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
                i = j + 1;
                j = i + 1;
            }
        }
    }
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove the newline character from input
    inputString[strcspn(inputString, "\n")] = '\0';

    reverseAdjacentLetters(inputString);

    printf("String with reversed adjacent letters: %s\n", inputString);

    return 0;
}
