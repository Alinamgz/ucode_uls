#include "libmx.h"

char *custom_swap_char (char s[]) {
    char c;
    int j = mx_strlen(s) - 1;

    for (int i = 0; i < j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
    }
    return s;
}
