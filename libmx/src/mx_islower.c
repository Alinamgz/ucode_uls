#include "libmx.h"

bool mx_islower(int c) {
    bool rslt = (c > 96 && c < 123 ) ? 1 : 0;

    return rslt;
}
