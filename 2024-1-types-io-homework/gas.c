#include <stdio.h>
#include <math.h>
double P, L, T;
int main() {
    scanf("%lf%lf%lf", &P, &L, &T);
    printf("%.4e", P * pow(L, 3) / 8.314 / T);
    return 0;
}