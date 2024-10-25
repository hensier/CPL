#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int a[9][9];
bool vis[10];
int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 9; i++) {
        memset(vis, false, sizeof(vis));
        for (int j = 0; j < 9; j++) {
            if (vis[a[i][j]]) {
                printf("NO");
                return 0;
            }
            vis[a[i][j]] = true;
        }
    }
    for (int i = 0; i < 9; i++) {
        memset(vis, false, sizeof(vis));
        for (int j = 0; j < 9; j++) {
            if (vis[a[j][i]]) {
                printf("NO");
                return 0;
            }
            vis[a[j][i]] = true;
        }
    }
    for (int i = 0; i < 9; i++) {
        memset(vis, false, sizeof(vis));
        for (int j = i / 3 * 3; j < (i / 3 + 1) * 3; j++) {
            for (int k = i % 3 * 3; k < (i % 3 + 1) * 3; k++) {
                if (vis[a[j][k]]) {
                    printf("NO");
                    return 0;
                }
                vis[a[j][k]] = true;
            }
        }
    }
    printf("YES");
    return 0;
}