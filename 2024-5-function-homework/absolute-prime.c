#include <stdio.h>
#include <stdbool.h>
int n, ans;
bool check(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int rev(int x) {
    int s = 0;
    while (x) {
        s = s * 10 + x % 10;
        x /= 10;
    }
    return s;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) ans += check(i) && check(rev(i));
    printf("%d", ans);
    return 0;
}