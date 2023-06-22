#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0) {
            return 1; // Leap year
        }
    }
    return 0; // Not a leap year
}

int calculateTotalDays(int day, int month, int year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = 0;

    // Count days for each year
    for (int y = 1; y < year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    // Count days for each month
    for (int m = 1; m < month; m++) {
        totalDays += daysInMonth[m];

        // Handle February in a leap year
        if (m == 2 && isLeapYear(year)) {
            totalDays += 1;
        }
    }

    // Add remaining days in the current month
    totalDays += day;

    return totalDays;
}

int main() {
    char date[11];
    int day, month, year;
    int totalDays;

    printf("Enter the date in DD/MM/YYYY format: ");
    scanf("%10s", date);

    sscanf(date, "%d/%d/%d", &day, &month, &year);

    totalDays = calculateTotalDays(day, month, year);

    printf("Total days: %d\n", totalDays);

    return 0;
}
