#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[9999], t[2], a[100][101];
int cmp(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}
int main() {
    scanf("%s%s", s, t);
    char *p = strtok(s, t);
    for (n = 1; ; n++) {
        if (p == NULL) break;
        strcpy(a[n], p);
        p = strtok(NULL, t);
    }
    n--;
    qsort(a + 1, n, sizeof(a[1]), cmp);
    for (int i = 1; i <= n; i++) puts(a[i]);
    return 0;
}