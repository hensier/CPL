#include <stdio.h>
#include <stdbool.h>
unsigned long long n, k;
bool leap(unsigned long long x) {
    if (x % 400 == 0) return true;
    if (x % 100 == 0) return false;
    return x % 4 == 0;
}
int main() {
    scanf("%llu%llu", &n, &k);
    printf(leap(n) ? "Leap year!\n" : "Normal year!\n");
    printf(leap(n + k) ? "Leap year!\n" : "Normal year!\n");
    return 0;
}