#include <stdio.h>
#include <stdlib.h>
int n, ans;
struct node {
    int t, d;
} task[101];
int cmp(const void *a, const void *b) {
    return ((*(struct node*)b).d > (*(struct node*)a).d) - ((*(struct node*)b).d < (*(struct node*)a).d);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &task[i].t, &task[i].d);
    qsort(task + 1, n, sizeof(struct node), cmp);
    ans = task[1].d;
    for (int i = 1; i <= n; i++) {
        if (ans < task[i].d) ans -= task[i].t;
        else ans = task[i].d - task[i].t;
        if (ans < 0) {
            printf("-1");
            return 0;
        }
    }
    printf("%d", ans);
    return 0;
}