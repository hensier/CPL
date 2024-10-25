#include <stdio.h>
#include <stdbool.h>
int n, m, A[501][501], pos[125001][5];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &A[i][j]);
            pos[A[i][j]][++pos[A[i][j]][0]] = i;
            pos[A[i][j]][++pos[A[i][j]][0]] = j;
        }
    }
    for (int i = 1; i <= n * m / 2; i++) {
        bool f1 = true, f2 = true, f3 = true, f4 = true;
        for (int j = pos[i][1] - 1; j; j--) {
            if (A[j][pos[i][2]]) {
                f1 = false;
                break;
            }
        }
        for (int j = pos[i][3] - 1; j; j--) {
            if (A[j][pos[i][4]]) {
                f1 = false;
                break;
            }
        }
        for (int j = pos[i][1] + 1; j <= n; j++) {
            if (A[j][pos[i][2]]) {
                f2 = false;
                break;
            }
        }
        for (int j = pos[i][3] + 1; j <= n; j++) {
            if (A[j][pos[i][4]]) {
                f2 = false;
                break;
            }
        }
        for (int j = pos[i][2] - 1; j; j--) {
            if (A[pos[i][1]][j]) {
                f3 = false;
                break;
            }
        }
        for (int j = pos[i][4] - 1; j; j--) {
            if (A[pos[i][3]][j]) {
                f3 = false;
                break;
            }
        }
        for (int j = pos[i][2] + 1; j <= m; j++) {
            if (A[pos[i][1]][j]) {
                f4 = false;
                break;
            }
        }
        for (int j = pos[i][4] + 1; j <= m; j++) {
            if (A[pos[i][3]][j]) {
                f4 = false;
                break;
            }
        }
        if (f1 || f2 || f3 || f4) {
            printf("%d ", i);
            A[pos[i][1]][pos[i][2]] = 0;
            A[pos[i][3]][pos[i][4]] = 0;
        }
    }
    return 0;
}