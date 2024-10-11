#include <stdio.h>
const int p = 10007;
int n, ans;
int main() {
    scanf("%d", &n);
    for (int i = 1, tmp = 1; i <= n; i++) {
        tmp = tmp * i % p;
        ans = (ans + tmp) % p;
    }
    printf("%d", ans);
    return 0;
}