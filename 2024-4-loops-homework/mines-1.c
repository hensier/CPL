#include <stdio.h>
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n;
char s[101][101];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '*') continue;
            s[i][j] = '0';
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 1 && x <= n && y >= 1 && y <= n && s[x][y] == '*') s[i][j]++; 
            }
        }
    }
    for (int i = 1; i <= n; i++) puts(s[i] + 1);
    return 0;
}