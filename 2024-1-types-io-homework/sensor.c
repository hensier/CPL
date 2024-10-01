#include <stdio.h>
#include <string.h>
char name[21], unit;
int pre;
double frac, factor;
int main() {
    scanf("%s%d%lf%lf %c", name, &pre, &frac, &factor, &unit);
    if (strlen(name) < 2) printf("%s", name);
    else printf("%c%c", name[0], name[1]);
    printf(": %d (%.5lf) | %.5E %.5lf %c", pre, frac, pre + frac, (pre + frac) * factor, unit + 'A' - 'a');
    return 0;
}