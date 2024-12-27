#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int n, q, cnt = 1, lst = 1;
char op[2];
struct node {
    int siz, id, nxt;
} block[30001];
int main() {
    scanf("%d%d", &n, &q);
    block[1].siz = n;
    while (q--) {
        scanf("%s", op);
        if (op[0] == 'A') {
            int id, m;
            scanf("%d%d", &id, &m);
            m = ceil(log2(m));
            while (true) {
                int pos = -1;
                for (int i = 1; i; i = block[i].nxt) {
                    if (block[i].id != 0) continue;
                    if (block[i].siz == m) {
                        pos = i;
                        break;
                    }
                    else if (pos == -1 && block[i].siz > m) pos = i;
                }
                if (block[pos].siz == m) {
                    block[pos].id = id;
                    break;
                }
                else {
                    block[pos].siz--;
                    block[++cnt].siz = block[pos].siz;
                    block[cnt].nxt = block[pos].nxt;
                    block[pos].nxt = cnt;
                    lst = cnt;
                }
            }
        }
        else {
            printf("%d\n", cnt);
            for (int i = 1; i; i = block[i].nxt) printf("%d ", block[i].id);
            putchar('\n');
        }
    }
    return 0;
}