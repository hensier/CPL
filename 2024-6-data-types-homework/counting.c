#include <stdio.h>
#include <stdbool.h>
int R, C, ans;
char s[101][101];
int main() {
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++) scanf("%s", s[i]);
    for (int i = 0; i < R - 1; i++) {
        for (int j = 0; j < C - 1; j++) {
            for (int k = 1; 2 * k < (R - i + 1) && k < C - j && k <= j + 1; k++) {
                bool flag = true;
                for (int l = 0; l < k; l++) {
                    if (s[i+l][j-l] != '/') {
                        flag = false;
                        break;
                    }
                }
                for (int l = 0; l < k; l++) {
                    if (s[i+l][j+1+l] != '\\') {
                        flag = false;
                        break;
                    }
                }
                for (int l = 0; l < k; l++) {
                    if (s[i+k+l][j-k+1+l] != '\\') {
                        flag = false;
                        break;
                    }
                }
                for (int l = 0; l < k; l++) {
                    if (s[i+k+l][j+k-l] != '/') {
                        flag = false;
                        break;
                    }
                }
                ans += flag;
            }
        }
    }
    printf("%d", ans);
    return 0;
}