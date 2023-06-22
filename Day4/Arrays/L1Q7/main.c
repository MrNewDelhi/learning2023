#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int binaryToDecimal(long long binary) {
    int decimal = 0;
    int base = 1;

    while (binary > 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * base;
        binary /= 10;
        base *= 2;
    }

    return decimal;
}

int octalToDecimal(int octal) {
    int decimal = 0;
    int base = 0;

    while (octal > 0) {
        int lastDigit = octal % 10;
        decimal += lastDigit * pow(8, base);
        octal /= 10;
        base++;
    }

    return decimal;
}

int hexadecimalToDecimal(char hexadecimal[]) {
    int decimal = 0;
    int length = strlen(hexadecimal);
    int base = 1;

    for (int i = length - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - '0') * base;
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 'A' + 10) * base;
        }
        base *= 16;
    }

    return decimal;
}

int main() {
    int choice;
    char number[100];

    printf("Choose conversion type:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Octal to Decimal\n");
    printf("3. Hexadecimal to Decimal\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a binary number: ");
            scanf("%s", number);
            printf("Decimal: %d\n", binaryToDecimal(atoll(number)));
            break;
        case 2:
            printf("Enter an octal number: ");
            scanf("%s", number);
            printf("Decimal: %d\n", octalToDecimal(atoi(number)));
            break;
        case 3:
            printf("Enter a hexadecimal number: ");
            scanf("%s", number);
            printf("Decimal: %d\n", hexadecimalToDecimal(number));
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
