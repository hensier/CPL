#include <stdio.h>
int n, a1 = -1, a2, a3, x, a[19];
int main() {
    scanf("%d", &n);
    a[3] = 3;
    a[14] = 14;
    a[15] = 15;
    a[16] = 16;
    a[18] = 18;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        a1 &= a[x];
        a2 |= a[x];
        a3 ^= a[x];
    }
    printf("%d %d %d", a1, a2, a3);
    return 0;
}