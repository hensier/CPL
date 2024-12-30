#include <stdio.h>
#include <stdlib.h>
int T, cnt, t[2000001][26], siz[2000001];
char op[7], s[21];
void insert(char *s) {
    for (int i = 0, p = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (t[p][c] == 0) t[p][c] = ++cnt;
        p = t[p][c];
        siz[p]++;
    }
}
int find(char *s) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (t[p][c] == 0) return 0;
        p = t[p][c];
    }
    return siz[p];
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", op);
        if (op[0] == 'i') {
            int n;
            scanf("%d", &n);
            for (int i = 1; i <= n; i++) {
                scanf("%s", s);
                insert(s);
            }
        }
        else {
            scanf("%s", s);
            int ans = find(s);
            for (int i = 0; s[i]; i++) {
                for (char j = 'a'; j <= 'z'; j++) {
                    if (s[i] != j) {
                        char t = s[i];
                        s[i] = j;
                        ans += find(s);
                        s[i] = t;
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}