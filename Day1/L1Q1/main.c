#include <stdio.h>

int findBiggestUsingIfElse(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int findBiggestUsingTernary(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int main() {
    int num1;
    int num2;

    printf("Enter your 1st input :");
    scanf("%d",&num1);
    printf("Enter your 2nd input :");
    scanf("%d",&num1);

    int biggestUsingIfElse = findBiggestUsingIfElse(num1, num2);
    int biggestUsingTernary = findBiggestUsingTernary(num1, num2);

    printf("Using if-else: %d\n", biggestUsingIfElse);
    printf("Using ternary: %d\n", biggestUsingTernary);

    return 0;
}
