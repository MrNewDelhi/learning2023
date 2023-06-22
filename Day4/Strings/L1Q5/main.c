#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotateString(char *str, int k, int left) {
    int len = strlen(str);
    char *temp = malloc((len + 1) * sizeof(char));

    // Normalize the rotation amount
    k = (k % len + len) % len;

    if (left) {
        // Rotate string to the left
        strncpy(temp, str + k, len - k);
        strncpy(temp + len - k, str, k);
    } else {
        // Rotate string to the right
        strncpy(temp, str + len - k, k);
        strncpy(temp + k, str, len - k);
    }

    temp[len] = '\0';

    strcpy(str, temp);
    free(temp);
}

int main() {
    char str[100];
    int k;
    int left;

    printf("Enter the string: ");
    scanf("%s", str);

    printf("Enter the rotation amount: ");
    scanf("%d", &k);

    printf("Enter 1 for left rotation or 0 for right rotation: ");
    scanf("%d", &left);

    rotateString(str, k, left);

    printf("Rotated string: %s\n", str);

    return 0;
}
