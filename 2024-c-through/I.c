#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int ST, cnt;
char name[10001];
int s[50001], ns[50001];
int main() {
    scanf("%s%d", name, &ST);
    for (int i = 0; name[i]; i++) {
        int x = name[i] - 'A' + ST;
        for (int l = log10(x); l >= 0; l--) s[++cnt] = (int)(x / pow(10, l)) % 10;
    }
    while (true) {
        for (int i = 1; i < cnt; i++) ns[i] = (s[i] + s[i + 1]) % 10;
        memcpy(s, ns, sizeof(ns));
        cnt--;
        if (cnt < 3 || (cnt == 3 && s[1] == 1 && s[2] == 0 && s[3] == 0)) break;
    }
    bool flag = false;
    for (int i = 1; i <= cnt; i++) {
        if (s[i] == 0 && !flag) continue;
        printf("%d", s[i]);
        flag = true;
    }
    if (!flag) printf("0");
    return 0;
}