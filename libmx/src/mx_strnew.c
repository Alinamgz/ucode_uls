#include "libmx.h"

char *mx_strnew(const int size) {
    char *result = (char *)malloc(size + 1);

    if (size < 0 || result == NULL) {
        return NULL;
    }

    for (int i = 0; i <= size; i++) {
        result[i] = '\0';
    }
    return result;
}
