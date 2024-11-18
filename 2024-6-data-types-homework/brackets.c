#include <stdio.h>
#include <stdbool.h>
int T, n;
char s[100001], st[100002];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        n = 0;
        bool flag = true;
        for (int i = 0; s[i]; i++) {
            switch (s[i]) {
                case '(': case '[': case '{': {
                    st[++n] = s[i];
                    break;
                }
                case ')': {
                    if (st[n--] != '(') flag = false;
                    break;
                }
                case ']': {
                    if (st[n--] != '[') flag = false;
                    break;
                }
                case '}': {
                    if (st[n--] != '{') flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        puts(flag && n == 0 ? "True": "False");
    }
    return 0;
}