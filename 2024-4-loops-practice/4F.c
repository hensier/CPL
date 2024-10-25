#include <stdio.h>
#include <stdlib.h>
int xa, ya, xb, yb, xc, yc;
int main() {
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
    xb -= xa;
    yb -= ya;
    xc -= xa;
    yc -= ya;
    if (xb == 0 && xc == 0) {
        if ((yb > yc && yc > 0) || (yb < yc && yc < 0)) {
            printf("%d\n", abs(yb) + 2);
            putchar('R');
            for (int i = 0; i < abs(yb); i++) putchar(yb > 0 ? 'U' : 'D');
            putchar('L');
        }
        else {
            printf("%d\n", abs(yb));
            for (int i = 0; i < abs(yb); i++) putchar(yb > 0 ? 'U' : 'D');
        }
    }
    else if (yb == 0 && yc == 0) {
        if ((xb > xc && xc > 0) || (xb < xc && xc < 0)) {
            printf("%d\n", abs(xb) + 2);
            putchar('U');
            for (int i = 0; i < abs(xb); i++) putchar(xb > 0 ? 'R' : 'L');
            putchar('D');
        }
        else {
            printf("%d\n", abs(xb));
            for (int i = 0; i < abs(xb); i++) putchar(xb > 0 ? 'R' : 'L');
        }
    }
    else if (xc == 0 || yb == yc) {
        printf("%d\n", abs(xb) + abs(yb));
        for (int i = 0; i < abs(xb); i++) putchar(xb > 0 ? 'R' : 'L');
        for (int i = 0; i < abs(yb); i++) putchar(yb > 0 ? 'U' : 'D');
    }
    else {
        printf("%d\n", abs(xb) + abs(yb));
        for (int i = 0; i < abs(yb); i++) putchar(yb > 0 ? 'U' : 'D');
        for (int i = 0; i < abs(xb); i++) putchar(xb > 0 ? 'R' : 'L');
    }
    return 0;
}