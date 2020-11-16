#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t ln = 0;
    char *dup = NULL;

    if (s1 == NULL && n == 0) {
        dup = mx_strnew(ln);
        return dup;
    }
    if ((ln = mx_strlen(s1)) > n) 
        dup = mx_strnew(ln);
    else
        dup = mx_strnew(n);

    mx_strncpy(dup, s1, n);
    return dup;
}
