#include <stdio.h>
#include <ctype.h>
int len, N, ans;
char s[30];
int ctoi(char c) {
    if (isdigit(c)) return c - '0';
    return c - 'A' + 10;
}
int main() {
    scanf("%d%d%s", &len, &N, &s);
    for (int i = 0; i < len; i++) {
        int x = ctoi(s[i]);
        if (x >= N) {
            printf("Error");
            return 0;
        }
        ans = ans * N + x;
    }
    printf("%d", ans);
    return 0;
}