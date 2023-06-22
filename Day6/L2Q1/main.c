#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void addStudent(struct Student** students, int* numStudents) {
    // Increment the number of students
    (*numStudents)++;

    // Reallocate memory for a larger array
    struct Student* newStudents = (struct Student*)realloc(*students, (*numStudents) * sizeof(struct Student));
    if (newStudents == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Update the students pointer to point to the new memory block
    *students = newStudents;

    // Get the details of the new student from the user
    struct Student newStudent;

    printf("Enter the roll number of the student: ");
    scanf("%d", &newStudent.rollno);

    printf("Enter the name of the student: ");
    scanf("%s", newStudent.name);

    printf("Enter the marks of the student: ");
    scanf("%f", &newStudent.marks);

    // Add the new student at the end of the array
    (*students)[*numStudents - 1] = newStudent;

    printf("Student added successfully.\n");
}
void displayStudents(struct Student* students, int numStudents) {
    printf("\nStudent Details (Sorted by Marks in Descending Order):\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

int main() {
    int numStudents = 0;

    // Add some initial students
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

    // Call the addStudent function to add a new student
    addStudent(&students, &numStudents);

    // Display the updated list of students
    displayStudents(students, numStudents);
    // Free the allocated memory
    free(students);

    return 0;
}
