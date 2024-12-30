#include <stdio.h>
int n, m, q, sum[4002][4002], pos[1001][1001][2], npos[2001][2001][2];
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1, j = m, ni = 1, nj = m; i <= n;) {
        for (int I = i, J = j, NI = ni, NJ = nj; I <= n && J <= m; I++, J++, NJ += 2) {
            pos[I][J][0] = NI;
            pos[I][J][1] = NJ;
            npos[NI][NJ][0] = I;
            npos[NI][NJ][1] = J;
        }
        if (j == 1) {
            i++;
            ni++;
            nj++;
        }
        else {
            j--;
            ni++;
            nj--;
        }
    }
    for (int i = 1, x, y, d; i <= q; i++) {
        scanf("%d%d%d", &x, &y, &d);
        int a = pos[x][y][0] - d + 1000, b = pos[x][y][1] - d + 1000,
        c = pos[x][y][0] + d + 1000, e = pos[x][y][1] + d + 1000;
        sum[a][b]++;
        sum[a][e+1]--;
        sum[c+1][b]--;
        sum[c+1][e+1]++;
    }
    for (int i = 1; i <= n + m + 1000; i++) {
        for (int j = 1; j <= n + m + 1000; j++) {
            sum[i][j] += sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) printf("%d ", sum[pos[i][j][0]+1000][pos[i][j][1]+1000]);
        putchar('\n');
    }
    return 0;
}