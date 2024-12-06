#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int T;
char *s1, *s2, *s;
int main() {
    s1 = malloc(1001 * sizeof(char));
    s2 = malloc(1001 * sizeof(char));
    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", s1, s2);
        int n = strlen(s1), m = strlen(s2);
        bool flag = true;
        for (int i = (n < m ? n : m) - 1; i >= 0; i--) {
            flag = true;
            for (int j = 0; j <= i; j++) {
                if (*(s2 + j) != *(s1 + n + j - i - 1)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                printf("%s%s\n", s1, s2 + i + 1);
                break;
            }
        }
        if (!flag) printf("%s%s\n", s1, s2);
    }
    return 0;
}