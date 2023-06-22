#include <stdio.h>
#include <string.h>

void swap(void* a, void* b, size_t size) {
    unsigned char* p = (unsigned char*)a;
    unsigned char* q = (unsigned char*)b;

    for (size_t i = 0; i < size; i++) {
        unsigned char temp = *(p + i);
        *(p + i) = *(q + i);
        *(q + i) = temp;
    }
}

int main() {
    char input1[100];
    char input2[100];

    printf("Enter the first value: ");
    scanf("%s", input1);

    printf("Enter the second value: ");
    scanf("%s", input2);

    printf("Before swapping: input1 = %s, input2 = %s\n", input1, input2);
    swap(input1, input2, sizeof(input1));
    printf("After swapping: input1 = %s, input2 = %s\n", input1, input2);

    return 0;
}
