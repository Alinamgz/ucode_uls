#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *cb = (unsigned char *)b;

    while(len > 0) {
        *cb = c;
         cb++;
         len--;
    }
    return b;
}
