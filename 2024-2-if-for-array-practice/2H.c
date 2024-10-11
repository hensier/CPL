#include <stdio.h>
const int p = 1000000007;
int n, ans;
int main() {
    scanf("%d", &n);
    for (int i = 1, tmp = 1; i <= n; i++) {
        tmp = 1LL * tmp * i % p;
        ans = (1LL * ans + tmp) % p;
    }
    printf("%d", ans);
    return 0;
}