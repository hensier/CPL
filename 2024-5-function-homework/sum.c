#include <stdio.h>
int n, t, ans;
int main() {
    scanf("%d%d", &n, &t);
    for (int i = 1, j = t; i <= n; i++, j = j * 10 + t) ans += j;
    printf("%d", ans);
    return 0;
}