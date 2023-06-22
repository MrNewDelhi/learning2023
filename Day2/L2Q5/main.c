#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] += 1; // Increment ASCII value of each character by 1
    }
}

void decode(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] -= 1; // Decrement ASCII value of each character by 1
    }
}

int main() {
    char originalString[100];
    printf("Enter the original string: ");
    fgets(originalString, sizeof(originalString), stdin);
    originalString[strcspn(originalString, "\n")] = '\0'; // Remove newline character from the input

    encode(originalString);
    printf("Encoded string: %s\n", originalString);

    decode(originalString);
    printf("Decoded string: %s\n", originalString);

    return 0;
}
