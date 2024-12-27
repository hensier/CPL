#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int N, R, M, posr = -1, d[1000000];
long long D, s[1000000];
int cmp(const void *a, const void *b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}
bool check(int L) {
    int l = 0, r = N - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (d[mid] > L) r = mid - 1;
        else l = mid + 1;
    }
    return s[posr] - s[l-1] - 1LL * (posr - l + 1) * L >= D;
}
int main() {
    scanf("%d%d%d%lld", &N, &R, &M, &D);
    for (int i = 0; i < N; i++) scanf("%d", &d[i]);
    qsort(d, N, sizeof(int), cmp);
    for (int i = N - 1; i >= 0; i--) {
        if (d[i] < R) {
            posr = i;
            break;
        }
    }
    if (posr == -1) {
        printf("%d", M == 0 && D == 0 ? d[1] - 1 : -1);
        return 0;
    }
    s[0] = d[0];
    for (int i = 1; i < N; i++) s[i] = s[i-1] + d[i];
    int l = 0, r = d[posr-M+1] - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d", r);
    return 0;
}