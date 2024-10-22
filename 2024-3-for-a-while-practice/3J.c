#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
int T;
char op, a[20002], b[20001], ADD[20002], SUB[20002], EMUL[202], MUL[202], DIV[102];
void reverse(char *s, int len) {
    for (char *l = s, *r = s + len - 1; l < r; l++, r--) {
        char t = *l;
        *l = *r;
        *r = t;
    }
}
void swap(char *x, char *y) {
    char t[20002];
    strcpy(t, x);
    strcpy(x, y);
    strcpy(y, t);
}
void append(char *s, int ls, char c) {
    s[ls] = c;
    s[ls+1] = '\0';
}
bool smaller(char *a, char *b, int la, int lb) {
    if (la != lb) return la < lb;
    return strcmp(a, b) < 0;
}
char *add(char *a, char *b) {
    strcpy(ADD, a);
    if (strlen(ADD) < strlen(b)) swap(ADD, b);
    int la = strlen(ADD), lb = strlen(b);
    reverse(ADD, la);
    reverse(b, lb);
    for (int i = 0; b[i]; i++) {
        ADD[i] += b[i] - '0';
        if (!isdigit(ADD[i])) {
            ADD[i] -= 10;
            if (la == lb && i == lb - 1) append(ADD, la++, '1');
            else ADD[i+1]++;
        }
    }
    for (int i = lb; ADD[i] && !isdigit(ADD[i]); i++) {
        ADD[i] -= 10;
        if (i == la - 1) append(ADD, la++, '1');
        else ADD[i+1]++;
    }
    reverse(ADD, la);
    return ADD;
}
char *subtract(char *a, char *b) {
    strcpy(SUB, a);
    bool neg = false;
    if (smaller(SUB, b, strlen(SUB), strlen(b))) {
        neg = true;
        swap(SUB, b);
    }
    int la = strlen(SUB), lb = strlen(b);
    reverse(SUB, la);
    reverse(b, lb);
    for (int i = 0; b[i]; i++) {
        SUB[i] -= b[i] - '0';
        if (!isdigit(SUB[i])) {
            SUB[i] += 10;
            SUB[i+1]--;
        }
    }
    for (int i = lb; SUB[i] && !isdigit(SUB[i]); i++) {
        SUB[i] += 10;
        SUB[i+1]--;
    }
    reverse(SUB, la);
    int pos = 0;
    while (SUB[pos+1] && SUB[pos] == '0') pos++;
    memcpy(SUB, SUB + pos, la - pos);
    for (int i = la - pos; SUB[i]; i++) SUB[i] = '\0';
    if (neg) {
        char t[20002] = "";
        memcpy(t + 1, SUB, strlen(SUB));
        t[0] = '-';
        strcpy(SUB, t);
    }
    reverse(b, lb);
    return SUB;
}
char *easy_mul(char *a, char b) {
    strcpy(EMUL, a);
    int la = strlen(EMUL), tmp = 0;
    reverse(EMUL, la);
    for (int i = 0; EMUL[i]; i++) {
        int x = (EMUL[i] - '0') * (b - '0') + tmp;
        EMUL[i] = x % 10 + '0';
        tmp = x / 10;
    }
    if (tmp) append(EMUL, la++, tmp + '0');
    reverse(EMUL, la);
    return EMUL;
}
char *mul(char *a, char *b) {
    memset(MUL, 0, sizeof(MUL));
    MUL[0] = '0';
    char t1[202];
    strcpy(t1, a);
    for (int i = strlen(b) - 1; i >= 0; i--) {
        char t2[202];
        strcpy(t2, MUL);
        strcpy(MUL, add(t2, easy_mul(t1, b[i])));
        append(t1, strlen(t1), '0');
    }
    int pos = 0;
    while (MUL[pos+1] && MUL[pos] == '0') pos++;
    char t[202] = "";
    strncpy(t, MUL + pos, strlen(MUL) - pos);
    strcpy(MUL, t);
    return MUL;
}
char *div(char *a, char *b) {
    memset(DIV, 0, sizeof(DIV));
    int pa = -1, pd = 0, la, lb = strlen(b);
    char sa[202] = "", sb[11][202];
    do sa[pa] = a[++pa];
    while (a[pa] && smaller(sa, b, la = pa + 1, lb));
    for (int i = 1; i <= 10; i++) strcpy(sb[i], easy_mul(b, i + '0'));
    do {
        int coef = 0;
        while (coef <= 9 && !smaller(sa, sb[coef+1], la, strlen(sb[coef+1]))) coef++;
        append(DIV, pd++, coef + '0');
        strcpy(sa, subtract(sa, sb[coef]));
        la = strlen(sa);
        append(sa, la++, a[++pa]);
        if (sa[0] == '0') {
            char t[202] = "";
            strncpy(t, sa + 1, --la);
            strcpy(sa, t);
        }
    } while (a[pa]);
    return DIV;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s %c %s", a, &op, b);
        switch (op) {
            case '+': {
                printf("%s\n", add(a, b));
                break;
            }
            case '-': {
                printf("%s\n", subtract(a, b));
                break;
            }
            case '*': {
                printf("%s\n", mul(a, b));
                break;
            }
            case '/': {
                printf("%s\n", div(a, b));
                break;
            }
        }
    }
    return 0;
}