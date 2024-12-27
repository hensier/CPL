#include <stdio.h>
#include <stdbool.h>
int n, target[100001];
char s[100001][21];
bool vis[100001];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s%d", s[i], &target[i]);
    for (int i = 1; i >= 1 && i <= n; i = target[i]) {
        if (vis[i]) {
            printf("%s", s[i]);
            return 0;
        }
        vis[i] = true;
    }
    printf("-1");
    return 0;
}