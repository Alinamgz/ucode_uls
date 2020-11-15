#include "libmx.h"

bool mx_isdigit(int c) {
    bool rslt = (c > 47 && c < 58) ? 1 : 0;

    return rslt;
}
