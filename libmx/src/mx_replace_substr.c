#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    int i = 0;
    int ln = 0;
    char *new_s = mx_strdup(str);
    int num = mx_count_substr(str, sub);

    if(!sub || !str || !replace) 
        return NULL;
    while(num != 0) {
        i = mx_get_substr_index(new_s, sub);
        ln = mx_strlen(sub);
        if (i >= 0)
            for (int j = 0; ln != 0; j++) {
                new_s[i] = replace[j];
                ln--;
                i++;
            }
        num --;
    }
    return new_s;
}
