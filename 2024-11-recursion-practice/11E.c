#include <stdio.h>
int n;
char canvas[1025][2049];
void paint(int n, int x, int y) {
    if (n == 1) {
        canvas[x][y+1] = '/';
        canvas[x][y+2] = '\\';
        canvas[x+1][y] = '/';
        canvas[x+1][y+1] = '_';
        canvas[x+1][y+2] = '_';
        canvas[x+1][y+3] = '\\';
        return;
    }
    paint(n - 1, x, y + (1 << (n - 1)));
    paint(n - 1, x + (1 << (n - 1)), y);
    paint(n - 1, x + (1 << (n - 1)), y + (1 << n));
}
int main() {
    scanf("%d", &n);
    paint(n, 0, 0);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << (n + 1)); j++) putchar(canvas[i][j] ? canvas[i][j] : ' ');
        putchar('\n');
    }
    return 0;
}