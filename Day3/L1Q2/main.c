#include <stdio.h>

void printBits(unsigned int num) {
    int i;
    // Start from the leftmost bit (31st bit)
    for (i = 31; i >= 0; i--) {
        // Check if the current bit is set (1) or not (0)
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
}

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Bits: ");
    printBits(num);
    printf("\n");

    return 0;
}
