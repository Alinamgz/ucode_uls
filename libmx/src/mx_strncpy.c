#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;

    for (i = 0; i < len && src[i] != '\0'; i++) 
        dst[i] = src[i];
    for ( ; i < len; i++)
        dst[i] = '\0';
    return dst;
}
