#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void swapStudents(struct Student* students, int index1, int index2) {
    // Check if the indexes are valid
    if (index1 < 0 || index1 >= numStudents || index2 < 0 || index2 >= numStudents) {
        printf("Invalid indexes.\n");
        return;
    }

    // Swap the members of the structures at the given indexes
    struct Student temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;

    printf("Students swapped successfully.\n");
}

int main() {
    int numStudents = 0;
    struct Student* students = NULL;

    // Add some initial students (similar to previous code)

    int index1, index2;

    // Get the indexes from the user
    printf("Enter the indexes of the students to swap: ");
    scanf("%d %d", &index1, &index2);

    // Call the swapStudents function to swap the students
    swapStudents(students, index1, index2);

    // Display the updated list of students (similar to previous code)

    // Free the allocated memory
    free(students);

    return 0;
}
