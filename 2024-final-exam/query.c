#include <stdio.h>
#include <stdlib.h>
int n, q, A[500001];
int cmp(const void *a, const void *b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    qsort(A + 1, n, sizeof(int), cmp);
    scanf("%d", &q);
    for (int i = 1, m; i <= q; i++) {
        scanf("%d", &m);
        int *p = bsearch(&m, A + 1, n, sizeof(int), cmp);
        printf("%d\n", p != NULL);
    }
    return 0;
}