#include <stdio.h>
int a, b, c;
int main() {
    scanf("%d%d%d", &a, &b, &c);
    if (a + b <= c) printf("not");
    else if (a == b && b == c) printf("equilateral");
    else if (a * a + b * b == c * c) printf("right");
    else if (a * a + b * b > c * c) {
        printf("acute");
        if (a == b || b == c) printf(" isosceles");
    }
    else {
        printf("obtuse");
        if (a == b) printf(" isosceles");
    }
    printf(" triangle");
    return 0;
}