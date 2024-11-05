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
int main() {
    scanf("%d", &n);
    if (n == 0) {
        printf("zero");
        return 0;
    }
    if (n >= 100) {
        printf("%s hundred", ones[n/100]);
        if (n % 100 != 0) {
            printf(" and ");
            n %= 100;
        }
        else return 0;
    }
    if (n < 20) printf("%s", ones[n]);
    else {
        printf("%s", tens[n/10]);
        if (n % 10 != 0) printf("-%s", ones[n%10]);
    }
    return 0;
}