#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box *box) {
    return box->length * box->width * box->height;
}

double calculateSurfaceArea(struct Box *box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {
    struct Box myBox;
    struct Box *boxPtr = &myBox;

    // Accessing structure members using indirection operator and dot operator
    (*boxPtr).length = 5.0;
    (*boxPtr).width = 3.0;
    (*boxPtr).height = 4.0;

    // Accessing structure members using arrow operator (->) using pointer representation
    printf("Volume: %.2f\n", calculateVolume(boxPtr));
    printf("Surface Area: %.2f\n", calculateSurfaceArea(boxPtr));

    // Accessing structure members using dot operator using dot representation
    boxPtr->length = 6.0;
    boxPtr->width = 4.0;
    boxPtr->height = 2.0;

    // Accessing structure members using arrow operator (->) using dot representation
    printf("Volume: %.2f\n", calculateVolume(boxPtr));
    printf("Surface Area: %.2f\n", calculateSurfaceArea(boxPtr));

    return 0;
}
