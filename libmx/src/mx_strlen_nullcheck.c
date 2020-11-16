#include "libmx.h"

int mx_strlen_nullcheck(const char *s) {
    int rslt;

    if (s == NULL) {
        return 0;
    }

    for(rslt = 0; s[rslt] != '\0'; rslt++);
    return rslt;
}
