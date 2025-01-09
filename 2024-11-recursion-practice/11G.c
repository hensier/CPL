#include <stdio.h>
int n, a[31];
void dfs(int k, int sum) {
    if (sum == n) {
        for (int i = 1; i < k; i++) printf("%d ", a[i]);
        putchar('\n');
        return;
    }
    for (int i = a[k-1]; i <= n - sum; i++) {
        a[k] = i;
        dfs(k + 1, sum + a[k]);
    }
}
int main() {
    scanf("%d", &n);
    a[0] = 1;
    dfs(1, 0);
    return 0;
}