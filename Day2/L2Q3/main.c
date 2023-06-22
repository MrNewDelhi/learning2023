#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortNames(char *names[], int size) {
    int i, j;
    char *temp;

    // Use bubble sort algorithm to sort the names
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap the names
                temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the number of names: ");
    scanf("%d", &size);

    char *names[size];
    printf("Enter the names:\n");
    for (int i = 0; i < size; i++) {
        char buffer[100];
        scanf("%s", buffer);

        names[i] = calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(names[i], buffer);
    }

    printf("Original Names:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", names[i]);
    }

    sortNames(names, size);

    printf("\nSorted Names:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
