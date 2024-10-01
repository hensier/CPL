#include <stdio.h>
int n;
int main() {
    scanf("%d", &n);
    printf("%d\n", n / 50);
    n %= 50;
    printf("%d\n", n / 20);
    n %= 20;
    printf("%d\n", n / 10);
    n %= 10;
    printf("%d\n", n / 5);
    n %= 5;
    printf("%d", n);
    return 0;
}