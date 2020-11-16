#include "libmx.h"

int mx_lcm(int a, int b) {
    if (a == 0 && b == 0) return 0;

    int a_norm = (a < 0 && a != -2147483648) ? a * -1 : a;
    int b_norm = (b < 0 && b != -2147483648) ? b * -1 : b;

    return a_norm * b_norm / mx_gcd(a_norm, b_norm);
}
