#include <stdio.h>

// Function to calculate the sum of an array
int calculateSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the average of an array
float calculateAverage(int arr[], int size) {
    int sum = calculateSum(arr, size);
    float average = (float)sum / size;
    return average;
}

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = calculateSum(arr, size);
    float average = calculateAverage(arr, size);

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}
