#include <stdio.h>
#include <math.h>
double m, R;
int main() {
    scanf("%lf%lf", &m, &R);
    printf("%.3e", 6.674e-11 * 77.15 * m / pow(R, 2));
    return 0;
}