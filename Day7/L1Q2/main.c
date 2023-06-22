#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToUpper(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);
    }
}

void convertToLower(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(tolower(ch), destination);
    }
}

void convertToSentenceCase(FILE *source, FILE *destination) {
    int ch;
    int isFirstChar = 1;
    while ((ch = fgetc(source)) != EOF) {
        if (isFirstChar) {
            fputc(toupper(ch), destination);
            isFirstChar = 0;
        } else {
            fputc(tolower(ch), destination);
        }
        if (ch == '.' || ch == '?' || ch == '!') {
            isFirstChar = 1;
        }
    }
}

void copyFile(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp -u/-l/-s source_file destination_file\n");
        return 1;
    }

    char *option = argv[1];
    char *sourceFileName = argv[2];
    char *destinationFileName = argv[3];

    FILE *sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    FILE *destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    if (strcmp(option, "-u") == 0) {
        convertToUpper(sourceFile, destinationFile);
        printf("File copied and converted to upper case successfully.\n");
    } else if (strcmp(option, "-l") == 0) {
        convertToLower(sourceFile, destinationFile);
        printf("File copied and converted to lower case successfully.\n");
    } else if (strcmp(option, "-s") == 0) {
        convertToSentenceCase(sourceFile, destinationFile);
        printf("File copied and converted to sentence case successfully.\n");
    } else {
        copyFile(sourceFile, destinationFile);
        printf("File copied successfully.\n");
    }

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
