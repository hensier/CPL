#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int W, N, D, ans, a[1001];
bool vis[100001];
int solve(int id, long long inc) {
    memset(vis, false, sizeof(vis));
    for (int i = 0, j = a[id]; !vis[j]; i++, j = (j + inc) % N) {
        vis[j] = true;
        if (j == a[W-id+1]) return i;
    }
    return -1;
}
int main() {
    scanf("%d%d%d", &W, &N, &D);
    for (int i = 1; i <= W; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    for (int i = 1; i <= W / 2; i++) {
        int cur1 = solve(i, D);
        if (cur1 == -1) {
            printf("Impossible");
            return 0;
        }
        int cur2 = solve(i, 1LL * (N - 1) * D);
        if (cur1 < cur2) ans += cur1;
        else ans += cur2;
    }
    printf("%d", ans);
    return 0;
}