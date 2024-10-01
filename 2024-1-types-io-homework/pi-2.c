#include <stdio.h>
#include <math.h>
int main() {
    printf("%.15lf\n%.15lf", log(pow(5280, 3) * pow(236674 + 30303 * sqrt(61), 3) + 744) / sqrt(427), 24 * atan(1.0 / 8) + 8 * atan(1.0 / 57) + 4 * atan(1.0 / 239));
    return 0;
}