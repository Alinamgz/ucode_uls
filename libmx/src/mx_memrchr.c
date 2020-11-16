#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *uc_s = (unsigned char*)s;
    unsigned char uc_c = (unsigned char)c;

    while (uc_s && (int)n >= 0) {
        if (*(uc_s + n) == uc_c) {
            return (uc_s + n);
        }
        n--;
    }

    return (void*)NULL;
}
