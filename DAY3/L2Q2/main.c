#include <stdio.h>

// Function to convert a decimal number to BCD format
unsigned char decimalToBCD(unsigned char decimal) {
    unsigned char tens = decimal / 10;
    unsigned char ones = decimal % 10;

    return (tens << 4) | ones;
}

int main() {
    unsigned char decimal = 45;  // Example decimal number

    printf("Decimal Number: %d\n", decimal);

    // Convert decimal to BCD
    unsigned char bcd = decimalToBCD(decimal);
    printf("BCD Format: 0x%02X\n", bcd);

    return 0;
}
