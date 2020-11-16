#include "libmx.h"

int mx_strlen(const char *s) {
    int p  = 0;
    while (*s++) {
        p++;
    }
    return p;
}
