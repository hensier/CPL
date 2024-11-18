#include <stdio.h>
int n, m;
char s[6], st[10001];
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        switch (s[0] + s[1]) {
            case 'p' + 'u': {
                scanf(" %c", &st[++m]);
                break;
            }
            case 'p' + 'o': {
                if (m == 0) puts("Empty");
                else m--;
                break;
            }
            case 't' + 'o': {
                if (m == 0) puts("Empty");
                else printf("%c\n", st[m]);
                break;
            }
            case 'p' + 'r': {
                if (m == 0) puts("Empty");
                else {
                    for (int i = m; i >= 1; i--) printf("| %c |\n", st[i]);
                    printf("|===|\n");
                }
                break;
            }
        }
    }
    return 0;
}