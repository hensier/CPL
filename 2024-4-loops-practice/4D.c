#include <stdio.h>
int m, n, a[2001][2001];
int get(int x, int y) {
    if (y <= 0 || y > n) return 0;
    return a[x][y];
}
int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) scanf("%1d", &a[1][i]);
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int x = get(i - 1, j - 1), y = get(i - 1, j), z = get(i - 1, j + 1);
            a[i][j] = (y != z || (x == 0 && y == 1));
        }
    }
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) printf("%d", a[i][j]);
        putchar('\n');
    }
    return 0;
}