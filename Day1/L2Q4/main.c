#include <stdio.h>

int findCharType(char ch) {
    int charType;

    if ((ch >= 'A' && ch <= 'Z')) {
        charType = 1;
    } else if (ch >= 'a' && ch <= 'z') {
        charType = 2;
    } else if (ch >= '0' && ch <= '9') {
        charType = 3;
    } else if (ch >= 32 && ch <= 126) {
        charType = 4;
    } else {
        charType = 5;
    }

    return charType;
}

int main() {
    char ch;

    ch = 'A';
    int type1 = findCharType(ch);
    printf("Character '%c' is of type: %d\n", ch, type1);

    ch = 'a';
    int type2 = findCharType(ch);
    printf("Character '%c' is of type: %d\n", ch, type2);

    ch = '7';
    int type3 = findCharType(ch);
    printf("Character '%c' is of type: %d\n", ch, type3);

    ch = '$';
    int type4 = findCharType(ch);
    printf("Character '%c' is of type: %d\n", ch, type4);

    ch = '\n';
    int type5 = findCharType(ch);
    printf("Character '\\n' is of type: %d\n", type5);

    return 0;
}
