#include "libmx.h"

void *mx_memccpy(void *restrict dst,
                 const void *restrict src, int c, size_t n) {
    unsigned char *cdst = (unsigned char *)dst;
    unsigned char *csrc = (unsigned char *)src;

    while(n > 0) {
        if (*csrc == c)
            return ++cdst;
        *cdst++ = *csrc++;
        n--;
    }
    return NULL;
}
