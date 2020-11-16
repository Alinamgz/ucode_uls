#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    int i = 0;
    const unsigned char *cs1 = (const unsigned char *)s1;
    const unsigned char *cs2 = (const unsigned char *)s2;

    if(mx_strlen(s1) == 0 && mx_strlen(s2) == 0)
        return 0;

    while (n > 0) {
        if(cs1[i] == cs2[i]) {
            i++;
            n--;
        }
        else
            return cs1[i] - cs2[i];
    }
    return 0;
}
