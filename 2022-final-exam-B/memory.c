#include <stdio.h>
#include <stdbool.h>
int T, n, cnt = 1, cntmal, ord[5001];
struct node {
    int l, r, nxt;
} list[5001];
int main() {
    scanf("%d%d", &T, &n);
    list[0].nxt = 1;
    list[1] = (struct node){0, n, 0};
    for (int i = 1, opt; i <= T; i++) {
        scanf("%d", &opt);
        switch (opt) {
            case 1: {
                cntmal++;
                int size;
                scanf("%d", &size);
                bool flag = false;
                for (int j = list[0].nxt, lst = 0; j; lst = j, j = list[j].nxt) {
                    if (list[j].r - list[j].l >= size) {
                        printf("%d\n", list[j].l);
                        list[++cnt] = (struct node){list[j].l, list[j].l + size, 0};
                        ord[cntmal] = cnt;
                        list[j].l += size;
                        if (list[j].l == list[j].r) {
                            list[lst].nxt = list[j].nxt;
                            list[j].nxt = 0;
                        }
                        flag = true;
                        break;
                    }
                }
                if (!flag) puts("malloc fail");
                break;
            }
            case 2: {
                int id;
                scanf("%d", &id);
                if (id > cntmal || ord[id] == 0) puts("free fail");
                else {
                    puts("free success");
                    int pos = 0;
                    for (int j = list[0].nxt; j; j = list[j].nxt) {
                        if (list[ord[id]].l >= list[j].r) pos = j;
                        else break;
                    }
                    if (pos != 0 && list[pos].nxt != 0 && list[ord[id]].l == list[pos].r && list[ord[id]].r == list[list[pos].nxt].l) {
                        int tmp = list[pos].nxt;
                        list[pos].r = list[tmp].r;
                        list[pos].nxt = list[tmp].nxt;
                        list[tmp].nxt = 0;
                    }
                    else if (pos != 0 && list[ord[id]].l == list[pos].r) list[pos].r = list[ord[id]].r;
                    else if (list[pos].nxt != 0 && list[ord[id]].r == list[list[pos].nxt].l) list[list[pos].nxt].l = list[ord[id]].l;
                    else {
                        list[ord[id]].nxt = list[pos].nxt;
                        list[pos].nxt = ord[id];
                    }
                    ord[id] = 0;
                }
                break;
            }
            case 3: {
                if (list[0].nxt == 0) printf("NULL");
                else for (int j = list[0].nxt; j; j = list[j].nxt) printf("[%d,%d) ", list[j].l, list[j].r);
                putchar('\n');
                break;
            }
        }
    }
    return 0;
}