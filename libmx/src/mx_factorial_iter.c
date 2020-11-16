#include "libmx.h"

int mx_factorial_iter(int n) {
    long result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;

        if (result > INT_MAX) {
            return 0;
        }
    }

    return (int)result;
}
