#include <stdio.h>
#include <string.h>
int T, a, b, c;
char s[85][85];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= 2 * b; i++) {
            for (int j = 1; j <= 2 * b - i + 1; j++) s[i][j] = ' ';
            s[i][2*b-i+2] = i % 2 ? '+' : '/';
            for (int j = 1; j <= a; j++) {
                s[i][2*(b+j)-i+1] = i % 2 ? '-': ' ';
                s[i][2*(b+j)-i+2] = i % 2 ? '+': '/';
            }
        }
        for (int i = 2 * b + 1; i <= 2 * (b + c) + 1; i++) {
            s[i][1] = i % 2 ? '+': '|';
            for (int j = 1; j <= a; j++) {
                s[i][2*j] = i % 2 ? '-' : ' ';
                s[i][2*j+1] = i % 2 ? '+': '|';
            }
        }
        for (int j = 2 * a + 2; j <= 2 * (a + b) + 1; j++) {
            for (int i = 1; i <= c; i++) {
                s[2*(a+b+i)-j+1][j] = j % 2 ? '|' : ' ';
                s[2*(a+b+i)-j+2][j] = j % 2 ? '+' : '/';
            }
        }
        for (int i = 1; i <= 2 * (b + c) + 1; i++) {
            for (int j = 1; j <= 2 * (a + b) + 1; j++) putchar(s[i][j] ? s[i][j] : ' ');
            putchar('\n');
        }
    }
    return 0;
}