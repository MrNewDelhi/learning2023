#include <stdio.h>
#include <string.h>

char *xstrchr(char *string, char ch) {
    while (*string != '\0') {
        if (*string == ch) {
            return string;  // Character found, return pointer to the first occurrence
        }
        string++;  // Move to the next character in the string
    }

    return NULL;  // Character not found, return NULL
}

int main() {
    char str[100];
    char ch;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character from the input

    printf("Enter a character to search: ");
    scanf(" %c", &ch);

    char *result = xstrchr(str, ch);

    if (result != NULL) {
        printf("Character '%c' found at position: %ld\n", ch, result - str);
    } else {
        printf("Character '%c' not found in the string.\n", ch);
    }

    return 0;
}
