#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    size_t i = 0;
    unsigned char *p = (unsigned char *)s;

    for (i = 0; i < n; i++, p++)
        if (*p == c)
            return p;
    return NULL;
}
