#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
char ch;
bool flag;
int main() {
    while ((ch = getchar()) != EOF) {
        if (isupper(ch) && flag) printf(" %c", tolower(ch));
        else putchar(ch);
        flag = true;
    }
    return 0;
}