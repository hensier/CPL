#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int T, n, m, a[1001], b[1001];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1, x; i <= m; i++) {
            scanf("%d", &x);
            b[1] = a[x];
            for (int j = 2; j <= x; j++) b[j] = a[j-1];
            for (int j = 1; j <= x; j++) a[j] = b[j];
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] < a[i-1]) {
                flag = false;
                break;
            }
        }
        puts(flag ? "I love C programming language" : "mayi is a good teacher");
    }
    return 0;
}