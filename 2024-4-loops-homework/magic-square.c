#include <stdio.h>
int n, s[1001][1001];
int main() {
    scanf("%d", &n);
    for (int i = 1, x = 1, y = n / 2 + 1; i <= n * n; i++) {
        s[x][y] = i;
        int nx = x - 1, ny = y + 1;
        if (nx == 0) nx = n;
        if (ny == n + 1) ny = 1;
        if (s[nx][ny] != 0) {
            nx = x + 1;
            ny = y;
        }
        x = nx;
        y = ny;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%d ", s[i][j]);
        putchar('\n');
    }
    return 0;
}