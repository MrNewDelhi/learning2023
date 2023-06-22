#include <stdio.h>

int compareBoxes(int A[], int B[], int size) {
    int count[size];

    // Initialize count array with all elements as 0
    for (int i = 0; i < size; i++) {
        count[i] = 0;
    }

    // Count the occurrences of items in Box A
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (A[i] == B[j]) {
                count[j]++;
                break;
            }
        }
    }

    // Check if each item in Box B has a one-to-one mapping in Box A
    for (int i = 0; i < size; i++) {
        if (count[i] != 1) {
            return 0;  // Not a one-to-one mapping
        }
    }

    return 1;  // One-to-one mapping exists
}

int main() {
    int size;
    printf("Enter the size of the boxes: ");
    scanf("%d", &size);

    int A[size];
    int B[size];

    printf("Enter the items in Box A:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the items in Box B:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &B[i]);
    }

    int result = compareBoxes(A, B, size);

    if (result == 1) {
        printf("There is a one-to-one mapping of items in the boxes.\n");
    } else {
        printf("There is no one-to-one mapping of items in the boxes.\n");
    }

    return 0;
}
