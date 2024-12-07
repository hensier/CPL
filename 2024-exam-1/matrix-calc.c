#include <stdio.h>
int op, n, A[100][100], B[100][100];
int main() {
    scanf("%d%d", &op, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    if (op == 4) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%d ", A[j][i]);
            putchar('\n');
        }
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    switch (op) {
        case 1: {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) printf("%d ", A[i][j] + B[i][j]);
                putchar('\n');
            }
            break;
        }
        case 2: {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) printf("%d ", A[i][j] - B[i][j]);
                putchar('\n');
            }
            break;
        }
        case 3: {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    long long C = 0;
                    for (int k = 0; k < n; k++) C += A[i][k] * B[k][j];
                    printf("%lld ", C);
                }
                putchar('\n');
            }
            break;
        }
    }
    return 0;
}