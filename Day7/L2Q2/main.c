#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updateDataEntry(int entryNo, const char *newData) {
    FILE *file = fopen("data.csv", "r+");
    if (file == NULL) {
        printf("Failed to open the data file.\n");
        return;
    }

    char line[100];
    fgets(line, sizeof(line), file); // Skip the header line

    int entryFound = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        int currentEntryNo;
        sscanf(line, "%d", &currentEntryNo);

        if (currentEntryNo == entryNo) {
            entryFound = 1;
            fseek(file, -(strlen(line)), SEEK_CUR); // Move file pointer back to the start of the current line
            fputs(newData, file); // Overwrite the line with the new data
            break;
        }
    }

    fclose(file);

    if (entryFound) {
        printf("Data entry updated successfully.\n");
    } else {
        printf("Entry number not found.\n");
    }
}

int main() {
    int entryNo = 2; // Example entry number to update
    const char *newData = "2,S3,35,95,40,10:31:05"; // Example new data

    updateDataEntry(entryNo, newData);

    return 0;
}
