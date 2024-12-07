#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int n, type1[401], type2[401], pos[401], l1[401], l2[401];
char com[500001], s[1000001], t[1000001], c1[401][500001], c2[401][500001];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", com);
        switch (com[0]) {
            case '.': {
                type1[i] = 1;
                break;
            }
            case '^': {
                type1[i] = 2;
                break;
            }
            case '$': {
                type1[i] = 3;
                break;
            }
        }
        for (int j = 4; com[j]; j++) {
            switch (com[j]) {
                case '.': {
                    type2[i] = 1;
                    break;
                }
                case '^': {
                    type2[i] = 2;
                    break;
                }
                case '$': {
                    type2[i] = 3;
                    break;
                }
            }
            if (type2[i]) {
                pos[i] = j + 2;
                break;
            }
        }
        strncpy(c1[i], com + 2, pos[i] - 5);
        l1[i] = strlen(c1[i]);
        strncpy(c2[i], com + pos[i], strlen(com) - pos[i] - 1);
        l2[i] = strlen(c2[i]);
    }
    scanf("%s", s);
    while (true) {
        bool flag = false;
        int ls = strlen(s);
        for (int i = 1; i <= n; i++) {
            char *pos = NULL;
            switch (type1[i]) {
                case 1: {
                    pos = strstr(s, c1[i]);
                    break;
                }
                case 2: {
                    pos = strstr(s, c1[i]);
                    if (pos != s) pos = NULL;
                    break;
                }
                case 3: {
                    pos = strstr(s + ls - l1[i], c1[i]);
                    break;
                }
            }
            if (pos == NULL) continue;
            flag = true;
            switch (type2[i]) {
                case 1: {
                    strncpy(t, s, pos - s);
                    strcat(t, c2[i]);
                    strncat(t, pos + l1[i], ls - l1[i] - (pos - s));
                    break;
                }
                case 2: {
                    strcpy(t, c2[i]);
                    strncat(t, s, pos - s);
                    strncat(t, pos + l1[i], ls - l1[i] - (pos - s));
                    break;
                }
                case 3: {
                    strncpy(t, s, pos - s);
                    strncat(t, pos + l1[i], ls - l1[i] - (pos - s));
                    strcat(t, c2[i]);
                    break;
                }
            }
            break;
        }
        if (!flag) break;
        strcpy(s, t);
        for (int i = 0; t[i]; i++) t[i] = 0;
    }
    printf("%s", s);
    return 0;
}