#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *rslt = mx_strtrim(str);
    char *final = NULL;
    int jump= 0;
    int i;

    if (rslt && *rslt) {      
        for( i = 0; rslt[i + jump]; i++) {
          if (mx_isspace(rslt[i + jump])) {
            rslt[i++] = ' ';
            for (; mx_isspace(rslt[i + jump]); jump++);
          }
          rslt[i] = rslt[i + jump];
        }
        rslt[i] = '\0';

        final = mx_strdup(rslt);
        mx_strdel(&rslt);
        return final;
    }
    return rslt;
}
