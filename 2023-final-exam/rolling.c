#include <stdio.h>
int m, n, a[50][50];
int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        int ans = -1;
        for (int x = 0, y = i; x >= 0 && x <= m && y >= 0 && y < n; y += a[x][y], x++) {
            if (x == m) {
                ans = y;
                break;
            }
            if (a[x][y] == -1 && (y == 0 || a[x][y-1] == 1)) break;
            if (a[x][y] == 1 && (y == n - 1 || a[x][y+1] == -1)) break;
        }
        printf("%d ", ans);
    }
    return 0;
}