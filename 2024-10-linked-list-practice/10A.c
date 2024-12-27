#include <stdio.h>
int n, m, head[1000001], tail[1000001];
struct node {
    int pre, nxt;
} list[1000001];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        head[i] = i;
        tail[i] = i;
    }
    for (int i = 1, x, y; i <= m; i++) {
        scanf("%d%d", &x, &y);
        if (head[x] == 0) continue;
        if (head[y] == 0) head[y] = tail[x];
        if (list[tail[y]].pre == 0) list[tail[y]].pre = tail[x];
        else list[tail[y]].nxt = tail[x];
        if (list[tail[x]].pre == 0) list[tail[x]].pre = tail[y];
        else list[tail[x]].nxt = tail[y];
        tail[y] = head[x];
        head[x] = 0;
        tail[x] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (head[i] == 0) printf("0");
        else for (int j = head[i], lst = 0; j; ) {
            printf("%d ", j);
            if (list[j].pre == lst) {
                lst = j;
                j = list[j].nxt;
            }
            else {
                lst = j;
                j = list[j].pre;
            }
        }
        putchar('\n');
    }
    return 0;
}