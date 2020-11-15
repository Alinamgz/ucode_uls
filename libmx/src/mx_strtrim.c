#include "libmx.h"

char *mx_strtrim(const char *str) {
    char *rslt = NULL;
    int rslt_len = 0;

    if (str) {
        while (mx_isspace(*str)) {
            str++;
        }

        rslt_len = mx_strlen(str);
        while(rslt_len > 0 && mx_isspace(str[rslt_len - 1])) {
            rslt_len--;
        }

        rslt = mx_strndup(str, rslt_len);
    }

    return rslt;
}
