#include <stdio.h>
#include <math.h>
int n, k;
double x[101], tau[21];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lf", &x[i]);
    for (int i = 1; i <= k; i++) scanf("%lf", &tau[i]);
    for (int i = 1; i <= k; i++) {
        double denom = 0, sum = 0;
        for (int j = 1; j <= n; j++) denom += exp(x[j] / tau[i]);
        for (int j = 1; j <= n; j++) {
            double y = exp(x[j] / tau[i]) / denom;
            printf("%.3lf ", y);
            sum += pow(y - 1.0 / n, 2);
        }
        printf("%.3lf\n", sum / n);
    }
    return 0;
}