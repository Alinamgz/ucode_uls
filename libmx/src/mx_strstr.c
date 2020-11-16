#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int f = 0;
    int ln = mx_strlen(needle);

    while (*haystack != 0) {
        f = *haystack;
        if (mx_strncmp(haystack, needle, ln) == 0)
            return mx_strchr(haystack, f);
        haystack++;
    }
    return 0;
}
