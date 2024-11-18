#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
const int dx[] = {-1, 0, 0, 0, 0, 1}, dy[] = {0, -1, 0, 0, 1, 0}, dz[] = {0, 0, -1, 1, 0, 0};
int n, sx, sy, sz;
char s[602][602][602];
int get(int x, int y, int z) {
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && nz >= 1 && nz <= n) cnt += s[nx][ny][nz] == '*';
    }
    return cnt;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                s[i][j][k] = getchar();
                while (s[i][j][k] != '*' && s[i][j][k] != '?' && !isdigit(s[i][j][k])) s[i][j][k] = getchar();
                if (s[i][j][k] == '?') {
                    sx = i;
                    sy = j;
                    sz = k;
                }
            }
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (isdigit(s[i][j][k]) && s[i][j][k] != get(i, j, k) + '0') {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
    }
    if (flag) {
        printf("valid\n%d", get(sx, sy, sz));
        return 0;
    }
    s[sx][sy][sz] = '*';
    flag = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (isdigit(s[i][j][k]) && s[i][j][k] != get(i, j, k) + '0') {
                    if (flag) {
                        flag = false;
                        puts("invalid");
                    }
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }
    if (flag) printf("valid\n*");
    return 0;
}