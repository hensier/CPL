#include <stdio.h>
int n, ans;
long long s;
int main() {
    scanf("%d", &n);
    for (int i = 0, a; i <= n; i++) {
        scanf("%d", &a);
        if (i > 0 && s < i) {
            ans += i - s;
            s = i;
        }
        s += a;
    }
    printf("%d", ans);
    return 0;
}