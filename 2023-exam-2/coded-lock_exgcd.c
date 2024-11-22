#include <stdio.h>
int W, N, D, ans, a[1001];
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
void exgcd(int a, int b, long long *x, long long *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    int t = *x;
    *x = *y;
    *y = t - a / b * (*y);
}
int main() {
    scanf("%d%d%d", &W, &N, &D);
    for (int i = 1; i <= W; i++) scanf("%d", &a[i]);
    int g = gcd(N, D), n = N / g;
    for (int i = 1; i <= W / 2; i++) {
        if ((a[i] - a[W-i+1]) % g != 0) {
            printf("Impossible");
            return 0;
        }
        long long x, y;
        int k = (a[i] - a[W-i+1]) / g;
        exgcd(D, N, &x, &y);
        x *= k;
        y *= k;
        x = (x % n + n) % n;
        if (x < n - x) ans += x;
        else ans += n - x;
    }
    printf("%d", ans);
    return 0;
}