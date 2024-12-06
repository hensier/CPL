#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
char ch;
bool flag = true;
int main() {
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            flag = true;
            putchar(' ');
            continue;
        }
        if (!isalpha(ch)) break;
        if (flag) putchar(toupper(ch));
        else putchar(tolower(ch));
        flag = false;
    }
    return 0;
}