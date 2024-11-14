#include <stdio.h>
int n;
const char *ones[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};
const char *tens[] = {
    "0", "1", "twenty", "thirty", "forty", 
    "fifty", "sixty", "seventy", "eighty", "ninety"
};
void easy_conv(int n) {
    if (n >= 100) {
        printf("%s hundred", ones[n/100]);
        if (n % 100 != 0) {
            printf(" and ");
            n %= 100;
        }
        else return;
    }
    if (n < 20) printf("%s", ones[n]);
    else {
        printf("%s", tens[n/10]);
        if (n % 10 != 0) printf("-%s", ones[n%10]);
    }
}
int main() {
    scanf("%d", &n);
    if (n == 0) {
        printf("zero");
        return 0;
    }
    if (n == -2147483648) {
        printf("minus two billion one hundred and forty-seven million four hundred and eighty-three thousand six hundred and forty-eight");
        return 0;
    }
    if (n < 0) {
        printf("minus ");
        n = -n;
    }
    if (n >= 1000000000) {
        printf("%s billion", ones[n/1000000000]);
        n %= 1000000000;
        if (n != 0) printf(" ");
    }
    if (n >= 1000000) {
        easy_conv(n / 1000000);
        printf(" million");
        n %= 1000000;
        if (n != 0) printf(" ");
    }
    if (n >= 1000) {
        easy_conv(n / 1000);
        printf(" thousand");
        n %= 1000;
        if (n != 0) printf(" ");
    }
    if (n != 0) easy_conv(n);
    return 0;
}