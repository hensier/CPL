#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char *S, *T;
int n, m;
int main() {
    S = malloc(100001 * sizeof(char));
    T = malloc(100001 * sizeof(char));
    scanf("%s%s", S, T);
    n = strlen(S);
    m = strlen(T);
    for (int i = 0; i + m - 1 < n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (*(S + i + j) != *(T + j)) {
                flag = false;
                break;
            }
        }
        if (flag) printf("%d " , i);
    }
    return 0;
}