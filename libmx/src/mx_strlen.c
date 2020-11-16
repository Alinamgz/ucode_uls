#include "libmx.h"

int mx_strlen(const char *s) {
    int rslt;

    for(rslt = 0; s[rslt] != '\0'; rslt++);
    return rslt;
}
