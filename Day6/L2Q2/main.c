#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void deleteStudent(struct Student** students, int* numStudents) {
    if (*numStudents == 0) {
        printf("No students to delete.\n");
        return;
    }

    // Decrement the number of students
    (*numStudents)--;

    // Shift the remaining elements to the left
    memmove(*students, (*students) + 1, (*numStudents) * sizeof(struct Student));

    // Reallocate memory for a smaller array
    struct Student* newStudents = (struct Student*)realloc(*students, (*numStudents) * sizeof(struct Student));
    if (newStudents == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Update the students pointer to point to the new memory block
    *students = newStudents;

    printf("Student deleted successfully.\n");
}

int main() {
    int numStudents = 0;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    // Initialize the array of structures
    for (int i = 0; i < numStudents; i++) {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }

    // Populate the student data
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
    // Call the deleteStudent function to delete a student from the start
    deleteStudent(&students, &numStudents);

    // Display the updated list of students (similar to previous code)

    // Free the allocated memory
    free(students);

    return 0;
}
