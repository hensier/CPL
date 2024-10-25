#include <stdio.h>
int m;
double sumx, sumy, sumx2, sumxy, t[2] = {1, 1}, x[101], y[101];
int main() {
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
        sumx += x[i];
        sumy += y[i];
        sumx2 += x[i] * x[i];
        sumxy += x[i] * y[i];
    }
    for (int i = 0; i < 2000; i++) {
        double J[2];
        J[0] = (t[0] * m + t[1] * sumx - sumy) / m;
        J[1] = (t[0] * sumx + t[1] * sumx2 - sumxy) / m;
        for (int j = 0; j < 2; j++) t[j] -= 0.01 * J[j];
    }
    printf("y = %.3lf + %.3lfx", t[0], t[1]);
    return 0;
}