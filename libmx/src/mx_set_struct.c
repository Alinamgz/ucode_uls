#include "libmx.h"

t_for_replsub *mx_set_struct(const char *str,
                            const char *sub,
                            const char *repl) {
    int delta_len = 0;
    t_for_replsub *rslt = (t_for_replsub*)malloc(sizeof(t_for_replsub));
    
    rslt->rslt_i = 0;
    rslt->str_i = 0;

    rslt->sub_pnt = mx_strstr((str + rslt->str_i), sub);

    rslt->sub_len = mx_strlen(sub);
    rslt->repl_len = mx_strlen(repl);

    delta_len = (rslt->sub_len - rslt->repl_len) * mx_count_substr(str, sub);
    rslt->rslt_len = mx_strlen(str) - delta_len;

    return rslt;
}
