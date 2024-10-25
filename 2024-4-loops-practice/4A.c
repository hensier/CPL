#include <stdio.h>
int n, m, cnt, a[101][101];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1, b; j <= m; j++) {
            scanf("%d", &b);
            if (a[i][j] == b) cnt++;
        }
    }
    printf("%.2lf", 100.0 * cnt / (n * m));
    return 0;
}