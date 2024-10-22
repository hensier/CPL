#include <stdio.h>
int n, k, pivot, l, r, a[1000000];
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
int find(int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    pivot = a[k-1];
    r = n - 1;
    while (l != r) {
        for (; l != r && a[l] < pivot; l++);
        for (; l != r && a[r] >= pivot; r--);
        if (l != r) swap(&a[l], &a[r]);
    }
    if (a[l] >= pivot && a[r] >= pivot) swap(&a[l], &a[find(pivot)]);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}