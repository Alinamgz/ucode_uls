#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    unsigned char *p = NULL;
    size_t ln = malloc_size(ptr);

    if ((int)size < 0)
        return NULL;
    if (size != 0)
        if(ln > size)
            return ptr;

    p = malloc(size);
    if (ptr != NULL)
        p = mx_memcpy(p, ptr, size);

    free(ptr);
    return p;
}
