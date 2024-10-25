#include <stdio.h>
#include <ctype.h>
int n, maxc, cnt, l[26], u[26];
char s[1000];
int main() {
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; i++) {
        if (islower(s[i])) l[s[i]-'a']++;
        else u[s[i]-'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (l[i] > maxc) maxc = l[i];
        if (u[i] > maxc) maxc = u[i];
    }
    for (int i = maxc; i; i--) {
        for (int j = 0; j < 26; j++) {
            if (l[j] != 0 && u[j] != 0) {
                printf("%c%c ", l[j] >= i ? '=' : ' ', u[j] >= i ? '=' : ' ');
                if (i == 1) cnt += 3;
            }
            else if (l[j] != 0) {
                printf("%c ", l[j] >= i ? '=' : ' ');
                if (i == 1) cnt += 2;
            }
            else if (u[j] != 0) {
                printf("%c ", u[j] >= i ? '=' : ' ');
                if (i == 1) cnt += 2;
            }
        }
        putchar('\n');
    }
    for (int i = 1; i < cnt; i++) putchar('-');
    putchar('\n');
    for (int i = 0; i < 26; i++) {
        if (l[i] != 0 && u[i] != 0) printf("%c%c ", i + 'a', i + 'A');
        else if (l[i] != 0) printf("%c ", i + 'a');
        else if (u[i] != 0) printf("%c ", i + 'A');
    }
    return 0;
}