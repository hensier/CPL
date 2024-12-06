#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, len;
char *s, *t;
int border(int x) {
    if (x < 0) return 0;
    if (x >= len) return len - 1;
    return x;
}
int main() {
    s = malloc(1001 * sizeof(char));
    t = malloc(1001 * sizeof(char));
    scanf("%d%s", &n, s);
    len = strlen(s);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < len; j++) {
            int *c = malloc(2 * sizeof(int));
            *c = 0;
            *(c + 1) = 0;
            for (int k = border(j - 3); k <= border(j + 3); k++) {
                if (k != j && *(s + k) != '.') {
                    (*(c + *(s + k) - 'A'))++;
                }
            }
            if (*(s + j) == '.') {
                if (*c >= 2 && *c <= 4 && *(c + 1) == 0) *(t + j) = 'A';
                else if (*(c + 1) >= 2 && *(c + 1) <= 4 && *c == 0) *(t + j) = 'B';
                else *(t + j) = *(s + j);
            }
            else {
                if (*(c + ((*(s + j) - 'A') ^ 1)) != 0 || *(c + (*(s + j) - 'A')) <= 1 || *(c + (*(s + j) - 'A')) >= 5) *(t + j) = '.';
                else *(t + j) = *(s + j);
            }
        }
        strcpy(s, t);
    }
    printf("%s", s);
    return 0;
}