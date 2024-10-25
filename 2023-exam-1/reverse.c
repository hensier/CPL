#include <stdio.h>
#include <ctype.h>
int n;
char s[100001];
int main() {
    scanf("%d%s", &n, s);
    for (int i = n - 1; i >= 0; i--) {
        if (isupper(s[i])) putchar(tolower(s[i]));
        else if (islower(s[i])) putchar(toupper(s[i]));
        else putchar(s[i]);
    }
    return 0;
}