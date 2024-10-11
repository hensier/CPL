#include <stdio.h>
#include <math.h>
double x, ans;
int n;
int main() {
    scanf("%lf%d", &x, &n);
    for (int i = 0; i <= n; i++) {
        double cur = pow(x, 2 * i + 1) / (2 * i + 1);
        if (i % 2 == 0) ans += cur;
        else ans -= cur;
    }
    ans *= 4;
    printf("%.10lf", ans);
    return 0;
}