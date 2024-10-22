#include <stdio.h>
int a, b;
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
int main() {
    scanf("%d%d", &a, &b);
    printf("%d", gcd(a, b));
    return 0;
}