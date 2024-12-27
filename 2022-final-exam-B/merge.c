#include <stdio.h>
#include <stdlib.h>
int n1, n2, pos1, pos2, a[200001], b[200001], c[400001];
int cmp_less(const void *a, const void *b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}
int cmp_greater(const void *a, const void *b) {
    return (*(int*)b > *(int*)a) - (*(int*)b < *(int*)a);
}
int main() {
    scanf("%d", &n1);
    for (int i = 1; i <= n1; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n1; i++) {
        if (a[i] > a[i+1]) {
            pos1 = i;
            break;
        }
    }
    scanf("%d", &n2);
    for (int i = 1; i <= n2; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n2; i++) {
        if (b[i] > b[i+1]) {
            pos2 = i;
            break;
        }
    }
    for (int i = 1; i <= pos1; i++) c[i] = a[i];
    for (int i = 1; i <= pos2; i++) c[pos1+i] = b[i];
    qsort(c + 1, pos1 + pos2, sizeof(int), cmp_less);
    for (int i = pos1 + 1; i <= n1; i++) c[pos2+i] = a[i];
    for (int i = pos2 + 1; i <= n2; i++) c[n1+i] = b[i];
    qsort(c + pos1 + pos2 + 1, n1 + n2 - pos1 - pos2, sizeof(int), cmp_greater);
    for (int i = 1; i <= n1 + n2; i++) printf("%d ", c[i]);
    return 0;
}