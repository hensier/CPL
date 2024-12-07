#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
char s[21];
struct node {
    char name[21];
    int val;
} off[1001], def[1001], stat[1001];
int cmp(const void *a, const void *b) {
    return (*(struct node*)b).val - (*(struct node*)a).val;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        strcpy(off[i].name, s);
        strcpy(def[i].name, s);
        strcpy(stat[i].name, s);
        for (int j = 1, x, y, z; j <= 11; j++) {
            scanf("%s%d%d%d", s, &x, &y, &z);
            off[i].val += x;
            def[i].val += y;
            stat[i].val += z;
        }
    }
    qsort(off + 1, n, sizeof(struct node), cmp);
    qsort(def + 1, n, sizeof(struct node), cmp);
    qsort(stat + 1, n, sizeof(struct node), cmp);
    for (int i = 1; i <= n; i++) printf("%s ", off[i].name);
    putchar('\n');
    for (int i = 1; i <= n; i++) printf("%s ", def[i].name);
    putchar('\n');
    for (int i = 1; i <= n; i++) printf("%s ", stat[i].name);
    return 0;
}