#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    const char *rslt = NULL;
    int cmp_rslt = 0;

    for (int i = 0; *(haystack + i) != '\0'; i++) {
        if (*(haystack + i) == *(needle)) {
            rslt = (haystack + i);

            cmp_rslt = mx_check_substr(rslt, needle);

            if (cmp_rslt == 0) {
                return (char*)rslt;
            }
        }
    }
    rslt = NULL;

    return (char *)rslt;
}
