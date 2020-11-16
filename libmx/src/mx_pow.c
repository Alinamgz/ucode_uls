#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    double pow_n = n;
    if (pow == 0)
        return 1;
    else {
            for(unsigned int i = 1; i < pow; i++) 
            n = n * pow_n;
            return n;
    }
}
