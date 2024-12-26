#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int n, m, cnt, ls[101], lt[101];
char S[10001], s[101][101], t[101][101];
struct node {
    char c;
    int nxt;
} list[100001];
int main() {
    scanf("%s%d%d", S, &n, &m);
    for (int i = 0; S[i]; i++) list[++cnt].c = S[i];
    for (int i = 0; S[i]; i++) list[i].nxt = i + 1;
    for (int i = 1; i <= n; i++) {
        scanf("%s%s", s[i], t[i]);
        ls[i] = strlen(s[i]);
        lt[i] = strlen(t[i]);
    }
    while (m--) {
        for (int i = 1; i <= n; i++) {
            for (int j = list[0].nxt, lst = 0; j; lst = j, j = list[j].nxt) {
                bool flag = true;
                int k = j;
                for (int l = 0; l < ls[i]; k = list[k].nxt, l++) {
                    if (k == 0 || list[k].c != s[i][l]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    for (int l = 0; l < lt[i]; l++) list[++cnt].c = t[i][l];
                    for (int l = 1; l < lt[i]; l++) list[cnt-lt[i]+l].nxt = cnt - lt[i] + l + 1;
                    list[lst].nxt = cnt - lt[i] + 1;
                    list[cnt].nxt = k;
                    break;
                }
            }
        }
    }
    for (int i = list[0].nxt; i; i = list[i].nxt) putchar(list[i].c);
    return 0;
}