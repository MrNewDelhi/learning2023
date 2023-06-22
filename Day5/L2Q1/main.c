#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SensorInfo {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
};

void parseData(const char* data, struct SensorInfo* sensor) {
    char* token = strtok(data, "-:");

    while (token != NULL) {
        if (strcmp(token, "S") == 0) {
            token = strtok(NULL, "-:");
            strcpy(sensor->sensorID, token);
        } else if (strcmp(token, "T") == 0) {
            token = strtok(NULL, "-:");
            sensor->temperature = atof(token);
        } else if (strcmp(token, "H") == 0) {
            token = strtok(NULL, "-:");
            sensor->humidity = atoi(token);
        } else if (strcmp(token, "L") == 0) {
            token = strtok(NULL, "-:");
            sensor->lightIntensity = atoi(token);
        }

        token = strtok(NULL, "-:");
    }
}

void printSensorInfo(const struct SensorInfo* sensor) {
    printf("Sensor Info:\n");
    printf("---------------------\n");
    printf("Sensor ID: %s\n", sensor->sensorID);
    printf("Temperature: %.1f C\n", sensor->temperature);
    printf("Humidity: %d\n", sensor->humidity);
    printf("Light Intensity: %d%%\n", sensor->lightIntensity);
    printf("---------------------\n");
}

int main() {
    const char* data = "S1-T:36.5-H:100-L:50";
    struct SensorInfo sensor;

    parseData(data, &sensor);
    printSensorInfo(&sensor);

    return 0;
}
