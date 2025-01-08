#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int n, m, k, s[16];
bool S[16][10001], U[10001], C[16], u[10001];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &s[i]);
        for (int j = 1, x; j <= s[i]; j++) {
            scanf("%d", &x);
            S[i][x] = true;
        }
    }
    memset(U, true, sizeof(U));
    while (k--) {
        int maxn = -1, maxi = -1;
        for (int i = 1; i <= m; i++) {
            memcpy(u, U, sizeof(U));
            int cur = 0;
            for (int j = 1; j <= n; j++) {
                u[j] &= S[i][j];
                cur += u[j];
            }
            if (cur > maxn) {
                maxn = cur;
                maxi = i;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (U[i] && S[maxi][i]) {
                U[i] = false;
            }
        }
        printf("%d ", maxi);
    }
    return 0;
}