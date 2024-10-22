#include <stdio.h>
#include <string.h>
#include <ctype.h>
char a[1002], b[1001];
void reverse(char *s, int len) {
    for (char *l = s, *r = s + len - 1; l < r; l++, r--) {
        char t = *l;
        *l = *r;
        *r = t;
    }
}
char *add(char *a, char *b) {
    if (strlen(a) < strlen(b)) {
        char t[1002];
        strcpy(t, a);
        strcpy(a, b);
        strcpy(b, t);
    }
    int la = strlen(a), lb = strlen(b);
    reverse(a, la);
    reverse(b, lb);
    for (int i = 0; b[i]; i++) {
        a[i] += b[i] - '0';
        if (!isdigit(a[i])) {
            a[i] -= 10;
            if (la == lb && i == lb - 1) {
                strcat(a, "1");
                la++;
            }
            else a[i+1]++;
        }
    }
    for (int i = lb; a[i] && !isdigit(a[i]); i++) {
        a[i] -= 10;
        if (i == la - 1) {
            strcat(a, "1");
            la++;
        }
        else a[i+1]++;
    }
    reverse(a, la);
    return a;
}
int main() {
    while (scanf("%s%s", a, b) != EOF) puts(add(a, b));
    return 0;
}