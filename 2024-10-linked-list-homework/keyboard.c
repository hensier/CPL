#include <stdio.h>
#include <ctype.h>
int Q, K, n, m, cnt;
char s[2000001], t[2000001];
struct node {
    int id;
    char c;
} lower[2000001], upper[2000001];
int main() {
    scanf("%d", &Q);
    while (Q--) {
        scanf("%s", s);
        if (s[0] == '?') {
            scanf("%d", &K);
            for (int i = 0, j = n, k = m; i < K; i++) {
                if (m == 0 || lower[j].id > upper[k].id) t[i] = lower[j--].c;
                else t[i] = upper[k--].c;
            }
            for (int i = K - 1; i >= 0; i--) putchar(t[i]);
            putchar('\n');
        }
        else {
            for (int i = 0; s[i]; i++) {
                switch (s[i]) {
                    case 'm': {
                        if (n != 0) n--;
                        break;
                    }
                    case 'M': {
                        if (m != 0) m--;
                        break;
                    }
                    default: {
                        if (islower(s[i])) lower[++n] = (struct node){++cnt, s[i]};
                        else upper[++m] = (struct node){++cnt, s[i]};
                    }
                }
            }
        }
    }
    return 0;
}