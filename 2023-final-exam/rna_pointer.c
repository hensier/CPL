#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int n, m, ls[101], lt[101];
char S[10001], s[101][101], t[101][101];
struct node {
    char c;
    struct node *nxt;
};
struct node *create(char c) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p -> c = c;
    p -> nxt = NULL;
    return p;
}
int main() {
    scanf("%s%d%d", S, &n, &m);
    struct node *head = create(S[0]), *lst = head;
    for (int i = 1; S[i]; i++) {
        struct node *p = create(S[i]);
        lst -> nxt = p;
        lst = p;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s%s", s[i], t[i]);
        ls[i] = strlen(s[i]);
        lt[i] = strlen(t[i]);
    }
    while (m--) {
        for (int i = 1; i <= n; i++) {
            for (struct node *p = head, *lst = NULL; p; lst = p, p = p -> nxt) {
                bool flag = true;
                struct node *q = p;
                for (int j = 0; j < ls[i]; j++, q = q -> nxt) {
                    if (q == NULL || q -> c != s[i][j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    struct node *LST = lst;
                    for (int j = 0; j < lt[i]; j++) {
                        struct node *r = create(t[i][j]);
                        if (LST != NULL) LST -> nxt = r;
                        else head = r;
                        LST = r;
                    }
                    LST -> nxt = q;
                    break;
                }
            }
        }
    }
    for (struct node *p = head; p; p = p -> nxt) putchar(p -> c);
    return 0;
}