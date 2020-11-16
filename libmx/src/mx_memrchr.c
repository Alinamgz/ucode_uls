#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const char *p = (const char *)s;
    int size = mx_strlen(p);
    int i = size - 1;

    while (n > 0) {
        if(p[i] == c) {
            p += i;
            return (void *)p;
        }
        i--;
        n--;
    }
    return NULL;
}
