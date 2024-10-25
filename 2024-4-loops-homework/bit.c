#include <stdio.h>
int a, b;
int popcount(int x) {
    int s = 0;
    while (x) {
        s += x & 1;
        x >>= 1;
    }
    return s;
}
int main() {
    scanf("%d%d", &a, &b);
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", a & b, a | b, a ^ b, ~a, a << b, a >> b, a >> b & 1, popcount(a));
    return 0;
}