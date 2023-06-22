#include <stdio.h>

char getGrade(int marks) {
    char grade;

    switch (marks) {
        case 90 ... 100:
            grade = 'A';
            break;
        case 75 ... 89:
            grade = 'B';
            break;
        case 60 ... 74:
            grade = 'C';
            break;
        case 50 ... 59:
            grade = 'D';
            break;
        case 36 ... 49:
            grade = 'E';
            break;
        case 0 ... 35:
            grade = 'F';
            break;
        default:
            grade = '\0';
            printf("Invalid marks entered!\n");
            break;
    }

    return grade;
}

int main() {
    int marks;

    marks = 65;
    char grade65 = getGrade(marks);
    printf("%d -> \"Grade %c\"\n", marks, grade65);

    marks = 66;
    char grade66 = getGrade(marks);
    printf("%d -> \"Grade %c\"\n", marks, grade66);

    marks = 67;
    char grade67 = getGrade(marks);
    printf("%d -> \"Grade %c\"\n", marks, grade67);

    marks = 68;
    char grade68 = getGrade(marks);
    printf("%d -> \"Grade %c\"\n", marks, grade68);

    marks = 69;
    char grade69 = getGrade(marks);
    printf("%d -> \"Grade %c\"\n", marks, grade69);

    marks = 70;
    char grade70 = getGrade(marks);
    printf("%d -> \"Grade %c\"\n", marks, grade70);

    return 0;
}
