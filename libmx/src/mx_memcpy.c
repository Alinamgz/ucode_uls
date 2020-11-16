#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *cdst = (unsigned char *)dst;
    unsigned char *csrc = (unsigned char *)src;

    while(n > 0) {
        *cdst++ = *csrc++;
        n--;
    }
    return dst;
}
