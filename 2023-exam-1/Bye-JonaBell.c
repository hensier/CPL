#include <stdio.h>
int n, k, b, l, cur, bombs, dead, tails[1501];
int inc(int x) {
    if (++x > n) return x - n;
    return x;
}
int main() {
    scanf("%d%d%d%d", &n, &k, &b, &l);
    bombs = b;
    while (dead < n) {
        for (int j = 0; j < k; j += tails[cur = inc(cur)] != l);
        if (bombs-- == 0) bombs = b;
        else if (++tails[cur] == l) dead++;
    }
    printf("%d", cur);
    return 0;
}