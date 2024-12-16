#include <stdio.h>
#include <string.h>
int n, q;
char question[101][101], answer[101][101], que[101], ans[5][101];
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%s%s", question[i], answer[i]);
    for (int i = 1; i <= q; i++) {
        scanf("%s%s%s%s%s", que, ans[1], ans[2], ans[3], ans[4]);
        for (int j = 1; j <= n; j++) {
            if (strcmp(question[j], que) == 0) {
                if (strcmp(answer[j], ans[1]) == 0) puts("A");
                if (strcmp(answer[j], ans[2]) == 0) puts("B");
                if (strcmp(answer[j], ans[3]) == 0) puts("C");
                if (strcmp(answer[j], ans[4]) == 0) puts("D");
                break;
            }
        }
    }
    return 0;
}