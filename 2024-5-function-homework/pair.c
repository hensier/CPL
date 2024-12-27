#include <stdio.h>
#include <stdlib.h>
int n, m, t, ans = -1, a[1000000], b[1000000];
int cmp(const void *a, const void *b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}
int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    qsort(b, m, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (b[mid] > t - a[i]) r = mid - 1;
            else l = mid + 1;
        }
        if (r != -1 && (ans == -1 || t - a[i] - b[r] < ans)) ans = t - a[i] - b[r]; 
    }
    printf("%d", ans);
    return 0;
}