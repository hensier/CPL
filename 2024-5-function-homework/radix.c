#include <stdio.h>
int p, q, r;
int to_dec(int x, int b) {
    int m = x / 10, n = x % 10;
    if (m >= b || n >= b) return -1;
    return m * b + n;
}
int main() {
    scanf("%d%d%d", &p, &q, &r);
    for (int B = 2; B <= 40; B++) {
        int P = to_dec(p, B), Q = to_dec(q, B), R = to_dec(r, B);
        if (P != -1 && Q != -1 && R != -1 && P * Q == R) {
            printf("%d", B);
            return 0;
        }
    }
    printf("0");
    return 0;
}