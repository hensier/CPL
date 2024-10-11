#include <stdio.h>
int n, cnt, maxn = 1;
int main() {
    scanf("%d", &n);
    while (n != 1) {
        ++cnt;
        if (n > maxn) maxn = n;
        if (n % 2 == 0) n = n / 2;
        else n = 3 * n + 1;
    }
    printf("%d %d", cnt, maxn);
    return 0;
}