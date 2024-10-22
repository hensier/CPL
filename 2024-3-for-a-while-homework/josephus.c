#include <stdio.h>
#include <stdbool.h>
int n, k, cur;
bool flag[501];
int inc(int x) {
    if (++x > n) return x - n;
    return x;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j += !flag[cur = inc(cur)]);
        flag[cur] = true;
    }
    printf("%d", cur);
    return 0;
}