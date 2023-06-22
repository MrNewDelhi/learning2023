#include <stdio.h>
#include <stdlib.h>

int calculateTotalSeconds(char *time) {
    int hours, minutes, seconds;
    int totalSeconds = 0;

    sscanf(time, "%d:%d:%d", &hours, &minutes, &seconds);

    totalSeconds = (hours * 3600) + (minutes * 60) + seconds;

    return totalSeconds;
}

int main() {
    char time[9];
    int totalSeconds;

    printf("Enter the time in HH:MM:SS format: ");
    scanf("%8s", time);

    totalSeconds = calculateTotalSeconds(time);

    printf("Total seconds: %d\n", totalSeconds);

    return 0;
}
