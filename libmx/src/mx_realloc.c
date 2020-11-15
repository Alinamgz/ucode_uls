#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    unsigned char *rslt = NULL;
    size_t buf_len = malloc_size(ptr);

    if ((int)size >= 0) {
        if (size != 0 && buf_len > size) {
            return ptr;
        }
        rslt = (unsigned char*)malloc(size);
        if (size != 0 && ptr != NULL) {
            mx_memcpy(rslt, ptr, size);
        }
        free(ptr);
    }

    return rslt;
}
