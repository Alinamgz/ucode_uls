#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len,
                const void *little, size_t little_len) {
    unsigned char *str = (unsigned char *)big;
    unsigned char *sub_str = (unsigned char *)little;

    if (little_len && big_len != 0)
        if (big_len >= little_len)
            while(*str) {
                if (mx_memcmp(str, sub_str, little_len) == 0)
                    return str;
                str++;
            }
    return NULL;
}
