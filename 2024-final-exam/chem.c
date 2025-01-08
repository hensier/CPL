#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n, m, cnt, head[2001], tail[2001], l[2001];
char op1[8], op2[6];
struct node {
    int val, pre, nxt;
} list[5000001];
void modify(int id, int old, int x) {
    if (list[id].pre == old) list[id].pre = x;
    else list[id].nxt = x;
}
int get_nxt(int id, int *lst) {
    if (list[id].pre != *lst) {
        *lst = id;
        return list[id].pre;
    }
    else {
        *lst = id;
        return list[id].nxt;
    }
}
int get_node(int x, int pos, int *pre, int *nxt) {
    int ans = -1, lst = 0;
    if (pos <= l[x] - pos + 1) {
        ans = head[x];
        for (int i = 1; i < pos; i++, ans = get_nxt(ans, &lst));
        if (pos == 1) *pre = 0;
        else *pre = lst;
        if (list[ans].pre != lst) *nxt = list[ans].pre;
        else *nxt = list[ans].nxt;
    }
    else {
        ans = tail[x];
        for (int i = 1; i < l[x] - pos + 1; i++, ans = get_nxt(ans, &lst));
        if (pos == l[x]) *nxt = 0;
        else *nxt = lst;
        if (list[ans].pre != lst) *pre = list[ans].pre;
        else *pre = list[ans].nxt;
    }
    return ans;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &l[i]);
        head[i] = cnt + 1;
        for (int j = 1; j <= l[i]; j++) {
            cnt++;
            if (j != 1) list[cnt].pre = cnt - 1;
            if (j != l[i]) list[cnt].nxt = cnt + 1;
            scanf("%d", &list[cnt].val);
        }
        tail[i] = cnt;
    }
    for (int i = 1, x, y, p, q; i <= m; i++) {
        scanf("%s", op1);
        if (op1[0] == 'l') {
            scanf("%s%d%d", op2, &x, &y);
            if (x < 1 || x > n || y < 1 || y > n || x == y || l[y] == 0) continue;
            switch (op2[0]) {
                case 'b': {
                    if (l[x] == 0) head[x] = head[y];
                    else {
                        modify(tail[x], 0, head[y]);
                        modify(head[y], 0, tail[x]);
                    }
                    tail[x] = tail[y];
                    l[x] += l[y];
                    head[y] = 0;
                    tail[y] = 0;
                    l[y] = 0;
                    break;
                }
                case 'f': {
                    if (l[x] == 0) tail[x] = tail[y];
                    else {
                        modify(tail[y], 0, head[x]);
                        modify(head[x], 0, tail[y]);
                    }
                    head[x] = head[y];
                    l[x] += l[y];
                    head[y] = 0;
                    tail[y] = 0;
                    l[y] = 0;
                    break;
                }
            }
        }
        else {
            scanf("%d%d%d", &x, &p, &q);
            if (p < 1 || p > l[x] || q < 1 || q > l[x] || p > q) continue;
            int prep = -1, nxtp = -1, preq = -1, nxtq = -1;
            int P = get_node(x, p, &prep, &nxtp), Q = get_node(x, q, &preq, &nxtq);
            switch (op1[1]) {
                case 'u': {
                    modify(prep, P, nxtq);
                    modify(nxtq, Q, prep);
                    if (p == 1) head[x] = nxtq;
                    if (q == l[x]) tail[x] = prep;
                    l[x] -= q - p + 1;
                    break;
                }
                case 'o': {
                    if (p == q) break;
                    modify(prep, P, Q);
                    modify(P, prep, Q);
                    modify(preq, Q, nxtq);
                    modify(Q, preq, prep);
                    modify(Q, nxtq, P);
                    modify(nxtq, Q, preq);
                    if (p == 1) head[x] = Q;
                    if (q == l[x]) tail[x] = preq;
                    break;
                }
                case 'e': {
                    if (p == q) break;
                    modify(prep, P, Q);
                    modify(P, prep, nxtq);
                    modify(Q, nxtq, prep);
                    modify(nxtq, Q, P);
                    if (p == 1) head[x] = Q;
                    if (q == l[x]) tail[x] = P;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (l[i] == 0) continue;
        for (int j = head[i], lst = 0; j; j = get_nxt(j, &lst)) printf("%d ", list[j].val);
        putchar('\n');
    }
    return 0;
}