#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

struct Person* modifyPerson(struct Person* person) {
    person->age += 1;
    return person;
}

int main() {
    struct Person* person = malloc(sizeof(struct Person));

    printf("Enter person's name: ");
    scanf("%s", person->name);
    printf("Enter person's age: ");
    scanf("%d", &person->age);

    printf("\nBefore modification:\n");
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);

    struct Person* modifiedPerson = modifyPerson(person);

    printf("\nAfter modification:\n");
    printf("Name: %s\n", modifiedPerson->name);
    printf("Age: %d\n", modifiedPerson->age);

    free(person);

    return 0;
}
