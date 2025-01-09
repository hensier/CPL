#include <stdio.h>
int n, width[26];
char canvas[26][247286];
int paint(int n, int x, int y, int type) {
    if (n == 0) return -1;
    if (n == 1) {
        canvas[x][y] = '\\';
        return -1;
    }
    int l = paint(n - 1, x, y, 1), r = paint(n - 2, x + 1, y + width[n-1] + 1, 0);
    if (n == 2) {
        l = y + 1;
        r = y + 2;
    }
    if (n == 3) r = y + 4;
    canvas[x+n-1][l] = '\\';
    canvas[x+n-1][r] = '/';
    for (int i = l + 1; i < r; i++) canvas[x+n-1][i] = '_';
    return type == 0 ? l : r;
}
int main() {
    scanf("%d", &n);
    width[0] = 1;
    width[1] = 1;
    for (int i = 2; i <= n; i++) width[i] = width[i-1] + width[i-2] + 1;
    paint(n, 0, 0, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < width[n]; j++) putchar(canvas[i][j] ? canvas[i][j] : ' ');
        putchar('\n');
    }
    return 0;
}