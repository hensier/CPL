#include <stdio.h>
#include <string.h>
int n, len;
char s[1001], t[1001];
int border(int x) {
    if (x < 0) return 0;
    if (x >= len) return len - 1;
    return x;
}
int main() {
    scanf("%d%s", &n, s);
    len = strlen(s);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < len; j++) {
            int c[2] = {};
            for (int k = border(j - 3); k <= border(j + 3); k++) {
                if (k != j && s[k] != '.') {
                    c[s[k]-'A']++;
                }
            }
            if (s[j] == '.') {
                if (c[0] >= 2 && c[0] <= 4 && c[1] == 0) t[j] = 'A';
                else if (c[1] >= 2 && c[1] <= 4 && c[0] == 0) t[j] = 'B';
                else t[j] = s[j];
            }
            else {
                if (c[(s[j]-'A')^1] != 0 || c[s[j]-'A'] <= 1 || c[s[j]-'A'] >= 5) t[j] = '.';
                else t[j] = s[j];
            }
        }
        memcpy(s, t, sizeof(t));
    }
    printf("%s", s);
    return 0;
}