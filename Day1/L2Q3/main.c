#include <stdio.h>

int isVowel(char ch) {
    int isVowel = 0;

    switch (ch) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            isVowel = 1;
            break;
        default:
            isVowel = 0;
            break;
    }

    return isVowel;
}

int main() {
    char ch;

    ch = 'a';
    int result1 = isVowel(ch);
    if (result1 == 1) {
        printf("\"%c\" is Vowel\n", ch);
    } else {
        printf("\"%c\" is Not Vowel\n", ch);
    }

    ch = 'b';
    int result2 = isVowel(ch);
    if (result2 == 1) {
        printf("\"%c\" is Vowel\n", ch);
    } else {
        printf("\"%c\" is Not Vowel\n", ch);
    }

    ch = 'E';
    int result3 = isVowel(ch);
    if (result3 == 1) {
        printf("\"%c\" is Vowel\n", ch);
    } else {
        printf("\"%c\" is Not Vowel\n", ch);
    }

    return 0;
}
