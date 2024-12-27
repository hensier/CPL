#include <stdio.h>
#include <stdlib.h>
int n, q, A[1000000];
int cmp(const void *a, const void *b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 1, x; i <= q; i++) {
        scanf("%d", &x);
        int *p = (int*)bsearch(&x, A, n, sizeof(int), cmp);
        printf("%d\n", p != NULL ? (int)(p - A) : -1);
    }
    return 0;
}