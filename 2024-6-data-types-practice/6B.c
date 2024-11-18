#include <stdio.h>
int n, l = 1, r, q[10001];
char s[5];
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        switch (s[0]) {
            case 'I': {
                scanf("%d", &q[++r]);
                break;
            }
            case 'O': {
                printf("%d\n", q[l++]);
                break;
            }
            case 'C': {
                if (l > r) puts("0 []");
                else {
                    printf("%d [%d", r - l + 1, q[l]);
                    for (int i = l + 1; i <= r; i++) printf(",%d", q[i]);
                    puts("]");
                }
                break;
            }
        }
    }
    return 0;
}