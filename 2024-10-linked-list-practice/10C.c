#include <stdio.h>
#include <stdbool.h>
#include <string.h>
const int N = 500000;
int m, q, head[500000];
char s[1001];
struct node {
    char s[1001];
    int nxt;
} list[500001];
int hash(char *s) {
    int h = 0;
    for (int i = 0; s[i]; i++) h = (h + s[i] * (i + 1)) % N;
    return h;
}
int main() {
    scanf("%d%d", &m, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%s", list[i].s);
        int h = hash(list[i].s);
        if (head[h] == 0) head[h] = i;
        else for (int j = head[h]; ; j = list[j].nxt) {
            if (list[j].nxt == 0) {
                list[j].nxt = i;
                break;
            }
        }
    }
    while (q--) {
        scanf("%s", s);
        int h = hash(s);
        bool flag = false;
        for (int i = head[h]; i; i = list[i].nxt) {
            if (strcmp(list[i].s, s) == 0) {
                puts("Yes");
                flag = true;
                break;
            }
        }
        if (!flag) puts("No");
    }
    return 0;
}