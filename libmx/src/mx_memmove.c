#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
   unsigned char *p = malloc(len);

   mx_memcpy(p, src, len);
   mx_memcpy(dst, p, len);
   free(p);
   return dst;
}
