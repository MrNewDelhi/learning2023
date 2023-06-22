#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void rotateStudents(struct Student* students, int numStudents, int k) {
    // Check if the rotation amount is valid
    if (k < 0 || k >= numStudents) {
        printf("Invalid rotation amount.\n");
        return;
    }

    // Create a temporary array to store the rotated elements
    struct Student* temp = (struct Student*)malloc(k * sizeof(struct Student));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Copy the first K elements to the temporary array
    memcpy(temp, students, k * sizeof(struct Student));

    // Shift the remaining elements to the left by K positions
    memmove(students, students + k, (numStudents - k) * sizeof(struct Student));

    // Copy the temporary array back to the end of the main array
    memcpy(students + numStudents - k, temp, k * sizeof(struct Student));

    // Free the temporary array
    free(temp);

    printf("Array rotated successfully.\n");
}

int main() {
    int numStudents = 0;
    struct Student* students = NULL;

    // Get the number of students from the user
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Allocate memory for the array of students
    students = (struct Student*)malloc(numStudents * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read student information from the user
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &(students[i].rollno));
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &(students[i].marks));
    }

    // Display the initial list of students
    printf("Initial list of students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("-------------------\n");
    }

    int k;

    // Get the rotation amount from the user
    printf("Enter the rotation amount: ");
    scanf("%d", &k);

    // Call the rotateStudents function to rotate the array
    rotateStudents(students, numStudents, k);

    // Display the updated list of students
    printf("Updated list of students after rotation:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("-------------------\n");
    }

    // Free the allocated memory
    free(students);

    return 0;
}
