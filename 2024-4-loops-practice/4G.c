#include <stdio.h>
#include <stdbool.h>
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int n, m, sx, sy, cnt, path[2501][2];
char s[51][51];
bool vis[51][51];
int main() {
    scanf("%d%d%d%d", &n, &m, &sx, &sy);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = sx, j = sy; ;) {
        vis[i][j] = true;
        path[++cnt][0] = i;
        path[cnt][1] = j;
        bool flag = false;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] == '#' && !vis[x][y]) {
                flag = true;
                i = x;
                j = y;
                break;
            }
        }
        if (!flag) break;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) printf("%d %d\n", path[i][0], path[i][1]);
    return 0;
}