#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteEntryFromFile(int entryNo) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the data file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        printf("Failed to create temporary file.\n");
        fclose(file);
        return;
    }

    char line[100];
    fgets(line, sizeof(line), file); // Copy the header line to the temporary file
    fputs(line, tempFile);

    while (fgets(line, sizeof(line), file) != NULL) {
        int currentEntryNo;
        sscanf(line, "%d,", &currentEntryNo);

        if (currentEntryNo != entryNo) {
            // Copy the line as it is to the temporary file
            fputs(line, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("data.csv");       // Remove the original file
    rename("temp.csv", "data.csv");  // Rename the temporary file to the original file name

    printf("Entry deleted successfully.\n");
}

int main() {
    int entryNo = 2;

    deleteEntryFromFile(entryNo);

    return 0;
}
