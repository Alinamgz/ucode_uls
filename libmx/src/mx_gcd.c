#include "libmx.h"

int mx_gcd(int a, int b) {
    int a_norm = (a < 0 && a != INT_MIN) ? a * -1 : a;
    int b_norm = (b < 0 && b != INT_MIN) ? b * -1 : b;

    if (b_norm != 0) {
        return mx_gcd(b_norm, a_norm % b_norm);
    }
    return a_norm;
}
