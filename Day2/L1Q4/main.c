#include <stdio.h>

int countSetBits(int arr[], int size) {
    int totalBits = 0;

    for (int i = 0; i < size; i++) {
        int num = arr[i];

        while (num > 0) {
            totalBits += num & 1;  // Check if the least significant bit is set
            num >>= 1;            // Right shift the number to consider the next bit
        }
    }

    return totalBits;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array (in hexadecimal format):\n");
    for (int i = 0; i < size; i++) {
        scanf("%x", &arr[i]);
    }

    int result = countSetBits(arr, size);

    printf("Total number of set bits: %d\n", result);

    return 0;
}
