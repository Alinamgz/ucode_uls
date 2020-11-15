#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int src_len = mx_strlen(src);

    for(int i = 0; i < len; i++) {
        dst[i] = (i > src_len) ? '\0' : src[i];
    }

    return (char *) dst;
}
