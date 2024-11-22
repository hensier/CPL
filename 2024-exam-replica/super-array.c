#include <stdio.h>
#include <stdbool.h>
int m, N[1000];
int main() {
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &N[i]);
    for (int i = 0; i < m - 1; i++) {
        if (N[i] > N[i+1]) {
            printf("-1");
            return 0;
        }
    }
    for (int i = 1; i < m - 1; i++) {
        if (N[i+1] - N[i] <= N[i] - N[i-1]) {
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}