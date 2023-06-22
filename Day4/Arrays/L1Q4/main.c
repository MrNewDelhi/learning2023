#include <stdio.h>

// Function to find the difference between even and odd elements
int findDifference(int arr[], int size) {
    int sumEven = 0;
    int sumOdd = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            sumEven += arr[i];  // Add even element to sumEven
        } else {
            sumOdd += arr[i];   // Add odd element to sumOdd
        }
    }

    return sumEven - sumOdd;  // Return the difference
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int difference = findDifference(arr, size);

    printf("Difference between sum of even and odd elements: %d\n", difference);

    return 0;
}
