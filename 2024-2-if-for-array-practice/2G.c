#include <stdio.h>
int n, k;
char s[10000001];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char ch = getchar();
        while (ch == '\n') ch = getchar();
        s[i] = ch;
    }
    scanf("%d", &k);
    if (k >= 1) {
        for (int i = k - 1; i >= 0; i--) putchar(s[i]);
    }
    if (k <= n - 1) {
        for (int i = n - 1; i >= k; i--) putchar(s[i]);
    }
    return 0;
}