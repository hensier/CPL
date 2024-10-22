#include <stdio.h>
#include <stdbool.h>
int n;
bool b[2001];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            b[j] = !b[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}