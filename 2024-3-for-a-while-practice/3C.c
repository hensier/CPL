#include <stdio.h>
int m, n;
void print(int x) {
    if (x < 10) putchar(' ');
    printf("%d  ", x);
}
int main() {
    scanf("%d%d", &m, &n);
    if ((n + 6) % 7 == 0) n = 7;
    else n = (n + 6) % 7;
    for (int i = 1; i < n; i++) printf("    ");
    for (int i = 1; i <= 8 - n; i++) {
        print(i);
    }
    for (int i = 9 - n; i <= m; i++) {
        if ((i + n - 2) % 7 == 0) putchar('\n');
        print(i);
    }
    return 0;
}