#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *buf = (unsigned char*)malloc(len);

    mx_memcpy(buf, src, len);
    mx_memcpy(dst, buf, len);

    free(buf);
    buf = NULL;

    return dst;
}
