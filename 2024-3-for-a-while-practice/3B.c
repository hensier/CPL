#include <stdio.h>
int N;
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) printf("%dx%d=%d ", j, i, j * i);
        putchar('\n');
    }
    return 0;
}