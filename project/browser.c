#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
const char ch_skip[] = "\n\r\t ";
char ans[11][51];
int X, COL[11][51];
bool EM[11][51], I[11][51], U[11][51], RESET[11][51];
enum type {
    _h, _p, _img, _div,
    _none = -1
};
enum color {
    red, blue, green,
    none = -1
};
enum direction {
    row, column
};
enum align {
    start, end, center, space_evenly
};
struct text {
    enum color c;
    bool em, i, u;
    char s[51];
};
struct image {
    char src[501];
    int width;
};
struct size {
    int w, h;
};
struct division {
    struct size siz;
    int cnt;
    enum direction dir;
    enum align ai, jc;
    enum type t[101];
    struct text txt[101];
    struct image img[101];
    struct division *div[101];
};
void init_text(struct text *txt) {
    txt -> c = none;
    txt -> em = false;
    txt -> i = false;
    txt -> u = false;
}
void init_division(struct division *d) {
    d -> siz.w = 0;
    d -> siz.h = 0;
    d -> cnt = 0;
    d -> dir = row;
    d -> ai = start;
    d -> jc = start;
    memset(d -> t, -1, sizeof(d -> t));
    for (int i = 0; i <= 100; i++) init_text(&d -> txt[i]);
    memset(d -> img, 0, sizeof(d -> img));
    for (int i = 0; i <= 100; i++) d -> div[i] = NULL;
}
struct division *create() {
    struct division *d = (struct division*)malloc(sizeof(struct division));
    init_division(d);
    return d;
}
void write_p(struct text txt, int x, int y) {
    bool reset = false;
    if (txt.c != -1) {
        COL[x][y] = txt.c;
        reset = true;
    }
    if (txt.em) {
        EM[x][y] = true;
        reset = true;
    }
    if (txt.i) {
        I[x][y] = true;
        reset = true;
    }
    if (txt.u) {
        U[x][y] = true;
        reset = true;
    }
    int len = (int)strlen(txt.s);
    for (int j = 0; j < len; j++) ans[x][y+j] = txt.s[j];
    if (reset) RESET[x][y+len-1] = true;
}
void write_h(struct text txt, int x, int y) {
    for (int i = 0; txt.s[i]; i++) txt.s[i] = toupper(txt.s[i]);
    write_p(txt, x, y);
}
void write_img(struct image img, int x, int y) {
    for (int i = x, j = y, k = 0; img.src[k]; j++, k++) {
        if (j - y == img.width) {
            i++;
            j = y;
        }
        ans[i][j] = img.src[k];
    }
}
struct size siz_txt(struct text txt) {
    return (struct size){(int)strlen(txt.s), 1};
}
struct size siz_img(struct image img) {
    return (struct size){img.width, (int)strlen(img.src) / img.width};
}
struct size siz_div(struct division *d) {
    int maxw = 0, maxh = 0, sumw = 0, sumh = 0;
    for (int i = 1; i <= d -> cnt; i++) {
        struct size cur;
        switch (d -> t[i]) {
            case _h: case _p: {
                cur = siz_txt(d -> txt[i]);
                break;
            }
            case _img: {
                cur = siz_img(d -> img[i]);
                break;
            }
            case _div: {
                cur = siz_div(d -> div[i]);
                break;
            }
            default: assert(false);
        }
        if (cur.w > maxw) maxw = cur.w;
        if (cur.h > maxh) maxh = cur.h;
        sumw += cur.w;
        sumh += cur.h;
    }
    struct size siz = (struct size){d -> dir == row ? maxw: sumw, d -> dir == column ? maxh: sumh};
    if (d -> siz.w != 0) siz.w = d -> siz.w;
    if (d -> siz.h != 0) siz.h = d -> siz.h;
    return siz;
}
void write_div(struct division *d, int x, int y) {
    if (d -> siz.w == 0 || d -> siz.h == 0) d -> siz = siz_div(d);
    struct size sonsiz[101];
    for (int i = 1; i <= d -> cnt; i++) {
        switch (d -> t[i]) {
            case _h: case _p: {
                sonsiz[i] = siz_txt(d -> txt[i]);
                break;
            }
            case _img: {
                sonsiz[i] = siz_img(d -> img[i]);
                break;
            }
            case _div: {
                sonsiz[i] = siz_div(d -> div[i]);
                break;
            }
            default: assert(false);
        }
    }
    int sonx[101] = {}, sony[101] = {};
    switch (d -> dir) {
        case row: {
            switch (d -> ai) {
                case start: {
                    sonx[1] = x;
                    for (int i = 2; i <= d -> cnt; i++) sonx[i] = sonx[i-1] + sonsiz[i-1].h;
                    break;
                }
                case end: {
                    sonx[d->cnt] = x + d->siz.h - sonsiz[d->cnt].h;
                    for (int i = d -> cnt - 1; i >= 1; i--) sonx[i] = sonx[i+1] - sonsiz[i].h;
                    break;
                }
                case center: {
                    int sumh = 0;
                    for (int i = 1; i <= d -> cnt; i++) sumh += sonsiz[i].h;
                    sonx[1] = x + (d -> siz.h - sumh) / 2;
                    for (int i = 2; i <= d -> cnt; i++) sonx[i] = sonx[i-1] + sonsiz[i-1].h;
                    break;
                }
                case space_evenly: {
                    int sumh = 0;
                    for (int i = 1; i <= d -> cnt; i++) sumh += sonsiz[i].h;
                    sonx[1] = x + (d -> siz.h - sumh) / (d -> cnt + 1);
                    for (int i = 2; i <= d -> cnt; i++) sonx[i] = sonx[i-1] + sonsiz[i-1].h + (d -> siz.h - sumh) / (d -> cnt + 1);
                    break;
                }
            }
            switch (d -> jc) {
                case start: {
                    for (int i = 1; i <= d -> cnt; i++) sony[i] = y;
                    break;
                }
                case end: {
                    for (int i = 1; i <= d -> cnt; i++) sony[i] = y + d -> siz.w - sonsiz[i].w;
                    break;
                }
                case center: case space_evenly: {
                    for (int i = 1; i <= d -> cnt; i++) sony[i] = y + (d -> siz.w - sonsiz[i].w) / 2;
                    break;
                }
            }
            break;
        }
        case column: {
            switch (d -> ai) {
                case start: {
                    for (int i = 1; i <= d -> cnt; i++) sonx[i] = x;
                    break;
                }
                case end: {
                    for (int i = 1; i <= d -> cnt; i++) sonx[i] = x + d -> siz.h - sonsiz[i].h;
                    break;
                }
                case center: case space_evenly: {
                    for (int i = 1; i <= d -> cnt; i++) sonx[i] = x + (d -> siz.h - sonsiz[i].h) / 2;
                    break;
                }
            }
            switch (d -> jc) {
                case start: {
                    sony[1] = y;
                    for (int i = 2; i <= d -> cnt; i++) sony[i] = sony[i-1] + sonsiz[i-1].w;
                    break;
                }
                case end: {
                    sony[d->cnt] = y + d->siz.w - sonsiz[d->cnt].w;
                    for (int i = d -> cnt - 1; i >= 1; i--) sony[i] = sony[i+1] - sonsiz[i].w;
                    break;
                }
                case center: {
                    int sumw = 0;
                    for (int i = 1; i <= d -> cnt; i++) sumw += sonsiz[i].w;
                    sony[1] = y + (d -> siz.w - sumw) / 2;
                    for (int i = 2; i <= d -> cnt; i++) sony[i] = sony[i-1] + sonsiz[i-1].w;
                    break;
                }
                case space_evenly: {
                    int sumw = 0;
                    for (int i = 1; i <= d -> cnt; i++) sumw += sonsiz[i].w;
                    sony[1] = y + (d -> siz.w - sumw) / (d -> cnt + 1);
                    for (int i = 2; i <= d -> cnt; i++) sony[i] = sony[i-1] + sonsiz[i-1].w + (d -> siz.w - sumw) / (d -> cnt + 1);
                    break;
                }
            }
            break;
        }
        default: assert(false);
    }
    for (int i = 1; i <= d -> cnt; i++) {
        switch (d -> t[i]) {
            case _h: {
                write_h(d -> txt[i], sonx[i], sony[i]);
                break;
            }
            case _p: {
                write_p(d -> txt[i], sonx[i], sony[i]);
                break;
            }
            case _img: {
                write_img(d -> img[i], sonx[i], sony[i]);
                break;
            }
            case _div: {
                write_div(d -> div[i], sonx[i], sony[i]);
                break;
            }
            default: assert(false);
        }
    }
}
char getch() {
    for (char ch = getchar(); ; ch = getchar()) {
        bool skip = false;
        for (int i = 0; ch_skip[i]; i++) {
            if (ch == ch_skip[i]) {
                skip = true;
                break;
            }
        }
        if (!skip) return ch;
    }
}
void skip_ch(int n) {
    for (int i = 0; i < n; i++) getch();
}
void read_till(char *s, char c) {
    int l = 0;
    while (true) {
        s[l++] = getchar();
        if (s[l-1] == c) {
            s[l-1] = '\0';
            break;
        }
    }
}
int read_int() {
    char s[3];
    read_till(s, '\"');
    int x = s[0] - '0';
    if (strlen(s) == 2) x = x * 10 + s[1] - '0';
    return x;
}
struct text read_txt(enum type t, enum color c, bool em, bool i, bool u) {
    struct text txt;
    init_text(&txt);
    txt.c = c;
    txt.em = em;
    txt.i = i;
    txt.u = u;
    while (true) {
        char ch_p = getch();
        if (ch_p == '>') break;
        switch (ch_p) {
            case 'e': {
                txt.em = true;
                skip_ch(1);
                break;
            }
            case 'i': {
                txt.i = true;
                break;
            }
            case 'u': {
                txt.u = true;
                break;
            }
            case 'c': {
                skip_ch(6);
                char ch_c = getch();
                switch (ch_c) {
                    case 'r': {
                        txt.c = red;
                        skip_ch(3);
                        break;
                    }
                    case 'b': {
                        txt.c = blue;
                        skip_ch(4);
                        break;
                    }
                    case 'g': {
                        txt.c = green;
                        skip_ch(5);
                        break;
                    }
                }
                break;
            }
        }
    }
    read_till(txt.s, '<');
    skip_ch(3);
    return txt;
}
struct image read_img() {
    struct image img;
    while (true) {
        char ch_p = getch();
        if (ch_p == '>') break;
        switch (ch_p) {
            case 's': {
                skip_ch(4);
                read_till(img.src, '\"');
                break;
            }
            case 'w': {
                skip_ch(6);
                img.width = read_int();
                break;
            }
        }
    }
    skip_ch(6);
    return img;
}
struct division *read_div(enum color c, bool em, bool i, bool u) {
    struct division *div = create();
    while (true) {
        char ch_p = getch();
        if (ch_p == '>') break;
        switch (ch_p) {
            case 'e': {
                em = true;
                skip_ch(1);
                break;
            }
            case 'i': {
                i = true;
                break;
            }
            case 'u': {
                u = true;
                break;
            }
            case 'c': {
                skip_ch(6);
                char ch_c = getch();
                switch (ch_c) {
                    case 'r': {
                        c = red;
                        skip_ch(3);
                        break;
                    }
                    case 'b': {
                        c = blue;
                        skip_ch(4);
                        break;
                    }
                    case 'g': {
                        c = green;
                        skip_ch(5);
                        break;
                    }
                }
                break;
            }
            case 'w': {
                skip_ch(2);
                div -> siz.w = read_int();
                break;
            }
            case 'h': {
                skip_ch(2);
                div -> siz.h = read_int();
                break;
            }
            case 'd': {
                skip_ch(10);
                char ch_d = getch();
                switch (ch_d) {
                    case 'r': {
                        div -> dir = row;
                        skip_ch(3);
                        break;
                    }
                    case 'c': {
                        div -> dir = column;
                        skip_ch(6);
                        break;
                    }
                    default: assert(false);
                }
                break;
            }
            case 'a': {
                skip_ch(12);
                char ch_a[2];
                ch_a[0] = getch();
                ch_a[1] = getch();
                switch (ch_a[0]) {
                    case 's': {
                        switch (ch_a[1]) {
                            case 't': {
                                div -> ai = start;
                                skip_ch(4);
                                break;
                            }
                            case 'p': {
                                div -> ai = space_evenly;
                                skip_ch(11);
                                break;
                            }
                            default: assert(false);
                        }
                        break;
                    }
                    case 'c': {
                        div -> ai = center;
                        skip_ch(5);
                        break;
                    }
                    case 'e': {
                        div -> ai = end;
                        skip_ch(2);
                        break;
                    }
                    default: assert(false);
                }
                break;
            }
            case 'j': {
                skip_ch(16);
                char ch_j[2];
                ch_j[0] = getch();
                ch_j[1] = getch();
                switch (ch_j[0]) {
                    case 's': {
                        switch (ch_j[1]) {
                            case 't': {
                                div -> jc = start;
                                skip_ch(4);
                                break;
                            }
                            case 'p': {
                                div -> jc = space_evenly;
                                skip_ch(11);
                                break;
                            }
                            default: assert(false);
                        }
                        break;
                    }
                    case 'c': {
                        div -> jc = center;
                        skip_ch(5);
                        break;
                    }
                    case 'e': {
                        div -> jc = end;
                        skip_ch(2);
                        break;
                    }
                    default: assert(false);
                }
                break;
            }
        }
    }
    for (char ch = getch(); ch != EOF; ch = getch()) {
        if (ch != '<') break;
        char ch_t = getch();
        enum type t = _none;
        if (ch_t == '/') {
            skip_ch(4);
            return div;
        }
        switch (ch_t) {
            case 'h': {
                t = _h;
                break;
            }
            case 'p': {
                t = _p;
                break;
            }
            case 'i': {
                t = _img;
                skip_ch(2);
                break;
            }
            case 'd': {
                t = _div;
                skip_ch(2);
                break;
            }
            default: assert(false);
        }
        div -> t[++div->cnt] = t;
        switch (t) {
            case _h: case _p: {
                div -> txt[div->cnt] = read_txt(t, c, em, i, u);
                break;
            }
            case _img: {
                div -> img[div->cnt] = read_img();
                break;
            }
            case _div: {
                div -> div[div->cnt] = read_div(c, em, i, u);
                break;
            }
            default: assert(false);
        }
    }
    skip_ch(5);
    return div;
}
int main() {
    memset(COL, -1, sizeof(COL));
    for (char ch = getch(); ch != EOF; ch = getch()) {
        assert(ch == '<');
        char ch_t = getch();
        enum type t = _none;
        switch (ch_t) {
            case 'h': {
                t = _h;
                break;
            }
            case 'p': {
                t = _p;
                break;
            }
            case 'i': {
                t = _img;
                skip_ch(2);
                break;
            }
            case 'd': {
                t = _div;
                skip_ch(2);
                break;
            }
            default: assert(false);
        }
        switch (t) {
            case _h: {
                struct text txt_h = read_txt(t, none, false, false, false);
                write_h(txt_h, X, 0);
                X++;
                break;
            }
            case _p: {
                struct text txt_p = read_txt(t, none, false, false, false);
                write_p(txt_p, X, 0);
                X++;
                break;
            }
            case _img: {
                struct image img = read_img();
                write_img(img, X, 0);
                X += strlen(img.src) / img.width;
                break;
            }
            case _div: {
                struct division *div = read_div(none, false, false, false);
                write_div(div, X, 0);
                X += div -> siz.h;
                break;
            }
            default: assert(false);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            switch (COL[i][j]) {
                case red: {
                    printf("\033[31m");
                    break;
                }
                case blue: {
                    printf("\033[34m");
                    break;
                }
                case green: {
                    printf("\033[32m");
                    break;
                }
            }
            if (EM[i][j]) printf("\033[1m");
            if (I[i][j]) printf("\033[3m");
            if (U[i][j]) printf("\033[4m");
            putchar(ans[i][j] ? ans[i][j] : ' ');
            if (RESET[i][j]) printf("\033[0m");
        }
        putchar('\n');
    }
    return 0;
}