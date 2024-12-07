#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int N, R, M, posr = -1, ans = -1, d[1000000];
long long D;
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
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
    long long sum = 0;
    for (int i = posr; i > posr - M + 1 && i >= 0; i--) sum += d[i];
    for (int i = min(posr, posr - M + 1); i >= 0; i--) {
        sum += d[i];
        ans = max(ans, min(d[i] - 1, (sum - D) / (posr - i + 1)));
        if (ans == d[i] - 1) break;
    }
    printf("%d", ans);
    return 0;
}