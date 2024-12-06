#include <stdio.h>
#include <ctype.h>
char s[1024], t[1024], ans[1024];
int len, a[52];
int get_id(char c) {
    if (islower(c)) return c - 'a';
    return c - 'A' + 26;
}
int main() {
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) a[get_id(s[i])]++;
        else a[get_id(s[i-1])]++;
    }
    scanf("%s", s);
    len = sprintf(ans, "%s\n", s);
    while (scanf("%s", t) != EOF) {
        if (t[0] != '-') continue;
        int x = a[get_id(t[1])];
        switch (x) {
            case 0: {
                printf("%s: invalid option -- '%c'", s, t[1]);
                return 0;
            }
            case 1: {
                len += sprintf(ans + len, "%c\n", t[1]);
                break;
            }
            case 2: {
                char ch = t[1];
                if (scanf("%s", t) == EOF) {
                    printf("%s: option requires an argument -- '%c'", s, ch);
                    return 0;
                }
                len += sprintf(ans + len, "%c=%s\n", ch, t);
            }
        }
    }
    printf("%s", ans);
    return 0;
}