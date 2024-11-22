#include <stdio.h>
int m, ans, tmp;
int main() {
    scanf("%d", &m);
    while (m) {
        int cur = tmp + m % 5;
        if (cur >= 3) {
            cur = 5 - cur;
            tmp = 1;
        }
        else tmp = 0;
        ans += cur;
        m /= 5;
    }
    printf("%d", ans + tmp);
    return 0;
}