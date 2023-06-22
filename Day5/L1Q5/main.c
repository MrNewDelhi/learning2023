#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

void swapFields(struct Student* student1, struct Student* student2) {
    struct Student temp;

    // Swap name
    strcpy(temp.name, student1->name);
    strcpy(student1->name, student2->name);
    strcpy(student2->name, temp.name);

    // Swap roll number
    int rollNumberTemp = student1->rollNumber;
    student1->rollNumber = student2->rollNumber;
    student2->rollNumber = rollNumberTemp;

    // Swap marks
    float marksTemp = student1->marks;
    student1->marks = student2->marks;
    student2->marks = marksTemp;
}

int main() {
    struct Student student1 = { "John", 1, 85.5 };
    struct Student student2 = { "Jane", 2, 92.0 };

    printf("Before swapping:\n");
    printf("Student 1:\nName: %s\nRoll Number: %d\nMarks: %.2f\n", student1.name, student1.rollNumber, student1.marks);
    printf("Student 2:\nName: %s\nRoll Number: %d\nMarks: %.2f\n", student2.name, student2.rollNumber, student2.marks);

    // Swap fields using pointers
    swapFields(&student1, &student2);

    printf("\nAfter swapping:\n");
    printf("Student 1:\nName: %s\nRoll Number: %d\nMarks: %.2f\n", student1.name, student1.rollNumber, student1.marks);
    printf("Student 2:\nName: %s\nRoll Number: %d\nMarks: %.2f\n", student2.name, student2.rollNumber, student2.marks);

    return 0;
}
