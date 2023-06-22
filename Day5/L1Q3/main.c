#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void getTimePeriod(struct Time *t) {
    printf("Enter the time period:\n");

    printf("Hours: ");
    scanf("%d", &(t->hours));

    printf("Minutes: ");
    scanf("%d", &(t->minutes));

    printf("Seconds: ");
    scanf("%d", &(t->seconds));
}

void printTimePeriod(struct Time t) {
    printf("Time period: %d hours, %d minutes, %d seconds\n", t.hours, t.minutes, t.seconds);
}

struct Time calculateDifference(struct Time start, struct Time end) {
    struct Time difference;
    int totalSecondsStart, totalSecondsEnd, totalSecondsDiff;

    totalSecondsStart = start.hours * 3600 + start.minutes * 60 + start.seconds;
    totalSecondsEnd = end.hours * 3600 + end.minutes * 60 + end.seconds;

    totalSecondsDiff = totalSecondsEnd - totalSecondsStart;

    difference.hours = totalSecondsDiff / 3600;
    totalSecondsDiff %= 3600;

    difference.minutes = totalSecondsDiff / 60;
    totalSecondsDiff %= 60;

    difference.seconds = totalSecondsDiff;

    return difference;
}

int main() {
    struct Time startTime, endTime, timeDiff;

    printf("Enter the start time:\n");
    getTimePeriod(&startTime);

    printf("Enter the end time:\n");
    getTimePeriod(&endTime);

    printf("\n");

    printf("Start time:\n");
    printTimePeriod(startTime);

    printf("End time:\n");
    printTimePeriod(endTime);

    timeDiff = calculateDifference(startTime, endTime);
    printf("Difference between the two time periods:\n");
    printTimePeriod(timeDiff);

    return 0;
}
