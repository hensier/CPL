#include <stdio.h>
int a, b, c;
char s[1001];
struct node {
    int x, y;
} p[4];
void swapi(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
void swapn(struct node *x, struct node *y) {
    struct node t = *x;
    *x = *y;
    *y = t;
}
int main() {
    scanf("%d%d%d%s", &a, &b, &c, s);
    p[1] = (struct node){a, 0};
    p[2] = (struct node){0, b};
    p[3] = (struct node){a, b};
    for (int i = 0; s[i]; i++) {
        switch (s[i]) {
            case 'W': {
                p[1] = (struct node){p[0].x - c, p[0].y};
                p[3] = (struct node){p[2].x - c, p[2].y};
                swapn(&p[0], &p[1]);
                swapn(&p[2], &p[3]);
                swapi(&a, &c);
                break;
            }
            case 'S': {
                p[0] = (struct node){p[1].x + c, p[1].y};
                p[2] = (struct node){p[3].x + c, p[3].y};
                swapn(&p[0], &p[1]);
                swapn(&p[2], &p[3]);
                swapi(&a, &c);
                break;
            }
            case 'A': {
                p[2] = (struct node){p[0].x, p[0].y - c};
                p[3] = (struct node){p[1].x, p[1].y - c};
                swapn(&p[0], &p[2]);
                swapn(&p[1], &p[3]);
                swapi(&b, &c);
                break;
            }
            case 'D': {
                p[0] = (struct node){p[2].x, p[2].y + c};
                p[1] = (struct node){p[3].x, p[3].y + c};
                swapn(&p[0], &p[2]);
                swapn(&p[1], &p[3]);
                swapi(&b, &c);
            }
        }
    }
    printf("%d %d %d %d", p[0].x, p[3].x, p[0].y, p[3].y);
    return 0;
}