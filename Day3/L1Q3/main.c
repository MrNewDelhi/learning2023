#include <stdio.h>

int findLargestAfterDeletion(int num) {
    int largest = 0;
    int divisor = 1;

    // Iterate through each digit of the number
    while (divisor <= num) {
        int digit = (num / divisor / 10) * divisor + num % divisor;

        // Update the largest number if the current number is greater
        if (digit > largest) {
            largest = digit;
        }

        divisor *= 10;
    }

    return largest;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largestAfterDeletion = findLargestAfterDeletion(num);
    printf("Largest number after deleting a single digit: %d\n", largestAfterDeletion);

    return 0;
}
