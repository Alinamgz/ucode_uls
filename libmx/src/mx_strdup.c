#include "libmx.h"

char *mx_strdup(const char *s1) {
    int src_size = mx_strlen(s1);
    char *result = mx_strnew(src_size);
    mx_strcpy(result, s1);

    return result;
}
