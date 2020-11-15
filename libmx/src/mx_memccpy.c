#include "libmx.h"

void *mx_memccpy(void *restrict dst,
                 const void *restrict src,
                 int c,
                 size_t n) {
    size_t i;
    unsigned char *m_dst = dst;
    const unsigned char *m_src = src;

    for (i = 0; i < n; i++) {
        m_dst[i] = m_src[i];
        if (m_src[i] == c) {
            return (m_dst + i + 1);
        }
    }
    return NULL;
}
