#include "libmx.h"

char *mx_strchr(const char *s, int c) {
    for (int i = 0; ; i++) {
        if (c != '\0' && s[i] == '\0') {
            break;
        }

        if (s[i] == c) {
            return (char *)s;
        }
    }
    return 0;
} 
