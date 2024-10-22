#include <stdio.h>
int n, cnt;
char s[100000];
int rev(int x) {
    return x % 10 * 10 + x / 10;
}
void print(int x) {
    if (x < 10) printf("0");
    printf("%d", x);
}
int main() {
    scanf("%d%s", &n, s);
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == '?' && s[n-i-1] != '?') s[i] = s[n-i-1];
        if (s[i] != '?' && s[n-i-1] == '?') s[n-i-1] = s[i];
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') print(i < n / 2 ? cnt++: rev(--cnt));
        else putchar(s[i]);
    }
    return 0;
}