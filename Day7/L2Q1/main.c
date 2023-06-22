#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortDataFile() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the data file.\n");
        return;
    }

    char lines[100][100];
    int numLines = 0;

    char line[100];
    fgets(line, sizeof(line), file); // Skip the header line

    while (fgets(line, sizeof(line), file) != NULL) {
        strcpy(lines[numLines], line);
        numLines++;
    }

    fclose(file);

    for (int i = 0; i < numLines; i++) {
        for (int j = i + 1; j < numLines; j++) {
            float temp1, temp2;

            sscanf(lines[i], "%*[^,],%*[^,],%f", &temp1);
            sscanf(lines[j], "%*[^,],%*[^,],%f", &temp2);

            if (temp1 < temp2) {
                char temp[100];
                strcpy(temp, lines[i]);
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], temp);
            }
        }
    }

    file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Failed to open the data file for writing.\n");
        return;
    }

    for (int i = 0; i < numLines; i++) {
        fputs(lines[i], file);
    }

    fclose(file);

    printf("Data file sorted successfully.\n");
}

int main() {
    sortDataFile();

    return 0;
}
