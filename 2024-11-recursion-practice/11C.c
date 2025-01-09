#include <stdio.h>
int n, f[100001];
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
int main() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        f[i] = x;
    }
    for (int i = 1; i <= n; i++) printf("%d ", find(i));
    return 0;
}