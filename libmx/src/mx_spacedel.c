#include "libmx.h"

char *mx_spacedel(char *strn1, const char *str) {
    int j = 0;
    int size = mx_strlen(str);

    for (int i = 0; i < size; i++) {
        if (mx_isspace(str[i])) {
            while(mx_isspace(str[i+1]))
                i++;
        }
        strn1[j] = str[i];
        j++;
    }
    return strn1;
}
