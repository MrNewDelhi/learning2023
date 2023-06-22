#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool validateEmail(const char *email) {
    // Check if email contains an '@' character
    const char *atSymbol = strchr(email, '@');
    if (atSymbol == NULL) {
        return false;
    }

    // Check if there is at least one character before and after the '@' symbol
    if (atSymbol == email || atSymbol[1] == '\0') {
        return false;
    }

    // Check if there is a dot '.' after the '@' symbol
    const char *dotSymbol = strchr(atSymbol, '.');
    if (dotSymbol == NULL || dotSymbol[1] == '\0') {
        return false;
    }

    // Check if there are no consecutive dots '..' in the domain name
    const char *prevChar = dotSymbol - 1;
    while (prevChar >= atSymbol) {
        if (*prevChar == '.') {
            return false;
        }
        prevChar--;
    }

    return true;
}

int main() {
    const int MAX_EMAILS = 5;
    const int MAX_LENGTH = 100;
    char emails[MAX_EMAILS][MAX_LENGTH];

    printf("Enter %d email addresses:\n", MAX_EMAILS);
    for (int i = 0; i < MAX_EMAILS; i++) {
        printf("Email %d: ", i + 1);
        fgets(emails[i], MAX_LENGTH, stdin);

        // Remove the newline character
        emails[i][strcspn(emails[i], "\n")] = '\0';
    }

    printf("Validation Results:\n");
    for (int i = 0; i < MAX_EMAILS; i++) {
        bool valid = validateEmail(emails[i]);
        printf("%s: %s\n", emails[i], valid ? "Valid" : "Invalid");
    }

    return 0;
}
