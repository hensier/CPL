#include <stdio.h>
int p1, p2, first, P1[10001], P2[10001];
char name[11];
void print(int coef, int pown) {
    if (coef == 0) {
        first--;
        return;
    }
    if (coef < 0) {
        putchar('-');
        coef = -coef;
    }
    else if (pown != first) putchar('+');
    if (coef != 1 || pown == 0) printf("%d", coef);
    if (pown != 0) {
        printf("%s", name);
        if (pown != 1) printf("^%d", pown);
    }
}
int main() {
    scanf("%d%d%s", &p1, &p2, name);
    for (int i = p1; i >= 0; i--) scanf("%d", &P1[i]);
    for (int i = p2; i >= 0; i--) scanf("%d", &P2[i]);
    first = p1 > p2 ? p1 : p2;
    for (int i = first; i >= 0; i--) print(P1[i] + P2[i], i);
    putchar('\n');
    first = p1 > p2 ? p1 : p2;
    for (int i = first; i >= 0; i--) print(P1[i] - P2[i], i);
    putchar('\n');
    first = p1 + p2;
    for (int i = first; i >= 0; i--) {
        int coef = 0;
        for (int j = i - p2 > 0 ? i - p2 : 0; j <= p1 && j <= i; j++) coef += P1[j] * P2[i-j];
        print(coef, i);
    }
    return 0;
}