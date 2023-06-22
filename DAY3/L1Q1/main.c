#include <stdio.h>

void printDecreasing(int n) {
    int i;
    for (i = n; i >= 1; i--) {
        printf("%d", i);
    }
}

void printSpaces(int n) {
    int i;
    for (i = 1; i <= 2 * (n - 1); i++) {
        printf(" ");
    }
}

void printIncreasing(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d", i);
    }
}

void printPattern(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printDecreasing(n - i + 1);
        printSpaces(i - 1);
        printIncreasing(n - i + 1);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printPattern(n);

    return 0;
}
