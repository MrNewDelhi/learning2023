#include <stdio.h>

// Function to set a bit at a specific position in an 8-bit number
unsigned char setBit(unsigned char num, int position) {
    return num | (1 << position);
}

// Function to clear a bit at a specific position in an 8-bit number
unsigned char clearBit(unsigned char num, int position) {
    return num & ~(1 << position);
}

// Function to toggle a bit at a specific position in an 8-bit number
unsigned char toggleBit(unsigned char num, int position) {
    return num ^ (1 << position);
}

int main() {
    unsigned char num = 0b01010101;  // Example 8-bit number

    printf("Original Number: 0x%02X\n", num);

    // Set bit at position 3
    num = setBit(num, 3);
    printf("After Setting Bit: 0x%02X\n", num);

    // Clear bit at position 5
    num = clearBit(num, 5);
    printf("After Clearing Bit: 0x%02X\n", num);

    // Toggle bit at position 2
    num = toggleBit(num, 2);
    printf("After Toggling Bit: 0x%02X\n", num);

    return 0;
}
