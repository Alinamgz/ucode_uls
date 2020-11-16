#include "libmx.h"

char *mx_strtrim(const char *str) {
    int len = mx_strlen(str);
    int start_str = 0;
    int last = 0;
    char *p = NULL;

    if (!str)
    	return NULL;
    for (int i = 0; mx_isspace(str[i]); ++i) {
        start_str++;
    }
    for(int j = len - 1 ; mx_isspace(str[j]); --j) {
        last++;
    }
    p = mx_strnew(len - start_str - last);
    mx_strncpy(p, str + start_str , len - start_str - last);
    return p;
    mx_strdel(&p);
}
