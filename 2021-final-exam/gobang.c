#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int T;
char s[21][22];
int check(char s[][22]) {
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            if (s[i][j] != '_') {
                if (i <= 16) {
                    bool flag = true;
                    for (int k = i + 1; k <= i + 4; k++) {
                        if (s[k][j] != s[i][j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) return s[i][j] == '#';
                }
                if (j <= 16) {
                    bool flag = true;
                    for (int k = j + 1; k <= j + 4; k++) {
                        if (s[i][k] != s[i][j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) return s[i][j] == '#';
                }
                if (i <= 16 && j <= 16) {
                    bool flag = true;
                    for (int k = 1; k <= 4; k++) {
                        if (s[i+k][j+k] != s[i][j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) return s[i][j] == '#';
                }
                if (i <= 16 && j >= 5) {
                    bool flag = true;
                    for (int k = 1; k <= 4; k++) {
                        if (s[i+k][j-k] != s[i][j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) return s[i][j] == '#';
                }
            }
        }
    }
    return -1;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        for (int i = 1; i <= 20; i++) scanf("%s", s[i] + 1);
        bool win = false;
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
                if (s[i][j] == '_') {
                    s[i][j] = '*';
                    int res = check(s);
                    s[i][j] = '_';
                    if (res == 0) {
                        win = true;
                        break;
                    }
                }
            }
            if (win) break;
        }
        if (win) {
            puts("Lose");
            continue;
        }
        win = true;
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
                if (s[i][j] == '_') {
                    s[i][j] = '*';
                    bool flag = false;
                    for (int k = 1; k <= 20; k++) {
                        for (int l = 1; l <= 20; l++) {
                            if (s[k][l] == '_') {
                                s[k][l] = '#';
                                int res = check(s);
                                s[k][l] = '_';
                                if (res == 1) {
                                    flag = true;
                                    break;
                                }
                            }
                        }
                        if (flag) break;
                    }
                    s[i][j] = '_';
                    if (!flag) {
                        win = false;
                        break;
                    }
                }
            }
            if (!win) break;
        }
        puts(win ? "Win" : "Not Sure");
    }
    return 0;
}