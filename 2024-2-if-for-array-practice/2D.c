#include <stdio.h>
#include <string.h>
#include <math.h>
char N[11];
int M, n1, n2;
int main() {
    scanf("%s", N);
    M = strlen(N);
    for (int i = 0; N[i]; i++) {
        n1 = n1 * 10 + N[i] - '0';
        n2 += pow(N[i] - '0', M);
    }
    printf("%d", (n1 && n1 == n2) ? M : 0);
    return 0;
}