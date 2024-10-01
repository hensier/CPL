#include <stdio.h>
#include <math.h>
int p, q;
double cubic_root(double a) {
    if (a < 0) return -pow(-a, 1.0 / 3);
    return pow(a, 1.0 / 3);
}
int main() {
    scanf("%d%d", &p, &q);
    printf("%.3lf", cubic_root(sqrt(pow(q / 2.0, 2) + pow(p / 3.0, 3)) - q / 2.0) + cubic_root(-sqrt(pow(q / 2.0, 2) + pow(p / 3.0, 3)) - q / 2.0));
    return 0;
}