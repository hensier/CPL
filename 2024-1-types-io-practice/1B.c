#include <stdio.h>
int x;
int main() {
    scanf("%d", &x);
    printf("%d", x / 100 + x % 10 * 100 + x / 10 % 10 * 10);
    return 0;
}