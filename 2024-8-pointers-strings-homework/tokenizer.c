#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
const char *res[] = {
    "const", "int", "float", "double",
    "long", "static", "void", "char",
    "extern", "return", "break", "enum",
    "struct", "typedef", "union", "goto"
};
const char *opt[] = {
    "+", "-", "*", "/", "=", 
    "==", "!=", ">=", "<=", ">", "<"
};
const char *out[] = {
    "", "reserved", "integer",
    "float", "operator", "variable"
};
int len;
char s[4096], ans[20001];
int get_type(char *s, int l, int r) {
    for (int i = 0; i < 16; i++) {
        int len = strlen(res[i]);
        if (r - l + 1 == len && strncmp(s + l, res[i], len) == 0) {
            return 1;
        }
    }
    bool flag = true;
    for (int i = l; i <= r; i++) {
        if (!isdigit(s[i])) {
            flag = false;
            break;
        }
    }
    if (flag) return 2;
    flag = true;
    bool dot = false;
    for (int i = l; i <= r; i++) {
        if (s[i] == '.') {
            if (dot) {
                flag = false;
                break;
            }
            dot = true;
        }
        else if (!isdigit(s[i])) {
            flag = false;
            break;
        }
    }
    if (flag && (!dot || l != r)) return 3;
    for (int i = 0; i < 11; i++) {
        int len = strlen(opt[i]);
        if (r - l + 1 == len && strncmp(s + l, opt[i], len) == 0) {
            return 4;
        }
    }
    flag = true;
    for (int i = l; i <= r; i++) {
        if (!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '_') {
            flag = false;
            break;
        }
    }
    if (flag && !isdigit(s[l])) return 5;
    return -1;
}
void compile(char *s, int l, int r) {
    if (l > r) return;
    int type = get_type(s, l, r);
    if (type == -1) {
        printf("Compile Error");
        exit(0);
    }
    len += sprintf(ans + len, "%s ", out[type]);
}
void split(char *s, int l, int r) {
    for (int i = l; i <= r; i++) {
        if (s[i] == ';') {
            compile(s, l, i - 1);
            len += sprintf(ans + len, "\n");
            split(s, i + 1, r);
            return;
        }
    }
    compile(s, l, r);
}
int main() {
    while (scanf("%s", s) != EOF) split(s, 0, strlen(s) - 1);
    while (s[strlen(s)-1] == ' ') s[strlen(s)-1] = '\0';
    if (s[strlen(s)-1] != ';') printf("Compile Error");
    else printf("%s", ans);
    return 0;
}