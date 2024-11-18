#include <stdio.h>
int n, m, d, ansn, V[601][601], pos[601][601][2], ansp[360001][2];
long long ans = -18000000000, sum[1300][1300];
int main() {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &V[i][j]);
        }
    }
    for (int i = 1, j = m, ni = 1, nj = m; i <= n; ) {
        for (int I = i, J = j, NI = ni, NJ = nj; I <= n && J <= m; I++, J++, NJ += 2) {
            pos[I][J][0] = NI;
            pos[I][J][1] = NJ;
            sum[NI][NJ] = V[I][J];
        }
        if (j >= 1) {
            j--;
            ni++;
            nj--;
        }
        else {
            i++;
            ni++;
            nj++;
        }
    }
    for (int i = 1; i < n + m; i++) {
        long long pre = 0;
        for (int j = 1; j < n + m; j++) {
            pre += sum[i][j];
            sum[i][j] = sum[i-1][j] + pre;
        }
    }
    for (int i = n + m; i < n + m + 2 * d; i++) {
        for (int j = 1; j < n + m; j++) {
            sum[i][j] = sum[n+m-1][j];
            sum[j][i] = sum[j][n+m-1];
        }
    }
    for (int i = n + m; i < n + m + 2 * d; i++) {
        for (int j = n + m; j < n + m + 2 * d; j++) {
            sum[i][j] = sum[n+m-1][n+m-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = pos[i][j][0], y = pos[i][j][1];
            long long cur = sum[x+d][y+d];
            if (x >= d + 1) cur -= sum[x-d-1][y+d];
            if (y >= d + 1) cur -= sum[x+d][y-d-1];
            if (x >= d + 1 && y >= d + 1) cur += sum[x-d-1][y-d-1];
            if (cur > ans) {
                ans = cur;
                ansn = 1;
                ansp[1][0] = i;
                ansp[1][1] = j;
            }
            else if (cur == ans) {
                ansp[++ansn][0] = i;
                ansp[ansn][1] = j;
            }
        }
    }
    printf("%lld %d\n", ans, ansn);
    for (int i = 1; i <= ansn; i++) printf("%d %d\n", ansp[i][0], ansp[i][1]);
    return 0;
}