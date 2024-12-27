#include <stdio.h>
#include <stdlib.h>
int a[10], b[4], c[4], d[4];
long long ans;
int cmp(const void *a, const void *b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}
int main() {
    for (int i = 1; i <= 9; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= 3; i++) scanf("%d", &b[i]);
    for (c[1] = 1; c[1] <= 9; c[1]++) {
        for (c[2] = 1; c[2] <= 9; c[2]++) {
            for (c[3] = 1; c[3] <= 9; c[3]++) {
                if (c[1] == c[2] || c[2] == c[3] || c[1] == c[3]) continue;
                for (int i = 1; i <= 3; i++) d[i] = c[i];
                qsort(d + 1, 3, sizeof(int), cmp);
                if (d[1] % 3 == 1 && d[2] == d[1] + 1 && d[3] == d[2] + 1) continue;
                if (d[2] == d[1] + 3 && d[3] == d[2] + 3) continue;
                if (d[1] == 1 && d[2] == 5 && d[3] == 9) continue;
                if (d[1] == 3 && d[2] == 5 && d[3] == 7) continue;
                long long cur = 0;
                for (int i = 1; i <= 3; i++) cur += a[c[i]] * b[i];
                if (cur > ans) ans = cur;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}