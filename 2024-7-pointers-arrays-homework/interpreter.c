#include <stdio.h>
int X;
int main() {
    scanf("%x", &X);
    printf("%d\n%u\n%f\n%.3e", X, X, *(float*)&X, *(float*)&X);
    return 0;
}