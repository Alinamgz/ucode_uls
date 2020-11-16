#include "libmx.h"

bool mx_islower(int c) {
    if (c >= 97 && c <=122)
        return 1;
    else
        return 0;
}
