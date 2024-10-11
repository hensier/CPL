#include <stdio.h>
#include <stdbool.h>
int n, cnt, p[3001135];
bool flag[50000001];
int main() {
    scanf("%d", &n);
    flag[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!flag[i]) p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= n; j++) {
            flag[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
    printf("%d", cnt);
    return 0;
}