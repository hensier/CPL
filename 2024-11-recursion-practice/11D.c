#include <stdio.h>
#include <math.h>
const double eps = 1e-3;
int n, p, a[21];
double l, r;
double f(double x) {
    double s = 0;
    for (int i = 0; i <= n; i++) s += a[i] * pow(x, i);
    s = pow(s, p);
    return s;
}
double int_f(double a, double b) {
    return (4 * f((a + b) / 2) + f(a) + f(b)) / 6 * (b - a);
}
double solve(double l, double r, double S, double eps) {
    double mid = (l + r) / 2;
    double SL = int_f(l, mid), SR = int_f(mid, r);
    if (fabs(SL + SR - S) <= 15 * eps) return SL + SR + (SL + SR - S) / 15;
    return solve(l, mid, SL, eps / 2) + solve(mid, r, SR, eps / 2);
}
int main() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i <= n; i++) scanf("%d", &a[i]);
    scanf("%lf%lf", &l, &r);
    printf("%.6lf", solve(l, r, int_f(l, r), eps));
    return 0;
}