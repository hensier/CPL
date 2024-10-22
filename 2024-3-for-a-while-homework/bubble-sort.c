#include <stdio.h>
#include <stdbool.h>
int T, n;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int maxn = -1000000000;
        for (int i = 1, a; i <= n; i++) {
            scanf("%d", &a);
            if (a > maxn) maxn = a;
            if (i == n) puts(a == maxn ? "Yes": "No");
        }
    }
    return 0;
}