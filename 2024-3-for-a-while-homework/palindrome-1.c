#include <stdio.h>
int n;
char s[2000];
int main() {
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; i++) putchar(s[i] == '?' ? s[n-i-1] : s[i]);
    return 0;
}