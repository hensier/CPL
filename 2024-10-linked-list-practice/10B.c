#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int n, q, cnt, head[10001];
char name[10001][11], s1[11], s2[11], op[7], s[11];
bool flag[10001];
struct node {
    int nxt, to;
} e[10001];
void add_edge(int u, int v) {
    e[++cnt] = (struct node){head[u], v};
    head[u] = cnt;
}
int dfs(int u) {
    if (flag[u]) return 0;
    int siz = 1;
    for (int i = head[u]; i; i = e[i].nxt) siz += dfs(e[i].to);
    return siz;
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s%s", s1, s2);
        strcpy(name[i], s1);
        int pos = -1;
        for (int j = 1; j <= i; j++) {
            if (strcmp(name[j], s2) == 0) {
                pos = j;
                break;
            }
        }
        if (pos != -1) add_edge(pos, i);
    }
    while (q--) {
        scanf("%s%s", op, s);
        int pos = -1;
        for (int i = 1; i <= n; i++) {
            if (strcmp(name[i], s) == 0) {
                pos = i;
                break;
            }
        }
        if (op[0] == 'r') flag[pos] = true;
        else printf("%d\n", dfs(pos));
    }
    return 0;
}