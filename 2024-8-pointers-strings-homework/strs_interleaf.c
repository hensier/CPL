#include <stdio.h>
#include <string.h>
#include <ctype.h>
int T, ds1, ds2, siz;
char s1[1001], s2[1001];
int read(char *s) {
    int x = 0;
    char ch = getchar();
    while (!isalpha(ch) && !isdigit(ch)) ch = getchar();
    while (isalpha(ch) || isdigit(ch)) {
        *(s + (x++)) = ch;
        ch = getchar();
    }
    return x;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s1));
        int n = read(s1), m = read(s2);
        scanf("%d;%d;%d", &ds1, &ds2, &siz);
        siz--;
        for (int i = 0, j = 0; siz && (i < n || j < m); ) {
            for (int k = 0; k < ds1 && i < n && siz; k++, siz--) putchar(s1[i++]);
            for (int k = 0; k < ds2 && j < m && siz; k++, siz--) putchar(s2[j++]);
        }
        putchar('\n');
    }
    return 0;
}