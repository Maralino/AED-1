#include <stdio.h>

int main() {
    int distance;
    double fuel;

    scanf("%d %lf", &distance, &fuel);

    double consumption = distance / fuel;

    printf("%.3lf km/l\n", consumption);

    return 0;
}
