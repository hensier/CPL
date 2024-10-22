#include <stdio.h>
#include <string.h>
int a, b;
char op[2];
int qpow(int x, int y) {
    int s = 1;
    while (y) {
        if (y % 2 == 1) s *= x;
        x *= x;
        y /= 2;
    }
    return s;
}
int main() {
    while (scanf("%d %s %d", &a, &op, &b) != EOF) {
        switch (op[0]) {
            case '+': {
                printf("%d\n", a + b);
                break;
            }
            case '-': {
                printf("%d\n", a - b);
                break;
            }
            case '*': {
                printf("%d\n", strlen(op) == 1 ? a * b : qpow(a, b));
                break;
            }
            case '/': {
                if (strlen(op) == 1) printf("%d\n", a / b);
                else printf("%.3lf\n", 1.0 * a / b);
                break;
            }
            case '%': {
                printf("%d\n", a % b);
                break;
            }
        }
    }
    return 0;
}