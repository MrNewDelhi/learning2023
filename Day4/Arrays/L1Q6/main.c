#include <stdio.h>

// Function to find the difference between even-indexed and odd-indexed elements
int findDifference(int arr[], int size) {
    int sumEvenIndex = 0;
    int sumOddIndex = 0;

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            sumEvenIndex += arr[i];  // Add even-indexed element to sumEvenIndex
        } else {
            sumOddIndex += arr[i];   // Add odd-indexed element to sumOddIndex
        }
    }

    return sumEvenIndex - sumOddIndex;  // Return the difference
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int difference = findDifference(arr, size);

    printf("Difference between sum of even-indexed and odd-indexed elements: %d\n", difference);

    return 0;
}
