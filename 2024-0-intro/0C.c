#include <stdio.h>
const char *s = "#include <stdio.h>%cconst char *s = %c%s%c;%cint main() {%c    printf(s, 10, 34, s, 34, 10, 10, 10);%c}";
int main() {
    printf(s, 10, 34, s, 34, 10, 10, 10);
}