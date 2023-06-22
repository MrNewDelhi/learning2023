#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

float calculateDistance(struct Point p1, struct Point p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float distance = sqrt(dx * dx + dy * dy);
    return distance;
}

int main() {
    struct Point point1, point2;

    printf("Enter the coordinates of point 1:\n");
    printf("x: ");
    scanf("%f", &point1.x);
    printf("y: ");
    scanf("%f", &point1.y);

    printf("Enter the coordinates of point 2:\n");
    printf("x: ");
    scanf("%f", &point2.x);
    printf("y: ");
    scanf("%f", &point2.y);

    float distance = calculateDistance(point1, point2);

    printf("The distance between the two points is: %.2f\n", distance);

    return 0;
}
