#include <stdio.h>
#include <stdbool.h>
const int B = 2000;
int n, q, cnt;
char s[100001], op[2], t[100001];
struct node {
    char a[2002];
    int nxt, len;
} list[100001];
void swap(char *x, char *y) {
    char t = *x;
    *x = *y;
    *y = t;
}
void split(int pos1, int pos2, int cutn) {
    cnt++;
    for (int i = pos2 + 1; i <= B; i++) swap(&list[pos1].a[i], &list[cnt].a[i-pos2]);
    list[pos1].len -= cutn;
    list[cnt].len = cutn;
    list[cnt].nxt = list[pos1].nxt;
    list[pos1].nxt = cnt;
}
void merge(int u) {
    int v = list[u].nxt;
    for (int i = list[u].len + 1, j = 1; j <= list[v].len; i++, j++) {
        list[u].a[i] = list[v].a[j];
        list[u].len++;
    }
    list[u].nxt = list[v].nxt;
}
void dfs(int u, int tmp) {
    if (u == tmp) return;
    dfs(list[u].nxt, tmp);
    if (list[u].len + list[list[u].nxt].len <= B) merge(u);
}
int main() {
    scanf("%d%d%s", &n, &q, s);
    for (int i = 0, j = 1; i < n; i++, j++) {
        if (j % B == 1) {
            cnt++;
            list[cnt].nxt = cnt + 1;
            j = 1;
        }
        list[cnt].a[j] = s[i];
        list[cnt].len++;
    }
    list[cnt].nxt = 0;
    for (int i = 1, p; i <= q; i++) {
        scanf("%s%d", op, &p);
        int sum = 0, pos1 = -1;
        for (int j = 1; j <= cnt; j = list[j].nxt) {
            sum += list[j].len;
            if (sum >= p) {
                pos1 = j;
                break;
            }
        }
        int pos2 = p - sum + list[pos1].len;
        if (op[0] == 'I') {
            scanf("%s", t);
            if (pos2 != B) split(pos1, pos2, sum - p);
            int lst = pos1, tmp = list[pos1].nxt;
            for (int j = 0, k = 1; t[j]; j++, k++) {
                if (k % B == 1) {
                    cnt++;
                    list[lst].nxt = cnt;
                    lst = cnt;
                    k = 1;
                }
                list[cnt].a[k] = t[j];
                list[cnt].len++;
            }
            list[lst].nxt = tmp;
            dfs(pos1, tmp);
        }
        else printf("%c\n", list[pos1].a[pos2]);
    }
    return 0;
}