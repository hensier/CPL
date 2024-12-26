#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
int n, len;
char op[2], s[16], t[22];
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s%s", op, s);
        if (op[0] == 't') {
            bool flag = true;
            int ans = 0;
            for (int i = 0; s[i]; i++) {
                if (s[i] != '0' && s[i] != '1' && s[i] != 'Z') {
                    flag = false;
                    break;
                }
                ans = ans * 3 + (s[i] == 'Z' ? -1 : s[i] - '0');
            }
            if (flag) printf("%d %s\n", ans, s);
            else puts("Radix Error");
        }
        else {
            bool flag = true, neg = (s[0] == '-');
            int val = 0, m = 0;
            for (int i = neg; s[i]; i++) {
                if (!isdigit(s[i])) {
                    flag = false;
                    break;
                }
                val = val * 10 + s[i] - '0';
            }
            if (!flag) {
                puts("Radix Error");
                continue;
            }
            printf("%s ", s);
            do {
                t[m++] = val % 3 + '0';
                val /= 3;
            } while (val);
            for (int i = 0; i < m; i++) {
                if (t[i] > '1') {
                    t[i] = t[i] == '2' ? 'Z' : '0';
                    if (i != m - 1) t[i+1]++;
                    else putchar(neg ? 'Z' : '1');
                }
            }
            for (int i = m - 1; i >= 0; i--) {
                if (t[i] == '1') putchar(neg ? 'Z': '1');
                else if (t[i] == 'Z') putchar(neg ? '1' : 'Z');
                else putchar(t[i]);
            }
            putchar('\n');
        }
    }
    return 0;
}