#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int i = 0;
    int w = 0;
    
    while (str[i] != '\0') {
        if (*str == c) {
            while (*str == c && *str != '\0')
                str++;
        }
        if (*str != c && *str != '\0') {
            w++;
            while (*str != c && *str != '\0')
                str++;
        }
    }
    return w;
}
