#include <stdio.h>
#include <stdbool.h>
int n, m, q, A[2501][2501];
struct node {
    int x, y;
} nxtr[2501][2501], nxtc[2501][2501];
void swap(struct node *a, struct node *b) {
    struct node t = *a;
    *a = *b;
    *b = t;
}
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            A[i][j] = i * m + j;
            nxtr[i][j] = (struct node){i + 1, j};
            nxtc[i][j] = (struct node){i, j + 1};
        }
    }
    for (int i = 1, a; i <= q; i++) {
        struct node p[4], p1 = {}, p3 = {};
        for (int j = 1; j <= 4; j++) scanf("%d%d", &p[j].x, &p[j].y);
        scanf("%d", &a);
        int h = p[2].x - p[1].x + 1, w = p[2].y - p[1].y + 1;
        for (int j = 1; j < p[1].x; j++) p1 = nxtr[p1.x][p1.y];
        for (int j = 1; j < p[1].y; j++) p1 = nxtc[p1.x][p1.y];
        for (int j = 1; j < p[3].x; j++) p3 = nxtr[p3.x][p3.y];
        for (int j = 1; j < p[3].y; j++) p3 = nxtc[p3.x][p3.y];
        struct node r1[5001] = {}, r2[5001] = {}, c1[5001] = {}, c2[5001] = {};
        struct node A1 = p1, A2 = p3;
        for (int j = 1; j <= h; j++) {
            A1 = nxtr[A1.x][A1.y];
            A2 = nxtr[A2.x][A2.y];
            c1[j] = (struct node){A1.x, A1.y};
            c2[j] = (struct node){A2.x, A2.y};
        }
        for (int j = 1; j <= w; j++) {
            A1 = nxtc[A1.x][A1.y];
            A2 = nxtc[A2.x][A2.y];
            r1[j] = (struct node){A1.x, A1.y};
            r2[j] = (struct node){A2.x, A2.y};
        }
        struct node B1 = p1, B2 = p3;
        for (int j = 1; j <= w; j++) {
            B1 = nxtc[B1.x][B1.y];
            B2 = nxtc[B2.x][B2.y];
            r1[w+j] = (struct node){B1.x, B1.y};
            r2[w+j] = (struct node){B2.x, B2.y};
        }
        for (int j = 1; j <= h; j++) {
            B1 = nxtr[B1.x][B1.y];
            B2 = nxtr[B2.x][B2.y];
            c1[h+j] = (struct node){B1.x, B1.y};
            c2[h+j] = (struct node){B2.x, B2.y};
        }
        for (int j = 1; j <= 2 * w; j++) swap(&nxtr[r1[j].x][r1[j].y], &nxtr[r2[j].x][r2[j].y]);
        for (int j = 1; j <= 2 * h; j++) swap(&nxtc[c1[j].x][c1[j].y], &nxtc[c2[j].x][c2[j].y]);
        struct node ans = {};
        for (int j = 1; j <= a; j++) ans = nxtr[ans.x][ans.y];
        long long sum = 0;
        for (int j = 1; j <= m; j++) {
            ans = nxtc[ans.x][ans.y];
            sum += A[ans.x][ans.y];
        }
        printf("%lld\n", sum);
    }
    return 0;
}