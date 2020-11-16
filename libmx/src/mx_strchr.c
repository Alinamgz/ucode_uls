#include "libmx.h"

char *mx_strchr(const char *s, int c) {
    if ((c > 255) || (c < 0))
        return 0;
    while (*s != '\0') {
        if (*s == c)
            return (char *)s;
        s++;
    }
    return 0;
}
