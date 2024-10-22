#include <stdio.h>
#include <stdbool.h>
int n, len;
char s[15];
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        bool flag = true;
        int ans = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] != '0' && s[i] != '1' && s[i] != 'Z') {
                flag = false;
                break;
            }
            ans = ans * 3 + (s[i] == 'Z' ? -1 : s[i] - '0');
        }
        if (flag) printf("%d\n", ans);
        else puts("Radix Error");
    }
    return 0;
}