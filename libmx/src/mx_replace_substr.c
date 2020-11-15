#include "libmx.h"

char *mx_replace_substr(const char *str,
                        const char *sub,
                        const char *replace) {
    char *rslt = NULL;
    t_for_replsub *cur = NULL;

    if (str && sub && replace) {
        cur = mx_set_struct(str, sub, replace);
        rslt = mx_strnew(cur->rslt_len);
        while (*(str + cur->str_i)) {
            if (cur->sub_pnt && (str + cur->str_i) == cur->sub_pnt) {
                mx_strcat(rslt, replace);
                cur->str_i += cur->sub_len;
                cur->rslt_i += cur->repl_len;
                cur->sub_pnt = mx_strstr((str + cur->str_i), sub);
            }
            else
                *(rslt + cur->rslt_i++) = *(str + cur->str_i++);
        }
    }
    free(cur);
    cur = NULL;
    return rslt;
}
