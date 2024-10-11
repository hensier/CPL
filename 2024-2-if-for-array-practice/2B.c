#include <stdio.h>
int h, m;
void print(int x) {
    if (x < 10) printf("0");
    printf("%d", x);
}
int main() {
    scanf("%d:%d", &h, &m);
    print(h <= 12 ? h : h - 12);
    printf(":");
    print(m);
    printf(h < 12 ? " a.m." : " p.m.");
    return 0;
}