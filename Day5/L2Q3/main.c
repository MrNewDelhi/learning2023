#include <stdio.h>

#define MAX_STUDENTS 50

struct Student {
    char name[50];
    int marks;
};

void readStudentData(struct Student students[], int n) {
    printf("Enter student details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
        printf("\n");
    }
}

void writeStudentData(struct Student students[], int n) {
    printf("Student details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %d\n", students[i].marks);
        printf("\n");
    }
}

float computeAverageMarks(struct Student students[], int n) {
    int totalMarks = 0;
    for (int i = 0; i < n; i++) {
        totalMarks += students[i].marks;
    }
    float averageMarks = (float)totalMarks / n;
    return averageMarks;
}

void printStudentsAboveBelowAverage(struct Student students[], int n) {
    float averageMarks = computeAverageMarks(students, n);

    printf("Students above average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks > averageMarks) {
            printf("%s\n", students[i].name);
        }
    }
    printf("\n");

    printf("Students below average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks < averageMarks) {
            printf("%s\n", students[i].name);
        }
    }
    printf("\n");
}

int main() {
    int numStudents;
    struct Student students[MAX_STUDENTS];

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    if (numStudents > 0 && numStudents <= MAX_STUDENTS) {
        readStudentData(students, numStudents);
        printf("\n");
        writeStudentData(students, numStudents);
        printf("\n");
        printStudentsAboveBelowAverage(students, numStudents);
    } else {
        printf("Invalid number of students!\n");
    }

    return 0;
}
