#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
int T, n, u[200001];
char s[100001], t[200001];
bool vis[101];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s%s", &n, s, t);
        for (int i = 0; i < n / 2; i++) {
            if (s[i] == '?' && s[n-i-1] != '?') s[i] = s[n-i-1];
            if (s[i] != '?' && s[n-i-1] == '?') s[n-i-1] = s[i];
        }
        int m = 0;
        bool flag = false;
        for (int i = 0; t[i]; i++) {
            if (s[m] != '?') {
                if (t[i] != s[m]) {
                    flag = true;
                    break;
                }
                u[m++] = t[i];
            }
            else {
                if (!isdigit(t[i]) || !isdigit(t[i+1])) {
                    flag = true;
                    break;
                }
                u[m++] = (t[i] - '0') * 10 + t[i+1] - '0' + 128;
                i++;
            }
        }
        if (flag || m != n) {
            puts("Wrong Answer!");
            continue;
        }
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != '?' && u[i] != s[i]) {
                flag = true;
                break;
            }
            else if (s[i] == '?') {
                int x = u[i] - 128, y = u[n-i-1] - 128;
                if (x < 0 || y < 0) {
                    flag = true;
                    break;
                }
                if (x % 10 * 10 + x / 10 != y) {
                    flag = true;
                    break;
                }
                if (vis[x] && vis[y]) {
                    flag = true;
                    break;
                }
                if (!vis[x]) vis[x] = true;
                else vis[y] = true;
            }
        }
        puts(flag ? "Wrong Answer!" : "Correct.");
    }
    return 0;
}