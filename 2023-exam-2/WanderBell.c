#include <stdio.h>
#include <stdbool.h>
int R, C, ans;
char s[3002][3002];
bool flag[3001][3001][4];
int main() {
    scanf("%d%d", &R, &C);
    for (int i = 1; i <= R; i++) scanf("%s", s[i] + 1);
    for (int j = 1; j <= C; j++) {
        int pos = R;
        for (int i = 1; i < R; i++) {
            if (s[i][j] != '.') {
                pos = i;
                break;
            }
        }
        for (int i = pos + 1; i <= R; i++) flag[i][j][0] = true;
    }
    for (int j = 1; j <= C; j++) {
        int pos = 1;
        for (int i = R; i > 1; i--) {
            if (s[i][j] != '.') {
                pos = i;
                break;
            }
        }
        for (int i = pos - 1; i >= 1; i--) flag[i][j][1] = true;
    }
    for (int i = 1; i <= R; i++) {
        int pos = C;
        for (int j = 1; j < C; j++) {
            if (s[i][j] != '.') {
                pos = j;
                break;
            }
        }
        for (int j = pos + 1; j <= C; j++) flag[i][j][2] = true;
    }
    for (int i = 1; i <= R; i++) {
        int pos = 1;
        for (int j = C; j > 1; j--) {
            if (s[i][j] != '.') {
                pos = j;
                break;
            }
        }
        for (int j = pos - 1; j >= 1; j--) flag[i][j][3] = true;
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (s[i][j] != '.') {
                if (!flag[i][j][0] && !flag[i][j][1] && !flag[i][j][2] && !flag[i][j][3]) {
                    printf("-1");
                    return 0;
                }
                switch (s[i][j]) {
                    case 'U': {
                        ans += !flag[i][j][0];
                        break;
                    }
                    case 'D': {
                        ans += !flag[i][j][1];
                        break;
                    }
                    case 'L': {
                        ans += !flag[i][j][2];
                        break;
                    }
                    case 'R': {
                        ans += !flag[i][j][3];
                        break;
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}