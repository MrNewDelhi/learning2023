#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int isLeapYear(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month - 1];
}

int calculateDays(struct Date startDate, struct Date endDate) {
    int days = 0;
    while (startDate.day != endDate.day || startDate.month != endDate.month || startDate.year != endDate.year) {
        days++;
        startDate.day++;
        if (startDate.day > daysInMonth(startDate.month, startDate.year)) {
            startDate.day = 1;
            startDate.month++;
            if (startDate.month > 12) {
                startDate.month = 1;
                startDate.year++;
            }
        }
    }
    return days;
}

int main() {
    struct Date start, end;

    printf("Enter the start date (dd mm yyyy): ");
    scanf("%d %d %d", &start.day, &start.month, &start.year);

    printf("Enter the end date (dd mm yyyy): ");
    scanf("%d %d %d", &end.day, &end.month, &end.year);

    int daysElapsed = calculateDays(start, end);
    printf("Number of days elapsed: %d\n", daysElapsed);

    return 0;
}
