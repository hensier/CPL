#include <stdio.h>
#include <stdlib.h>
int N, u[500001], d[500001], l[500001], r[500001], U[500001], D[500001], L[500001], R[500001];
long long ans = 5000000000000000000, hp[500001], HP[500001];
struct node {
    int x, y, hp;
} a[500001];
int cmp(const void *a, const void *b) {
    return ((*(struct node*)a).x > (*(struct node*)b).x) - ((*(struct node*)a).x < (*(struct node*)b).x);
}
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].hp);
    qsort(a + 1, N, sizeof(struct node), cmp);
    u[1] = a[1].y;
    d[1] = a[1].y;
    l[1] = a[1].x;
    r[1] = a[1].x;
    U[N] = a[N].y;
    D[N] = a[N].y;
    L[N] = a[N].x;
    R[N] = a[N].x;
    hp[1] = a[1].hp;
    HP[N] = a[N].hp;
    for (int i = 2; i <= N; i++) {
        u[i] = max(u[i-1], a[i].y);
        d[i] = min(d[i-1], a[i].y);
        l[i] = min(l[i-1], a[i].x);
        r[i] = max(r[i-1], a[i].x);
        hp[i] = max(hp[i-1], a[i].hp);
    }
    for (int i = N - 1; i; i--) {
        U[i] = max(U[i+1], a[i].y);
        D[i] = min(D[i+1], a[i].y);
        L[i] = min(L[i+1], a[i].x);
        R[i] = max(R[i+1], a[i].x);
        HP[i] = max(HP[i+1], a[i].hp);
    }
    for (int i = 1; i <= N; i++) {
        if (i != N && a[i].x == a[i+1].x) continue;
        long long cur = 0;
        cur += 1LL * (u[i] - d[i] + 1) * (r[i] - l[i] + 1) * hp[i];
        if (i != N) cur += 1LL * (U[i+1] - D[i+1] + 1) * (R[i+1] - L[i+1] + 1) * HP[i+1];
        if (cur < ans) ans = cur;
    }
    printf("%lld", ans);
    return 0;
}