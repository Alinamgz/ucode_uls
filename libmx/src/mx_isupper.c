#include "libmx.h"

bool mx_isupper(int c) {
    bool rslt = (c > 64 && c < 91) ? 1 : 0;

    return rslt;
}
