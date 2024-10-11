#include <stdio.h>
#include <stdbool.h>
int n, a[200000];
bool flag[1000001];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n - 1; i++) {
        scanf("%d", &a[i]);
        flag[a[i]] = !flag[a[i]];
    }
    for (int i = 1; i <= 2 * n - 1; i++) {
        if (flag[a[i]]) {
            printf("%d", a[i]);
            return 0;
        }
    }
    return 0;
}