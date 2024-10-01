#include <stdio.h>
char month[10], weekday[10];
int day, year, hour, minute, second;
int main() {
    scanf("%s%d%d%s%d%d%d", month, &day, &year, weekday, &hour, &minute, &second);
    printf("%c%c%c %c%c%c ", weekday[0], weekday[1], weekday[2], month[0], month[1], month[2]);
    if (day < 10) printf("0");
    printf("%d ", day);
    if (hour < 10) printf("0");
    printf("%d:", hour);
    if (minute < 10) printf("0");
    printf("%d:", minute);
    if (second < 10) printf("0");
    printf("%d ", second);
    if (year < 1000) printf("0");
    if (year < 100) printf("0");
    if (year < 10) printf("0");
    printf("%d", year);
    return 0;
}