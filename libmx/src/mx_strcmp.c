#include "libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    int i;
    int result = 0;
    
    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            result = s1[i] - s2[i];
            break;
        }
    }
    return result;
}
