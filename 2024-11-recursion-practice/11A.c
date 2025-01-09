#include <stdio.h>
int a, b;
long long C[35][35];
long long solve(int a, int b) {
    if (b == 0 || b == a) return 1;
    if (C[a][b] != 0) return C[a][b];
    return C[a][b] = solve(a - 1, b - 1) + solve(a - 1, b);
}
int main() {
    scanf("%d%d", &a, &b);
    printf("%lld", solve(a - 1, b - 1));
    return 0;
}