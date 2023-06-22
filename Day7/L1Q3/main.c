#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

int parseLogFile(FILE *file, LogEntry *logEntries) {
    char line[MAX_LINE_LENGTH];
    int numEntries = 0;

    fgets(line, sizeof(line), file);  // Skip the header line

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token;
        token = strtok(line, ",");

        logEntries[numEntries].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[numEntries].sensorNo, token);

        token = strtok(NULL, ",");
        logEntries[numEntries].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[numEntries].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[numEntries].light = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[numEntries].timestamp, token);

        numEntries++;
    }

    return numEntries;
}

void displayLog(LogEntry *logEntries, int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n", logEntries[i].entryNo, logEntries[i].sensorNo,
               logEntries[i].temperature, logEntries[i].humidity, logEntries[i].light, logEntries[i].timestamp);
    }
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the log file.\n");
        return 1;
    }

    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = parseLogFile(file, logEntries);

    displayLog(logEntries, numEntries);

    fclose(file);

    return 0;
}
