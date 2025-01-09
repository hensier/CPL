#include <stdio.h>
int n;
long long ans[41];
long long solve(int n) {
    if (n == 0 || n == 1) return 1;
    if (ans[n] != 0) return ans[n];
    return ans[n] = solve(n - 1) + solve(n - 2);
}
int main() {
    scanf("%d", &n);
    printf("%lld", solve(n));
    return 0;
}