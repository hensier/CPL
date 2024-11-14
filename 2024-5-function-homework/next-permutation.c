#include <stdio.h>
#include <stdlib.h>
int n, p1, p2, p[2001];
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (int i = n; i > 1; i--) {
        if (p[i] > p[i-1]) {
            p1 = i;
            break;
        }
    }
    for (int i = p1; i <= n; i++) {
        if (p[i] > p[p1-1] && (p2 == 0 || p[i] < p[p2])) {
            p2 = i;
        }
    }
    swap(&p[p1-1], &p[p2]);
    qsort(p + p1, n - p1 + 1, sizeof(int), cmp);
    for (int i = 1; i <= n; i++) printf("%d ", p[i]);
    return 0;
}