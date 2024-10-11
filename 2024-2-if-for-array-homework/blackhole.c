#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int N, ans, a, b, x[3], y[3];
bool vis[3];
void dfs(int k) {
    if (k == 3) {
        int z = y[0] * 100 + y[1] * 10 + y[2];
        if (z < a) a = z;
        if (z > b) b = z;
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (!vis[i]) {
            vis[i] = true;
            y[k] = x[i];
            dfs(k + 1);
            vis[i] = false;
        }
    }
}
int main() {
    scanf("%d", &N);
    while (N != 495) {
        x[0] = N / 100;
        x[1] = N / 10 % 10;
        x[2] = N % 10;
        a = 999;
        b = 0;
        memset(vis, false, sizeof(vis));
        dfs(0);
        if (N > b - a) ans += N + a - b;
        N = b - a;
    }
    printf("%d", ans);
    return 0;
}