#include <stdio.h>
#include <stdlib.h>
int n, L, ans;
struct node {
    int val, tot;
} wine[10001];
int cmp(const void *a, const void *b) {
    return (*(struct node*)b).val - (*(struct node*)a).val;
}
int main() {
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; i++) scanf("%d", &wine[i].val);
    for (int i = 1; i <= n; i++) scanf("%d", &wine[i].tot);
    qsort(wine + 1, n, sizeof(struct node), cmp);
    for (int i = 1; i <= n; i++) {
        if (L <= wine[i].tot) {
            ans += wine[i].val * L;
            break;
        }
        else {
            ans += wine[i].val * wine[i].tot;
            L -= wine[i].tot;
        }
    }
    printf("%d", ans);
    return 0;
}