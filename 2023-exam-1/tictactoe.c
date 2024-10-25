#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int t, x, n, a[11][11];
bool win[5];
int main() {
    scanf("%d%d", &t, &x);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        memset(win, false, sizeof(win));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                bool fc = true, fr = true, fd1 = true, fd2 = true;
                if (i + x - 1 <= n) {
                    for (int l = i + 1; l < i + x; l++) {
                        if (a[l][j] != a[i][j]) {
                            fc = false;
                            break;
                        }
                    }
                }
                else fc = false;
                if (j + x - 1 <= n) {
                    for (int l = j + 1; l < j + x; l++) {
                        if (a[i][l] != a[i][j]) {
                            fr = false;
                            break;
                        }
                    }
                }
                else fr = false;
                if (i + x - 1 <= n && j + x - 1 <= n) {
                    for (int l = 1; l < x; l++) {
                        if (a[i+l][j+l] != a[i][j]) {
                            fd1 = false;
                            break;
                        }
                    }
                }
                else fd1 = false;
                if (i + x - 1 <= n && j - x + 1 >= 1) {
                    for (int l = 1; l < x; l++) {
                        if (a[i+l][j-l] != a[i][j]) {
                            fd2 = false;
                            break;
                        }
                    }
                }
                else fd2 = false;
                if (fc || fr || fd1 || fd2) win[a[i][j]] = true;
            }
        }
        if (win[1] && !win[2] && !win[4]) puts("1");
        else if (!win[1] && win[2] && !win[4]) puts("2");
        else if (!win[1] && !win[2] && win[4]) puts("4");
        else puts("draw");
    }
    return 0;
}