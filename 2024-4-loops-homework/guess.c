#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
char res[2];
int main() {
    for (unsigned long long l = 0, r = UINT_MAX; l <= r; ) {
        unsigned int mid = (l + r) >> 1;
        printf("%u\n", mid);
        fflush(stdout);
        scanf("%s", res);
        if (res[0] == 'G') r = mid - 1;
        else if (res[0] == 'L') l = mid + 1;
        else break;
    }
    return 0;
}