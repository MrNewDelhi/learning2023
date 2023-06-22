#include <stdio.h>

int main() {
    float num1, num2;
    char operator;

    // Read the first operand
    printf("Enter Number1: ");
    scanf("%f", &num1);

    // Read the operator
    printf("Enter the operator: ");
    scanf(" %c", &operator);

    // Read the second operand
    printf("Enter Number2: ");
    scanf("%f", &num2);

    // Perform calculation based on the operator
    float result;
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                return 1;  // Exit the program with an error code
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            return 1;  // Exit the program with an error code
    }

    // Print the result
    printf("Result: %.2f\n", result);

    return 0;
}
