#include <stdio.h>

void printPattern(int n) {
    int i, j;
    int space = 0;
    for (i = n; i >= 1; i--) {
        // Print decreasing sequence
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // Print spaces
        for (j = 1; j <= space; j++) {
            printf(" ");
        }

        // Print increasing sequence
        for (j = i; j >= 1; j--) {
            printf("%d", j);
        }

        printf("\n");
        space += 2;
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printPattern(n);

    return 0;
}
